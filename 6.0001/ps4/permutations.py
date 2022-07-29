# Problem Set 4A
# Name: <your name here>
# Collaborators:
# Time Spent: x:xx

def get_permutations(sequence):
    '''
    Enumerate all permutations of a given string

    sequence (string): an arbitrary string to permute. Assume that it is a
    non-empty string.  

    You MUST use recursion for this part. Non-recursive solutions will not be
    accepted.

    Returns: a list of all permutations of sequence

    Example:
    >>> get_permutations('abc')
    ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

    Note: depending on your implementation, you may return the permutations in
    a different order than what is listed here.
    '''
    l = []
    if len(sequence)==1:
        return [sequence]
    else:
        l1 = get_permutations(sequence[1:])
        for i in l1:
            a= i+sequence[0] 
            if a not in l:
                l.append(a)
            for j in range(len(i)):
                a = i[0:j]+sequence[0]+i[j:]
                if a not in l:
                    l.append(a)

        return l
                

if __name__ == '__main__':
#    #EXAMPLE
#    example_input = 'abc'
#    print('Input:', example_input)
#    print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
#    print('Actual Output:', get_permutations(example_input))
    
#    # Put three example test cases here (for your sanity, limit your inputs
#    to be three characters or fewer as you will have n! permutations for a 
#    sequence of length n)
    print(get_permutations('abcd'))
    print(get_permutations('uuss'))
    print(get_permutations('buss'))

