#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;


map<char, int> ma;
string str[10] = {"0", "1", "2", "3", "4", "5", "6",
                  "7", "8", "9"};

int klen(string k){
    if(k.length() < 11){
        return k.length()-1;
    }
    if(k.length() < 102){
        return k.length()-2;
    }
    if(k.length() < 1003){
        return k.length()-3;
    }
    if(k.length() < 10004){
        return k.length()-4;
    }
    if(k.length() < 100005){
        return k.length()-5;
    }
    if(k.length() < 1000006){
        return k.length()-6;
    }
}

int main()
{
    string s, subs;
    cin >> s >> subs;
    int k = klen(s);
    string bits = to_string(k);
    //去掉位数信息

    for(int i = 0; i < s.length(); i++){
        ma[s[i]] += 1;
    }
    for(int i = 0; i < bits.length(); i++){
        ma[bits[i]] -= 1;
    }
    for(int j = 0; j < subs.length(); j++){
        ma[subs[j]] -= 1;
    }
    string result = "";
    if(subs[0] == '0'){
        /*min bit*/
        for(int i = 1; i <= 9; i++){
            if(ma[i+'0'] != 0){
                string splus = to_string(i);
                result = result + splus;
                ma[i+'0'] -= 1;
                break;
            }
        }
        while(ma['0'] != 0){
            result = result + str[0];
            ma['0'] -= 1;
        }

        result = result + subs;

        for(int i = 1; i <= 9; i++){
            while(ma[i+'0'] != 0){
                result = result + str[i];
                ma[i+'0'] -= 1;
            }
        }
    }
    else if(subs[0] != '0'){
        for(int i = 1; i <= 9; i++){
            if(ma[i+'0'] != 0){
                string splus = to_string(i);
                result = result + splus;
                ma[i+'0'] -= 1;
                break;
            }
        }
        while(ma['0'] != 0){
            result = result + str[0];
            ma['0'] -= 1;
        }
        for(int i = 1; i <= 9; i++){
            while(ma[i+'0'] != 0){
                result = result + str[i];
                ma[i+'0'] -= 1;
            }
        }
        int flag = 0;
        for(int i = 0; i < result.length()-2; i++){
            if(result[i]-'0' < subs[0]-'0' && result[i+1]-'0' >= subs[0] - '0'){
                result = result.insert(i+1, subs);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            result = result + subs;
        }
    }
    cout << result << endl;

    return 0;
}

