#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


char graph[25][25];
bool vis[25][25];

int w, h;
int count = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x0, int y0)
{
	if(vis[x0][y0]){
		return ;
	}
	vis[x0][y0] = 1;
	if(graph[x0][y0] == '.'){
		count += 1;
	}
	for(int i = 0; i < 4; i++){
		int x = x0 + dx[i];
		int y = y0 + dy[i];
		if(x > 0 && x <= h && y > 0 && y <= w && graph[x][y] == '.'){
			dfs(x, y);
		}
	}
	return;
}

int main()
{
	while(true){
		cin >> w >> h;
		if(w == 0 && h == 0){break;}

		for(int i = 0; i < 25; i++){
			for(int j = 0; j < 25; j++){
				vis[i][j] = 0;
				graph[i][j] = 0;
			}
		}

		count = 0;
		int x0, y0;

		// h 行  w 列  i 行  j 列
		for(int i = 1; i <= h; i++){
			char cc;
			scanf("%c", &cc);
			for(int j = 1; j <= w; j++){
				char c;
				scanf("%c", &c);
				graph[i][j] = c;
				if(graph[i][j] == '@'){
					x0 = i;
					y0 = j;
				}
			}
		}
		dfs(x0, y0);
		cout << count + 1<< endl;
	}
	return 0;
}
