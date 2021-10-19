# we are implementing trapezoidal rule for receiving numerial integration value.
# importing packages
import numpy as np

# taking inputs from user - upper limit, lower limit, function over which integration is to be carried out.
func = input("Enter the function in numpy format: ")
a = int(input("Lower limit : "))
b = int(input("Upper limit : "))

# convert the string input from user into mathematical function
def f(x):
    f = eval(func, {'x':x, 'np':np})
    return f

# implementing trapezoidal rule
n = (b-a)*1000
summ = 0
for i in range (1,n):
    summ += f(a + i*0.001)
integral = 0.0005*(f(a)+ 2*summ + f(b))

# final output
print("integral of ", func, " from ", a, " to ", b, " = ", integral)