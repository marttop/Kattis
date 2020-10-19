a = input()
i = 0
c = ''
while i < len(a) :
    if a[i] == a[i].upper() and (a[i] != "-") :
        c += a[i]
    i = i + 1  
print(c)