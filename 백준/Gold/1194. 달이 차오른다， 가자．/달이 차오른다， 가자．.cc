#include <bits/stdc++.h>

int preX[4] = {-1,1,0,0};
int preY[4] = {0,0,-1,1};

char map[52][52];
int d[52][52][70];

struct point
{
    std::pair<int,int> pos;
    int key;
};

void getKey(int& key, char num) {
    int k = num-'a';
    if((key & (1<<k)) == 0) key |= (1<<k);

}

bool hasKey(int key, char num) {
    int k = num-'A';
    if((key & (1<<k)) == 0) return false;
    return true;
}


int main() {
    std::queue<point> q;
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 1;i<=n;i++) {
        char a[52];
        scanf("%s",a);
        for(int j = 0;j<m;j++) {
            map[i][j+1] = a[j];
            if(a[j] == '0') {
                q.push(point{{i,j+1},0});
                d[i][j+1][0] = 1;
            }
        }
    }

    while(!q.empty()) {
        std::pair<int,int> pos = q.front().pos;
        int key = q.front().key;
        q.pop();

        for(int i = 0;i<4;i++) {
            int curx = pos.first+preX[i];
            int cury = pos.second+preY[i];
            int curk = key;
            
            if(curx <= 0 or cury <= 0 or curx > n or cury > m) continue;
            if(map[curx][cury] == '#') continue;

            if('a' <= map[curx][cury] and map[curx][cury] <= 'f') getKey(curk,map[curx][cury]);
            if(('A' <= map[curx][cury] and map[curx][cury] <= 'F') and hasKey(curk,map[curx][cury]) == false) continue;

            if(d[curx][cury][curk] != 0) continue;

            d[curx][cury][curk] = d[pos.first][pos.second][key]+1;

            if(map[curx][cury] == '1') {
                printf("%d\n",d[curx][cury][curk]-1);
                return 0;
            }

            q.push(point{{curx,cury},curk});
        }
    }
    printf("-1");
    return 0;
}