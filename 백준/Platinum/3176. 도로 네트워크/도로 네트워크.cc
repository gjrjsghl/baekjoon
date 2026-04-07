#include <bits/stdc++.h>

int n;
std::vector<std::pair<int,int>> edge[100001];
int parent[100001][21];
int path[2][100001][21]; //0에 max, 1에 min 저장
int depth[100001];

void find_2kparent() {
    for(int k = 1;k<=20;k++) {
        for(int x = 1;x<=n;x++) {
            int t = parent[x][k-1];
            if(t != 0) {
                parent[x][k] = parent[t][k-1];
                path[0][x][k] = std::max(path[0][x][k-1],path[0][t][k-1]);
                path[1][x][k] = std::min(path[1][x][k-1],path[1][t][k-1]);
            } 
        }
    }
}

void find_parent() {
    std::queue<std::pair<int,int>> q;

    q.push({1,0});

    while(!q.empty()) {
        int pos = q.front().first;
        int par = q.front().second;
        q.pop();

        for(std::pair<int,int> next : edge[pos]) {
            if(next.first == par) continue; 
            path[0][next.first][0] = path[1][next.first][0] = next.second;
            parent[next.first][0] = pos;
            depth[next.first] = depth[pos]+1;

            q.push({next.first,pos});
        }
    }

    find_2kparent();
}


void lca(int a, int b) {
    int max = -1000000000;
    int min = 1000000000;

    if(depth[a] < depth[b]) std::swap(a,b);

    for(int k = 20;k>=0;k--) {
        if((depth[a]-depth[b]) >= (1<<k)) {

            max = std::max(max,path[0][a][k]);
            min = std::min(min,path[1][a][k]);
            
            a = parent[a][k];
        }
    }

    if(a == b) {
    printf("%d %d\n",min,max);
        return;
    }


    for(int k = 20;k>=0;k--) {
        if(parent[a][k] != parent[b][k]) {

            max = std::max(max,path[0][a][k]);
            min = std::min(min,path[1][a][k]);
            max = std::max(max,path[0][b][k]);
            min = std::min(min,path[1][b][k]);

            a = parent[a][k];
            b = parent[b][k];

        }
    }


    max = std::max(max,path[0][a][0]);
    min = std::min(min,path[1][a][0]);
    max = std::max(max,path[0][b][0]);
    min = std::min(min,path[1][b][0]);

    printf("%d %d\n",min,max);
}

int main() {
    scanf("%d",&n);

    for(int i = 0;i<n-1;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    find_parent();
    int k;
    scanf("%d",&k);

    for(int i = 0;i<k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);

        lca(a,b);
    }
    return 0;
}