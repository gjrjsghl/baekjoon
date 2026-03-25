#include <bits/stdc++.h>

using namespace std;

vector<int> after[32005];

int main() {

    int n,m;
    scanf("%d %d",&n,&m);
    priority_queue<int, vector<int>,greater<int>> p;
    vector<int> prior(n+1,0);
    for(int i = 0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        after[a].push_back(b);
        prior[b] += 1;
    }

    for(int i = 1;i<=n;i++) {
        if(prior[i] == 0) p.push(i);
    }

    while(!p.empty()) {
        int q = p.top();
        p.pop();

        printf("%d ",q);

        for(int i = 0;i<after[q].size();i++) {
            int a = after[q][i];
            prior[a] -= 1;

            if(prior[a] == 0) p.push(a);
        }
    }

    return 0;
}
