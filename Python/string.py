a= "My name is Ritanshu Mahajan\nand I am a good boy" #Escape Sequence characters -- new line \n
b= "My name is Ritanshu Mahajan\tand I am a good \\boy" #Escape Sequence characters -- tab \t --back slash \\
c= "My name is \'Ritanshu Mahajan\' and I am a \"good boy\""  #Escape Sequence characters -- double,single Quote \"\"  \'\'

print(a)
print(b)
print(c)


name="Ritanshu"
date="22-02-26"

letter=f'''Dear {name} 
You are Selected! 
{date}'''
print(letter)
