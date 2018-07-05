def main():
    n = input()
    lenn = len(n)
    if len(n) <= 1:
        print(-1)
        return
    if '2' in n and '5' in n:
        if n[lenn - 2] is not '2':
            n2 = n[::-1]
            index2 = n2.find('2')
        

if __name__ == '__main__':
    main()
