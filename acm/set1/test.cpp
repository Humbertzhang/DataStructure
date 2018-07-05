#include <iostream>
#include <map>
using namespace std;
int main() {
	map<char, char> c;
	c['A'] = 'B';
	cout << c['B'] << endl;
	cout << (c['B'] == NULL) << endl;
}
