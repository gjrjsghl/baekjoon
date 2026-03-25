#include <bits/stdc++.h>

using namespace std;

int m,n;
int k;

int xy[51][51];

void dfs(int x, int y) {
    if(x < 0 || y < 0 || x >= m || y >= n) return;
    if(xy[x][y] == 0) return;

    xy[x][y] = 0;

    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d",&m,&n,&k);

        while(k--) {
            int a,b;
            scanf("%d %d",&a,&b);
            xy[a][b] = 1;
        }

        int c = 0;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(xy[i][j] == 1) {
                    dfs(i,j);
                    c += 1;
                }
            }
        }

        printf("%d\n",c);
    }


    return 0;
}