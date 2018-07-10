import random
i = 0
while i < 100:
    m = random.randint(1, 10)
    n = random.randint(1, 10)
    j = 0; k = 0;
    print(str(m) + " " + str(n))
    s = ""
    while j < m:
        k = 0
        while k < n:
            num = random.randint(1, 101)
            if num <= 50:
                s = s + "*"
            else:
                s = s + "@"
            k += 1
        j += 1
        s = s + "\n"
    print(s)
    i += 1
print("0 0")
