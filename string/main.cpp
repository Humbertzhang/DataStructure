#include <iostream>
#include <string.h>

using namespace std;

int Index_BF(char * a, char *b, int pos);
int Index_KMP(char * a, char * b, int pos);
int * generateTable(char * str, int strlen, int * table )

//B 为短字符串，A 为待被匹配字符串.

int main()
{
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    char b[] = "rst";

    int pos1 = Index_BF(a, b, 0);
    cout << "Position by bf:" << pos1 << endl;
    int pos2 = 0;
    //cout << "Position by KMP:" << pos2 << endl;
    //return 0;
}

int Index_BF(char * a, char *b, int pos)
{
    int i = pos;
    int j = 0;
    while(a[i+j] != '\0' && b[j] != '\0') {
        if(a[i+j] == b[j]) {
            j++;
        }
        else {
            i++;
            j = 0;
        }
    }
    if(b[j] == '\0')
        return i;
    else
        return -1;
}
int Index_KMP(char * a, char * b, int pos)
{
    int slen = strlen(b);
    int table[slen] = {0};
    generateTable(b, slen, table);
    return 0;
}

int * generateTable(char * str, int slen, int * table )
{
    int prelen = 0;     //length of the previous prefix and suffix.
    table[0] = 0;       //table[0] is 0
    int i = 1;
    while(i < slen) {
        if(str[i] == str[prelen]) {
            prelen ++; //已经匹配的长度加1
            table[i++] = prelen;    //将table在i处进行标记.
        }else{
            if(prelen != 0) {
                prelen = table[prelen-1];   //等于上一次记录下来的prelen长度,即长度没有增加.
            }else {
                table[i++] = 0;
            }
        }
    }
}