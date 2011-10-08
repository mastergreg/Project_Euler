from math import sqrt, pow
def kapa(n, list):
    if (n == 0):
        return 2.
    else:
        return (2 * list[n - 1] + 1) / list[n - 1] 
def paronomasths(i, list):
    max=int(pow(10,250))
    f2=0
    f = 2 * list[i] + 1
    while (i > 1):
        i = i - 1;
        f = f * list[i-1]
        f2=f2 *list[i-1]
        f2=f2 + f/max
        f=f%max
    return len(str(int(f2)))+len(str(int(f)))
def arithmhths(i, list):
    max=int(pow(10,250))
    f2=0
    f = 3 * list[i] + 1
    while (i > 1):
        i -= 1
        f = f * list[i-1]
        f2 = f2 * list[i-1]
        f2= f2 + f/max
        f= f % max
    return len(str(int(f2)))+len(str(int(f)))
def klasma(i, list,j):
    p = paronomasths(i, list)
    a = arithmhths(i, list)
    if (a>p):
        return j+1
    else:
        return j

kapalist = []
j=0
for i in range (0, 997):
    kapalist.append(kapa(i, kapalist))
for i in range (0, 997):
    j=klasma(i, kapalist,j)
print j
