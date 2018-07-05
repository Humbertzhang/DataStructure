n = int(input())
strs = []
i = 0
while i < n:
    s = input()
    strs.append(s)
    i += 1
strs.sort(key = len)
i = 0
status = 1
while i < n:
    if i != n-1:
        if strs[i] not in strs[i+1]:
            print("NO")
            status = 0
            break
    i = i + 1
if status == 1:
    print("YES")
    for s in strs:
        print(s)
