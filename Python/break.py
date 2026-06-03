for num in range(1,15):
    if num>1:
        is_prime= True
        for i in range(1, num+1):
            if num%i==0 and i!=1 and i!=num:
                is_prime=False
                break

        if is_prime:
            if num==13:
                break
            print(num)


print("\n")

for num1 in range(1,20):
    if num1>1:
        is_prime= True
        for i in range(1, num1+1):
            if num1%i==0 and i!=1 and i!=num1:
                is_prime=False
                break

        if is_prime:
            if num1==11:
                continue
            print(num1)

print("\n")

for n in range(1,51):
    if n%2==0:
        continue
    print(n)

