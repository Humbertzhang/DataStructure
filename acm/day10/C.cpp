#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

struct mypair {
    int x;
    int y;
    mypair(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool visited[1000][1000];
int step[1000][1000];
int size, startx, starty, endx, endy;
int result;
//queue<mypair> q;

int bx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int by[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

/*
void clear(){
    while(!q.empty()){
        q.pop();
    }
    for(int i = 0; i < 305; i++){
        for(int j = 0; j < 305; j++){
            visited[i][j] = 0;
            step[i][j] = 0;
        }
    }
    size = 0; result = 0;
    startx = 0; starty = 0; endx = 0; endy = 0;
}
*/

int bfs()
{
    queue<mypair> q;
    mypair m(startx, starty);
    q.push(m);
    visited[startx][starty] = 1;
    step[startx][starty] = 0;
    while(!q.empty()){
        mypair p = q.front();
        q.pop();
        int stepnow = step[p.x][p.y];

        if(p.x == endx && p.y == endy){
            return step[endx][endy];
        }

        for(int i = 0; i < 8; i++){
            mypair next(0, 0);
            next.x = p.x + bx[i];
            next.y = p.y + by[i];

            if(next.x < 0 || next.y > size-1 || next.y < 0 || next.y > size - 1){
                continue;
            }
            if(!visited[next.x][next.y]){
                q.push(next);
                visited[next.x][next.y] = 1;
                step[next.x][next.y] = stepnow + 1;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--){
        //clear();
        memset(visited, 0, sizeof(visited));
        scanf("%d %d %d %d %d", &size, &startx, &starty, &endx, &endy);
        result = bfs();
        printf("%d\n", result);
    }
    return 0;
}
