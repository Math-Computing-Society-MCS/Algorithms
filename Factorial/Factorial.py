#initializing var
user_input = 's'
factorial = 1

#looping until the user enters a valid number
while not user_input.isdigit():
  user_input = input ("Enter a number ")
  try:
    #storing user input in variable val
    val = int(user_input)
    #checking is number is less then 0 becasue factorial for negative numbers does not exit
    if val < 0:
        print("Sorry, factorial does not exist for negative numbers")
    #checking is val is 0
    elif val == 0:
        print("The factorial of 0 is 1")
    #calculating the factorial of the val entered
    else:
        for i in range(1,val + 1):
            factorial = factorial*i
        print("The factorial of",val,"is",factorial)
    #throwing exception for incorrect number enter
  except ValueError:
    print("That's not a number! Please enter a positive number!")
