#include <bits/stdc++.h>

using namespace std;

int xy[1001][1001];
int v[1001][1001];

int preX[] = {-1,1,0,0};
int preY[] = {0,0,-1,1};

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    queue<pair<int,int>> p;
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<n;j++) {
            scanf("%d",&xy[i][j]);
            v[i][j] = -1;
            if(xy[i][j] == 1) {
                p.push({i,j});
                v[i][j] = 0;
            }
            if(xy[i][j] == -1) {
                v[i][j] = -2;
            }
        }
    }

    //printf("%d",p.size());

    while(!p.empty()) {
        int x = p.front().first;
        int y = p.front().second;
        

        p.pop();

        for(int i = 0;i<4;i++) {
            int curx = x+preX[i], cury = y+preY[i];
            if(curx < 0 || cury < 0 || curx >= m || cury >= n) continue;
            if(v[curx][cury] != -1) continue;
            if(xy[curx][cury] == -1) continue;

            v[curx][cury] = v[x][y]+1;
            p.push({curx,cury});
        }
    }
    //printf("\n\n");

    // for(int i = 0;i<m;i++) {
    //     for(int j = 0;j<n;j++) {
    //         printf("%d ",v[i][j]);
    //     }
    //     printf("\n");
    // }

    //printf("\n\n");
    int k = -1;
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<n;j++) {
            k = max(k,v[i][j]);
            if(v[i][j] == -1) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d",k);

    return 0;
}