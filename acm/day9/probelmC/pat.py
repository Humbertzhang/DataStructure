import os
def run():
    os.system("./my.out < testdata > my.out.data")
    os.system("./standard.out < testdata > standard.out.data")

def check():
    my = open("my.out.data")
    right = open("standard.out.data")
    log = open("log.txt", "w")
    log = open('log.txt', 'w')
    log.write('-----------All Error-----------\n')
    for (i, (a, b)) in enumerate(zip(my, right)):
        if a != b:
            log.write('line ' + str(i+1) + '\n')
            log.write('---MY:' + a)
            log.write('---AC:' + b)

if __name__ == '__main__':
    run()
    check()
