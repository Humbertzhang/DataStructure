#include <iostream>
#include <utility>
#include <vector>

using namespace std;
int maze[5][5];
vector< pair<int, int> > path;

//right down
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void display()
{
    for(int i = 0; i < path.size(); i++){
        cout << "(" << path[i].first << ", " << path[i].second << ")" << endl;
    }
}

void solve(int x, int y)
{
    pair<int, int> p(x, y);
    path.push_back(p);
    if(x == 4 && y == 4){
        display();
        return;
    }

    for(int i = 0; i < 2; i++){
        int xn = x + dx[i];
        int yn = y + dy[i];
        if(xn <= 4 && y <= 4 && maze[xn][yn] != 1){
            solve(xn, yn);
            path.pop_back();
        }
    }

}

int main() {
    // i 行 j 列
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> maze[i][j];
        }
    }
    solve(0, 0);

    return 0;
}
