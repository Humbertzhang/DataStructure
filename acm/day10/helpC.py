import random
print(200)
i = 0
while i < 200:
    size = random.randint(200,300)
    print(size)
    starx = random.randint(0, size-1)
    stary = random.randint(0, size-1)
    print(str(starx) + " " + str(stary))
    endx = random.randint(0, size-1)
    endy = random.randint(0, size-1)
    print(str(endx) + " " + str(endy))
    i += 1
