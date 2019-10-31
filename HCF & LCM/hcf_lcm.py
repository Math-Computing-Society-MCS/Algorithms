# Python program to find the H.C.F of two input number
# define a function for HCF
def HCF(x, y):
# choose the smaller number
    if x > y:
        smaller = y
    else:
        smaller = x
    for i in range(1, smaller+1):
        if((x % i == 0) and (y % i == 0)):
            hcf = i
            
    return hcf



# Python Program to find the L.C.M. of two input number
# define a function for LCM
def LCM(x, y):
   # choose the greater number
   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

# take input from the user and display result
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))
print("The H.C.F. of", num1,"and", num2,"is", HCF(num1, num2))
print("The L.C.M. of", num1,"and", num2,"is", LCM(num1, num2))