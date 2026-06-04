a = set()   #Empty Set , if a={} it will create empty dictionary

s={1,2,3,3,4,5,5,"Yash"}   #In this way a set is created  AND No Duplicate values are counted in Sets
print(s,type(s))

s.add(6)
print(s)



s1={3,1,34,6}
s2={3,8,23,1}
print(s1.union(s2))
print(s1.intersection(s2))


s.union({8,11})
s.intersection({8,11})
print(s)

