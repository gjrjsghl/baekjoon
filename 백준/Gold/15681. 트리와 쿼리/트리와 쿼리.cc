#include <bits/stdc++.h>

using namespace std;


vector<int> v[100001];
int cnt[100001];
int check[100001];

int dfs(int p) {
    if(check[p] !=0) return 0;
    check[p] = 1;
    for(int i = 0;i<v[p].size();i++) {
        //printf("%d ",v[p][i]);
        cnt[p] += dfs(v[p][i]);
    }
    //printf("\n");

    return cnt[p]+=1;
}

int main() {

    int n,r,u;

    scanf("%d %d %d",&n,&r,&u);

    for(int i = 0;i<n-1;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(r);

    while(u--) {
        int k;
        scanf("%d",&k);

        printf("%d\n",cnt[k]);
    }

    return 0;
}
