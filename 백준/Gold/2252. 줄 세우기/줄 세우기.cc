#include <bits/stdc++.h>

using namespace std;

vector<int> stu[32005];

int main() {

    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> prior(n+1,0);
    for(int i = 0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        stu[a].push_back(b);
        prior[b] += 1;
    }
    queue<int> line;
    for(int i = 1;i<=n;i++) {
        if(prior[i] == 0) {
            line.push(i);
        }
    }

    while(!line.empty()) {
        int s = line.front();
        line.pop();
        printf("%d ",s);

        for(int i = 0;i<stu[s].size();i++) {
            prior[stu[s][i]] -= 1;

            if(prior[stu[s][i]] == 0) {
                line.push(stu[s][i]);
            }
        }
    }

    return 0;
}
