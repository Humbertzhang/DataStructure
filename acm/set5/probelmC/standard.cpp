
#include <stdio.h>
#include <memory.h>

#define DIRECTSIZE 8

struct direct {
    int drow;
    int dcol;
} direct[DIRECTSIZE] =
    {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

#define MAXN 100

char grid[MAXN+2][MAXN+2];

void dfs(int row, int col)
{
    int i;

    for(i=0; i<DIRECTSIZE; i++) {
        int nextrow = row + direct[i].drow;
        int nextcol = col + direct[i].dcol;

        if(grid[nextrow][nextcol] == '@') {
            grid[nextrow][nextcol] = '*';

            dfs(nextrow, nextcol);
        }
    }
}

int main(void)
{
    int m, n, count, i, j;

    while(scanf("%d%d", &m, &n) != EOF) {
        // 判定结束条件
        if(m == 0 && n == 0)
            break;

        // 清零：边界清零
        memset(grid, 0, sizeof(grid));

        // 读入数据
        for(i=1; i<=m; i++)
            scanf("%s", grid[i]+1);

        // 计数清零
        count = 0;

        // 深度优先搜索
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++)
                if(grid[i][j] == '@') {
                    count++;
                    grid[i][j] = '*';
                    dfs(i, j);
                }

        // 输出结果
        printf("%d\n", count);
    }

    return 0;
}
