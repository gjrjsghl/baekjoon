#include <bits/stdc++.h>

using namespace std;

int n,k;
int build[1005];
vector<int> prior[1005];
int v[1005];

int dfs(int num) {
    if(v[num] != -1) return v[num];
    if(prior[num].size() == 0) {
        return build[num];
    }
    int t = 0;
    for(int i = 0;i<prior[num].size();i++) {
        t = max(t,dfs(prior[num][i]));
    }
    return v[num] = t + build[num];
}

int main() {

    int t;
    scanf("%d",&t);
    while(t--) {

        scanf("%d %d",&n,&k);
        
        for(int i = 0;i<=n;i++) {
            v[i] = -1;
            prior[i].clear();
        }

        for(int i = 1;i<=n;i++) {
            scanf("%d",&build[i]);
        }
        for(int i = 0;i<k;i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            prior[b].push_back(a);
        }

        int target;
        scanf("%d",&target);
        printf("%d\n",dfs(target));

    }


    return 0;
}
