#include "stack.h"
#include <iostream>
#include <string.h>
#include <stack>
#include <math.h>

using namespace std;

bool isOperator(char a);
int parsenum(Stack * stemp);
int calculate(int num1, int num2, char c);

int main()
{
    Stack stemp;
    InitStack(&stemp);
    stack<int> snum;

    char s[200];
    cout << "后缀表达式格式如12|33-16*#" <<endl;
    cout << "连续数字之间用|分割开来" <<endl;
    cout << "输入你的后缀表达式:";
    cin >> s;
    //算出数值

    for(int i=0; i<strlen(s);) {
        if (s[i] == '#') {
            break;
        }
        else if (!isOperator(s[i])) {
            ClearStack(&stemp);
            while(!isOperator(s[i])){
                Push(&stemp, s[i++]);
            }
            int thenum = parsenum(&stemp);
            snum.push(thenum);
        }

        else if (s[i] == '|') {
            i++;
            continue;
        }

        else if (isOperator(s[i])){
            int num1 = snum.top();
            snum.pop();
            int num2 = snum.top();
            snum.pop();
            int num3 = calculate(num2, num1, s[i]);
            snum.push(num3);
            i++;
        }
    }
    cout << "结果是:"  << snum.top() << endl;
    return 0;
}

bool isOperator(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '|') {
        return true;
    }
    return false;
}

int parsenum(Stack * stemp) {
    int num = 0;
    for (int i = 0; !StackEmpty(*stemp); i++) {
        num += (Pop(stemp)-'0') * pow(10, i);
    }
    return num;
}

int calculate(int num1, int num2, char c) {
    if (c == '+')
        return num1 + num2;
    else if(c == '-')
        return num1 - num2;
    else if (c == '*')
        return num1 * num2;
    else if (c == '/')
        return num1 / num2;
}
