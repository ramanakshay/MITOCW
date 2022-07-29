# 6.0001/6.00 Problem Set 5 - RSS Feed Filter
# Name:
# Collaborators:
# Time:

import feedparser
import string
import time
import threading
from project_util import translate_html
from mtTkinter import *
from datetime import datetime
import pytz


#-----------------------------------------------------------------------

#======================
# Code for retrieving and parsing
# Google and Yahoo News feeds
# Do not change this code
#======================

def process(url):
    """
    Fetches news items from the rss url and parses them.
    Returns a list of NewsStory-s.
    """
    feed = feedparser.parse(url)
    entries = feed.entries
    ret = []
    for entry in entries:
        guid = entry.guid
        title = translate_html(entry.title)
        link = entry.link
        description = translate_html(entry.description)
        pubdate = translate_html(entry.published)
        print(pubdate)
        try:
            pubdate = datetime.strptime(pubdate, "%a, %d %b %Y %H:%M:%S %Z")
            pubdate.replace(tzinfo=pytz.timezone("GMT"))
          #  pubdate = pubdate.astimezone(pytz.timezone('EST'))
          #  pubdate.replace(tzinfo=None)
        except ValueError:
            pubdate = datetime.strptime(pubdate, "%a, %d %b %Y %H:%M:%S %z")

        newsStory = NewsStory(guid, title, description, link, pubdate)
        ret.append(newsStory)
    return ret

#======================
# Data structure design
#======================

# Problem 1

class NewsStory(object):
    def __init__(self,guid, title, description, link, pubdate):
        self.guid = guid
        self.title = title
        self.description = description
        self.link = link
        self.pubdate = pubdate
    def get_guid(self):
        return self.guid
    def get_title(self):
        return self.title
    def get_description(self):
        return self.description
    def get_link(self):
        return self.link
    def get_pubdate(self):
        return self.pubdate
    


#======================
# Triggers
#======================

class Trigger(object):
    def evaluate(self, story):
        """
        Returns True if an alert should be generated
        for the given news item, or False otherwise.
        """
        # DO NOT CHANGE THIS!
        raise NotImplementedError

# PHRASE TRIGGERS

# Problem 2
class PhraseTrigger(Trigger):
    def __init__(self,phrase):
        self.phrase = phrase.lower()
    def is_phrase_in(self,text):
        check = []
        t = text.lower()
        self.phrase = self.phrase.lower()
        for i in t:
            if i in string.punctuation:
               t = t.replace(i,' ')
        words = t.split()
        search_words = self.phrase.split()
        for i in words:
            if i in search_words:
                check.append(i)
                search_words.remove(i)
            elif ' '.join(check)!=self.phrase and check !=[]:
                return False
        if ' '.join(check)==self.phrase:
            return True
        else:
            return False  

# Problem 3
class TitleTrigger(PhraseTrigger):
       def evaluate(self,story):
            """
            Returns True if an alert should be generated
            for the given news item, or False otherwise.
            """
            return self.is_phrase_in(story.get_title())

# Problem 4
        
class DescriptionTrigger(PhraseTrigger):
       def evaluate(self,story):
            """
            Returns True if an alert should be generated
            for the given news item, or False otherwise.
            """
            return self.is_phrase_in(story.get_description())
            
    

# TIME TRIGGERS

# Problem 5
class TimeTrigger(Trigger):
    def __init__(self,timestr):
        self.time = datetime.strptime(timestr,'%d %b %Y %H:%M:%S')

# Problem 6
class BeforeTrigger(TimeTrigger):
    def evaluate(self,story):
        return self.time>story.get_pubdate().replace(tzinfo = self.time.tzinfo)
class AfterTrigger(TimeTrigger):
    def evaluate(self,story):
        return self.time<story.get_pubdate().replace(tzinfo = self.time.tzinfo)

# COMPOSITE TRIGGERS

# Problem 7
class NotTrigger(Trigger):
    def __init__(self,triggerr):
        self.trig = triggerr
    def evaluate(self,story):
        return not self.trig.evaluate(story)

# Problem 8
class AndTrigger(Trigger):
    def __init__(self,trigger1,trigger2):
        self.trig1 = trigger1
        self.trig2 = trigger2
    def evaluate(self,story):
        return self.trig1.evaluate(story) and self.trig2.evaluate(story)


# Problem 9
class OrTrigger(Trigger):
    def __init__(self,trigger1,trigger2):
        self.trig1 = trigger1
        self.trig2 = trigger2
    def evaluate(self,story):
        return self.trig1.evaluate(story) or self.trig2.evaluate(story)

