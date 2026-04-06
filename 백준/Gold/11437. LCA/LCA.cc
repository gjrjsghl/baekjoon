#include <bits/stdc++.h>

using namespace std;


int n;
vector<int> edge[100001];
int parent[100001][21]; //parent[x][k] x노드의 2^k번째 부모
int depth[100001];


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

        parent[pos][0] = p;
        depth[pos] = depth[p]+1;

        for(int next : edge[pos]) {
            if(next == p) continue;
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
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    find_parent();

    int m;
    scanf("%d",&m);
    while(m--) {
        int a,b;
        scanf("%d %d",&a,&b);

        printf("%d\n",lca(a,b));
    }

    return 0;
}
