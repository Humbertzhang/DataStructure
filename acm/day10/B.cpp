#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100005];
int step[100005];
queue<int> q;


int bfs(int n, int k)
{
    q.push(n);
    step[n] = 0;
    visited[n] = 1;
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        int stepnow = step[pos];
        /*广度优先 入队*/

        for(int i = 0; i < 3; i++){
            int np = 0;
            if(i == 0){
                np = pos-1;
            } else if(i == 1){
                np = pos+1;
            } else {
                np = pos * 2;
            }
            if(np < 0 || np > 100000){
                continue;
            }
            if(!visited[np]){
                q.push(np);
                visited[np] = 1;
                step[np] = stepnow + 1;
            }
            if(np == k){return step[np];}
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < max(n, k); i++){
        visited[i] = 0;
        step[i] = 0;
    }

    if(n > k){
        cout << n-k << endl;
    } else {
        int result = bfs(n, k);
        cout << result << endl;
    }
    return 0;
}
