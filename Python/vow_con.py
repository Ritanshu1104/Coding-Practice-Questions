def replace_vowels(s):
    vowels = "aeiouAEIOU"
    result = ""
    for ch in s:
        if ch in vowels:
            result += "#"
        else:
            result += ch
    return result

def replace_consonants(s):
    vowels = "aeiouAEIOU"
    result = ""
    for ch in s:
        if ch.isalpha() and ch not in vowels:
            result += "%"
        else:
            result += ch
    return result

s1 = input()
s2 = input()
s3 = input()

s1 = replace_vowels(s1)
s2 = replace_consonants(s2)
s3 = s3.upper()

print(s1 + s2 + s3)