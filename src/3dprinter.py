j = 0
p = 1
nbStatue = 0
while nbStatue < 1 :
    nbStatue = int(input())
if (nbStatue == 1) :
    print(1)
else :
    while p < (nbStatue/2) :
        p = p*2
        j += 1
    print(j + 2)