#======================
# Filtering
#======================

# Problem 10
def filter_stories(stories, triggerlist):
    """
    Takes in a list of NewsStory instances.

    Returns: a list of only the stories for which a trigger in triggerlist fires.
#    """
    filtered = []
    for news in stories:
        for t in triggerlist:
            if t.evaluate(news):
                filtered.append(news)
    return filtered



#======================
# User-Specified Triggers
#======================
# Problem 11
def read_trigger_config(filename):
    """
    filename: the name of a trigger configuration file

    Returns: a list of trigger objects specified by the trigger configuration
        file.
    """
    # We give you the code to read in the file and eliminate blank lines and
    # comments. You don't need to know how it works for now!
    trigger_file = open(filename, 'r')
    trigger_dict = {}
    lines = []
    trigger_list = []
    for line in trigger_file:
        line = line.rstrip()
        if not (len(line) == 0 or line.startswith('//')):
            lines.append(line)

    for line in lines:
        l = line.split(',')
        if l[0]=='ADD':
            for i in l[1:]:
                trigger_list.append(trigger_dict[i])
        else:
            if l[1]=='DESCRIPTION':
                trigger_dict[l[0]]=DescriptionTrigger(l[2])
            elif l[1]=='TITLE':
                trigger_dict[l[0]]=TitleTrigger(l[2])    
            elif l[1]=='BEFORE':
                trigger_dict[l[0]]=BeforeTrigger(l[2]) 
            elif l[1]=='AFTER':
                trigger_dict[l[0]]=AfterTrigger(l[2]) 
            elif l[1]=='NOT':
                trigger_dict[l[0]]=NotTrigger(trigger_dict[l[2]]) 
            elif l[1]=='AND':
                trigger_dict[l[0]]=AndTrigger(trigger_dict[l[2]],trigger_dict[l[3]]) 
            elif l[1]=='OR':
                trigger_dict[l[0]]=AndTrigger(trigger_dict[l[2]],trigger_dict[l[3]])    
    return trigger_list

SLEEPTIME = 120 #seconds -- how often we poll
def main_thread(master):
    # A sample trigger list - you might need to change the phrases to correspond
    # to what is currently in the news
    try:
#        t1 = TitleTrigger("election")
#        t2 = DescriptionTrigger("Trump")
#        t3 = DescriptionTrigger("Clinton")
#        t4 = AndTrigger(t2, t3)
#        triggerlist = [t1, t4]

        # Problem 11
        # TODO: After implementing read_trigger_config, uncomment this line 
        triggerlist = read_trigger_config('triggers.txt')
        
        # HELPER CODE - you don't need to understand this!
        # Draws the popup window that displays the filtered stories
        # Retrieves and filters the stories from the RSS feeds
        frame = Frame(master)
        frame.pack(side=BOTTOM)
        scrollbar = Scrollbar(master)
        scrollbar.pack(side=RIGHT,fill=Y)

        t = "Google & Yahoo Top News"
        title = StringVar()
        title.set(t)
        ttl = Label(master, textvariable=title, font=("Helvetica", 18))
        ttl.pack(side=TOP)
        cont = Text(master, font=("Helvetica",14), yscrollcommand=scrollbar.set)
        cont.pack(side=BOTTOM)
        cont.tag_config("title", justify='center')
        button = Button(frame, text="Exit", command=root.destroy)
        button.pack(side=BOTTOM)
        guidShown = []
        def get_cont(newstory):
            if newstory.get_guid() not in guidShown:
                cont.insert(END, newstory.get_title()+"\n", "title")
                cont.insert(END, '   '+str(newstory.get_pubdate())+"\n", "date")
                cont.insert(END, "---------------------------------------------------------------\n", "title")
                cont.insert(END, newstory.get_description())
                cont.insert(END, "\n*********************************************************************\n\n", "title")
                guidShown.append(newstory.get_guid())

        while True:

            print("Polling . . .", end=' ')
            # Get stories from Google's Top Stories RSS news feed
            stories = process("http://news.google.com/news?output=rss")

            # Get stories from Yahoo's Top Stories RSS news feed
            stories.extend(process("http://news.yahoo.com/rss/topstories"))

            stories = filter_stories(stories, triggerlist)

            list(map(get_cont, stories))
            scrollbar.config(command=cont.yview)


            print("Sleeping...")
            time.sleep(SLEEPTIME)

    except Exception as e:
        print(e)


if __name__ == '__main__':
    root = Tk()
    root.title("Some RSS parser")
    t = threading.Thread(target=main_thread, args=(root,))
    t.start()
    root.mainloop()

