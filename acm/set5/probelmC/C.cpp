#include <iostream>

using namespace std;

char omap[105][105];
bool visted[105][105];
int count = 0;
int m, n;

//上右下左 左上 右上 左下 右下
int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[8] = {-1, 0, 1, 0, -1, -1, 1, 1};

void occupyoil(int x0, int y0);
void dfs(int x0, int y0);

int main() {
    while(true){
        cin >> m >> n;
        if(m == 0){ break;}
        if(n == 0){
            cout << 0 << endl;
            continue;
        }
        count = 0;
        for(int i = 0; i < 105; i++){
            for(int j = 0; j < 105; j++){
                omap[i][j] = 0;
                visted[i][j] = 0;
            }
        }

        for(int i = 1; i <= m; i++){
            string s;
            cin >> s;
            //cout << "s:" << s << endl;
            for(int j = 1; j <= n; j++){
                omap[i][j] = s[j-1];
            }
        }
        //dfs(1, 1);
        for(int i = 1; i <= m; i++ ){
            for(int j = 1; j <= n; j++){
                if(visted[i][j] == 0){
                    dfs(i, j);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}


void occupyoil(int x0, int y0){
    if(visted[x0][y0] == 1){ return;}
    visted[x0][y0] = 1;
    for(int i = 0; i < 8; i++){
        int x = x0 + dx[i];
        int y = y0 + dy[i];
        if(x < 0 || x > m || y < 0 || y > n){
            continue;
        }
        if(omap[x][y] == '@' && visted[x][y] == 0){
            occupyoil(x, y);
        } else {
            continue;
        }
    }
}

void dfs(int x0, int y0){
    if(visted[x0][y0] == 1){ return;}
    if(omap[x0][y0] == '@'){
        occupyoil(x0, y0);
        count += 1;
    }
    visted[x0][y0] = 1;

    for(int i = 0; i < 8; i++){
        int x = x0 + dx[i];
        int y = y0 + dy[i];
        if(x < 0 || x > m || y < 0 || y > n){
            continue;
        }
        if(omap[x][y] == '@' && visted[x][y] == 0){
            occupyoil(x, y);
            count += 1;
        } else if(visted[x][y] == 0){
            dfs(x, y);
        }
    }
}


