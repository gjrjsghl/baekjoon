#include <bits/stdc++.h>

using namespace std;

int memo[10005];

int roma,hangulem;
vector<pair<int,int>> path[100001];

int getmin(int k) {
    if(memo[k] != -1) return memo[k];
    if(k == roma) return memo[k] = 0;

    int t = -1;
    for(int i = 0;i< path[k].size();i++) {
        t = max(t,getmin(path[k][i].first)+path[k][i].second);
    }
    return memo[k] = t;
}

int v[100001];

int countmin() {
    int cnt = 0;
    queue<int> q;
    q.push(hangulem);
    v[hangulem] = 1;

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i = 0;i<path[t].size();i++) {
            pair<int,int> p = path[t][i];
            if(memo[p.first] == -1) continue;
            if(memo[t] == memo[p.first]+p.second) {
                cnt += 1;
                if(v[p.first] == 0) {
                    q.push(p.first);
                }
                v[p.first] = 1;
            }
        }
    }
    return cnt;
}

int main() {

    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 0;i<=n;i++) {
        memo[i] = -1;
    }

    for(int i = 0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        path[b].push_back({a,c});
    }

    scanf("%d %d",&roma,&hangulem);

    printf("%d\n",getmin(hangulem));
    printf("%d",countmin());



    return 0;
}