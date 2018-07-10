import sys;
import random;
import os;
    os.system("my.out");
    os.system("standard.out");
    f1=open("STD.out","r");
    f2=open("CHX.out","r");
    f3=open("result.txt","w");
    cnt=1;tot=0;ans=True;
    while True:
        a1=f1.readline();
        if not a1:break;
        a2=f2.readline();
        if(a1!=a2):
            tot=tot+1;
            f3.write("line"+str(cnt)+':'+str(a1)+"?"+str(a2)+"\n");
            ans=False;
        cnt=cnt+1;
    if ans:
        f3.write("All Good!");
        print("All Good!");
    else:
        print("Not Good!There're "+str(tot)+" Wrongs!You Must Check Your Program!");
        f1.close();
        f2.close();
        f3.close();
        os.system("pause");
    f1.close();
    f2.close();
    f3.close();
