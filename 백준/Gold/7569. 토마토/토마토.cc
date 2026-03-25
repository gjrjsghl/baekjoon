#include <bits/stdc++.h>

using namespace std;

int xy[101][101][101];
int v[101][101][101];

int preX[] = {0,0,-1,1,0,0};
int preY[] = {0,0,0,0,-1,1};
int preZ[] = {-1,1,0,0,0,0};

int main() {
    int n,m,h;
    scanf("%d %d %d",&n,&m,&h);
    queue<pair<pair<int,int>,int>> p;
    for(int z = 0;z<h;z++) {
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                scanf("%d",&xy[i][j][z]);
                v[i][j][z] = -1;
                if(xy[i][j][z] == 1) {
                    p.push({{i,j},z});
                    v[i][j][z] = 0;
                }
                if(xy[i][j][z] == -1) {
                    v[i][j][z] = -2;
                }
            }
        }

    }


    while(!p.empty()) {
        int x = p.front().first.first;
        int y = p.front().first.second;
        int z = p.front().second;
        

        p.pop();

        for(int i = 0;i<6;i++) {
            int curx = x+preX[i], cury = y+preY[i], curz = z+preZ[i];
            if(curx < 0 || cury < 0 || curx >= m || cury >= n || curz < 0 || curz >= h) continue;
            if(v[curx][cury][curz] != -1) continue;
            if(xy[curx][cury][curz] == -1) continue;

            v[curx][cury][curz] = v[x][y][z]+1;
            p.push({{curx,cury},curz});
        }
    }

    // printf("\n\n");
    // for(int z = 0;z<h;z++) {
    //     for(int i = 0;i<m;i++) {
    //         for(int j = 0;j<n;j++) {
    //             printf("%d ",v[i][j][z]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n\n");
    // }


    int k = -1;
    for(int z = 0;z<h;z++) {
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                k = max(k,v[i][j][z]);
                if(v[i][j][z] == -1) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }


    printf("%d",k);

    return 0;
}