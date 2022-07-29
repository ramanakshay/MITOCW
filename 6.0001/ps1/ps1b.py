# -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 10:58:15 2019

@author: aksha
"""

annual_salary = int(input('Enter your annual salary: '))
portion_saved = float(input('Enter the percent of your salary to be saved, as a decimal: '))
total_cost = int(input('Enter cost your dream home: '))
semi_annual_raise = float(input('Enter the semi-annual raise, as a decimal: '))
current_savings = 0.0
months = 0
while current_savings<=(total_cost*0.25):
    months +=1
    if months%6==1 and months != 1:
        annual_salary += annual_salary*semi_annual_raise
        
    current_savings += annual_salary/12*portion_saved + current_savings*0.04/12
print('Number of months:',months)  