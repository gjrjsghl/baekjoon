#include <bits/stdc++.h>

using namespace std;

int n,m;
int xy[301][301];
int sea[301][301];
int v[301][301];

void cntLand(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(v[x][y] != 0) return;

    sea[x][y] == 0;
    v[x][y] = 1;
    
    if(xy[x-1][y] == 0) sea[x][y] += 1;
    else cntLand(x-1,y);

    if(xy[x+1][y] == 0) sea[x][y] += 1;
    else cntLand(x+1,y);

    if(xy[x][y-1] == 0) sea[x][y] += 1;
    else cntLand(x,y-1);

    if(xy[x][y+1] == 0) sea[x][y] += 1;
    else cntLand(x,y+1);
    
}

void timeGoes() {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            xy[i][j] -= sea[i][j];
            if(xy[i][j] < 0) xy[i][j] = 0;

            sea[i][j] = 0;
            v[i][j] = 0;
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            scanf("%d",&xy[i][j]);
        }
    }

    int t = 0;
    int land = 0;
    while(1) {
        
        // printf("\n");
        // for(int i = 0;i<n;i++) {
        //     for(int j = 0;j<m;j++) {
        //         printf("%d ",xy[i][j]);
        //     }
        //     printf("\n");
        // }


        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(xy[i][j] != 0 && v[i][j] == 0) {
                    cntLand(i,j);
                    land += 1;
                }
            }
        }
        //printf("%d\n",land);

        if(land > 1) {
            printf("%d",t);
            return 0;
        }
        if(land == 0) {
            printf("0");
            return 0;
        }
        land = 0;
    

        t += 1;
        timeGoes();
    }

    return 0;
}
