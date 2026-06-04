a = int(input("Enter your Age:"))

if(a>=18 ):
    print("You are Eligible")
elif(a<=-1):
    print("This age is Invalid")
else:
   print ("You are below Age")



b = int(input("Enter A Number:"))
if(b%2==0):
    print("It is even number")


com1 = "Click This"
com2 = "buy now"

msg = input("Enter Your Comment:")

if(com1 in msg or com2 in msg):
    print("This is Spam Comment")
else:
    print("Not a Spam Comment")