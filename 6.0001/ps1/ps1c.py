# -*- coding: utf-8 -*-
"""
Created on Tue Jul 23 14:39:19 2019

@author: aksha
"""
annual_salary = int(input('Enter your annual salary: '))
annual_salary1 = annual_salary
total_cost = 1000000
semi_annual_raise = 0.07
current_savings = 0.0
low = 0
high = 10000
guess = 5000
numberofsteps = 0
while abs(current_savings-total_cost*0.25)>=100 and guess != 9999 and abs(low-high)>=2:
    current_savings = 0.0
    annual_salary = annual_salary1
    for months in range(1,37):
        if months%6==1 and months != 1:
            annual_salary += annual_salary*semi_annual_raise
        current_savings += annual_salary/12*(guess/10000) + current_savings*0.04/12
    if current_savings<(total_cost*0.25):
        low = guess
    else:
        high = guess
    guess =int((low+high)/2)
    numberofsteps += 1   

if guess==9999:
    print('It is not possible to pay the down payment in 3 years')
elif guess ==0:
    print('The portion size cannot be computed as it is very less(less than 0.0001)')
else:
    print('Best Savings Rate: ',guess/10000)
    print('Steps in bisection search: ',numberofsteps)