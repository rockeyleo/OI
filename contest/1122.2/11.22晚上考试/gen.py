import os
from random import randint
for T in range(1,11) :
    if T <= 3 :
        n=randint(20-5,20)
    elif T <= 6 :
        n=randint(1000-5,1000)
    else :
        n=randint(10**5-5,10**5)
        
    if randint(1,2) == 1 :
        m = 10
    else :
        m = 10**9
    f = open('ball'+str(T)+'.in','w')
    f.write("%d " % n)
    if randint(1,2) == 1 :
        f.write('baiyun\n')
    else :
        f.write('baitu\n')
    for i in range(n) :
        f.write('%d %d\n' % (randint(1,m),randint(1,m)))
    f.close()

    os.system("./ball < ball"+str(T)+".in > ball"+str(T)".out")
