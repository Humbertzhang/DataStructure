import random

i = 0; j = 0; k = 0;
while i < 100:
    a = random.randint(1, 100)
    b = random.randint(1, 100)
    n = random.randint(2, a+b)
    print(str(n) + " "+ str(a) + " " + str(b))
    i+=1
