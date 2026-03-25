#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    scanf("%d %d",&n,&k);

    vector<int> prior(n+1,0);
    vector<int> after[1005];
    for(int i = 0;i<k;i++) {
        int k;
        scanf("%d",&k);
        k-= 1;
        int a;
        scanf("%d",&a);
        while(k--) {
            int b;
            scanf("%d",&b);
            prior[b] += 1;
            after[a].push_back(b);
            a = b;
        }
    }
    queue<int> seq;
    for(int i = 1;i<=n;i++) {
        if(prior[i] == 0) {
            seq.push(i);
        }
    }

    queue<int> ans;

    while(!seq.empty()) {
        int f = seq.front();
        seq.pop();

        ans.push(f);

        for(int i = 0;i<after[f].size();i++) {
            int t = after[f][i];
            prior[t] -= 1;
            if(prior[t] == 0) seq.push(t);
        }
    }

    if(ans.size() < n) {
        printf("0");
        return 0;
    }

    while(!ans.empty()) {
        printf("%d\n",ans.front());
        ans.pop();
    }


    return 0;
}
