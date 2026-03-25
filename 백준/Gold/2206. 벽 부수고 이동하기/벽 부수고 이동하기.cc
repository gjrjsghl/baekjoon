#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[1005][1005][3];
int xy[1005][1005];

int preX[] = {-1,1,0,0};
int preY[] = {0,0,-1,1};

int main() {
    scanf("%d %d",&n,&m);

    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            scanf("%1d",&xy[i][j]);
        }
    }

    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},0});
    v[1][1][0] = 1;
    v[1][1][1] = 1;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++) {
            int curx = x+preX[i];
            int cury = y+preY[i];

            if(curx <= 0 || cury <= 0 || curx > n || cury > m) continue;
            if(wall == 0) {
                if(xy[curx][cury] == 1) {
                    if(v[curx][cury][1] != 0) continue;
                    v[curx][cury][1] = v[x][y][0]+1;
                    q.push({{curx,cury},1});
                    continue;
                }
                if(v[curx][cury][0] != 0) continue;

                v[curx][cury][0] = v[x][y][0]+1;
                q.push({{curx,cury},0});
            }
            if(wall == 1) {
                if(v[curx][cury][1] != 0) continue;
                if(xy[curx][cury] == 1) continue;

                v[curx][cury][1] = v[x][y][1]+1;
                q.push({{curx,cury},1});
            }
        }
    }

    int a = v[n][m][0], b = v[n][m][1];
    if(a == 0) {
        if(b == 0) {
            printf("-1");
            return 0;
        }
        printf("%d",b);
        return 0;
    }
    if(b == 0) {
        printf("%d",a);
        return 0;
    }
    printf("%d",min(a,b));
    return 0;
}