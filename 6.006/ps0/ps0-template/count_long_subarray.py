def count_long_subarray(A):
    '''
    Input:  A     | Python Tuple of positive integers
    Output: count | number of longest increasing subarrays of A
    '''
    count = 1
    length = 1
    current = 1
    for i in range(1, len(A)):
        if A[i-1] < A[i]:
            current += 1
        else:
            current = 1
            
        if current == length:
            count += 1
        elif current > length:
            length = current
            count = 1
    return count
