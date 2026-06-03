x=input("Enter the name of the user:")
vowels = 'aeiouAEIOU'
count = 0
for char in x:
    if char in vowels:
        count += 1
print("Number of vowels:", count)   