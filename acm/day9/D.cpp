#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

map<char, vector<string>> startwith;
map<string, bool> checked;

bool check(char checkc){
    if(startwith[checkc].size() == 0){return false;}
    if(checkc == 'm'){ return true; }
    for(int i = 0; i < startwith[checkc].size(); i++){
        string ss = startwith[checkc][i];
        if(checked[ss]){ continue;}
        checked[ss] = true;
        char tail = ss[ss.length()-1];
        if(check(tail)){
            return true;
        }
    }
    return false;
}

int main() {
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        string s;
        ss >> s;
        if(s[0] == '0' && s.length() == 1){
            if(startwith['b'].size() == 0 || startwith['m'].size() == 0){
                cout << "No." << endl;
            } else if (check('b')){
                cout << "Yes." << endl;
            } else {
                cout << "No." << endl;
            }
            startwith.clear();
            checked.clear();
            continue;
        } else {
            startwith[s[0]].push_back(s);
            checked[s] = false;
        }
    }
    return 0;
}
