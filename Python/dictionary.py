a = {
    "Key":"Value",
    "Yash":"Code",
    "Marks":"100",
    "list":[1,2,3,4]
    }

print(a,type(a))



marks = {"Ram":90,
         "Sham":85,
         "Yash":95
         }

print(type(marks))

print(marks.items())
print(marks.keys())
print(marks.values())
print(marks.update({"Ram":99, "Geet":90}))
print(marks.get("Yash"))
marks.pop("Geet")
print(marks)

        