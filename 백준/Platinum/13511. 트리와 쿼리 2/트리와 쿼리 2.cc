#include <bits/stdc++.h>

using namespace std;


int n;
vector<pair<int,int>> edge[100001];
int parent[100001][21]; //parent[x][k] x노드의 2^k번째 부모
int depth[100001];
long long int dist[100001];


void find_2kParent() { //2^k번째 부모를 기록하는 함수
    for(int k = 1;k<=20;k++) { 
        for(int x = 1;x<=n;x++) {
            int t = parent[x][k-1]; //x노드의 2^(k-1)번째 부모
            if(t != 0) parent[x][k] = parent[t][k-1]; //t가 기록되어있다면 기록
        }
    }
}

void find_parent() { //자기 바로 위의 부모와 깊이를 기록하는 함수 (bfs)
    queue<pair<int,int>> q; //{노드,부모}
    q.push({1,0});

    while(!q.empty()) {
        int pos = q.front().first;
        int p = q.front().second;
        q.pop();


        for(pair<int,int> node : edge[pos]) {
            int next = node.first;
            int cost = node.second;

            if(next == p) continue;
            dist[next] = dist[pos]+cost;
            depth[next] = depth[pos]+1;
            parent[next][0] = pos;

            q.push({next,pos});
        }
    }

    find_2kParent(); //기록 끝났으면 2^k부모도 기록
}


int lca(int a, int b) { //최소공통조상 구하는 함수
    if(depth[a] < depth[b]) swap(a,b); //항상 a가 더 깊은걸로

    for(int k = 20;k>=0;k--) {
        if(depth[a] - depth[b] >= (1<<k)) a = parent[a][k]; //깊이 맞춰주기
    }

    if(a == b) return a; //똑같으면 그게 최소공통조상

    for(int k = 20;k>=0;k--) {
        if(parent[a][k] != parent[b][k]) { //위 조상이 같으면 넘기고 다르면 이동 (같기 직전을 구해야함)
            a = parent[a][k];
            b = parent[b][k];
        }
    }

    return parent[a][0]; //같기 직전을 구했으니 바로 위 값이 답
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

    int m;
    scanf("%d",&m);
    while(m--) {
        int f;
        scanf("%d",&f);
        if(f == 1) {
            int a,b;
            scanf("%d %d",&a,&b);

            int anc = lca(a,b);
            printf("%lld\n",dist[a]+dist[b]-2*dist[anc]);
        }
        else {
            int a,b,k;
            scanf("%d %d %d",&a,&b,&k);

            int anc = lca(a,b);
            k -= 1;
            if(depth[a]-depth[anc] < k) {
                
                k = depth[a]+depth[b]-2*depth[anc] - k;
                swap(a,b);
            }

            for(int z = 20;z>=0;z--) {
                if(k  >= (1<<z)) {
                    a = parent[a][z];
                    k -= (1<<z);
                } 
            }

            printf("%d\n",a);
        }

    }

    return 0;
}
