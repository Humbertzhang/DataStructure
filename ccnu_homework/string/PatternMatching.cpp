#include <iostream>
#include <string.h>

using namespace std;

int Index_BF(char * a, char *b, int pos);
int Index_KMP(char * a, char * b, int pos);
int * generateTable(char * str, int strlen, int * table );

//B 为短字符串，A 为待被匹配字符串.

int main()
{
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    char b[] = "rst";
    cout << "被搜索字符串:" << a  <<endl;
    cout << "检索字符串:" << b <<endl;
    int pos1 = Index_BF(a, b, 0);
    cout << "Position by BF:" << pos1 << endl;
    int pos2 = Index_KMP(a, b, 0);
    cout << "Position by KMP:" << pos2 << endl;
    return 0;
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
    int blen = strlen(b);
    int table[blen] = {0};
    generateTable(b, blen, table);
    int alen = strlen(a);

    int i = 0, j = 0;   //i is index for a, j is index for b
    while(i < alen) {
        if(a[i] == b[j]) {
            i+=1;
            j+=1;
        }
        if(j == blen) {
            return i-j;
        }
        else if(i < alen && a[i] != b[j]) {
            if(j != 0) {
                j = table[j-1];
            } else {
                i = i + 1;
            }
        }
    }
    return -1;
}


int * generateTable(char * str, int slen, int * table )
{
    int prelen = 0;     //上一次前缀后缀的共同长度
    table[0] = 0;       //table[0] 应为0
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