#include <bits/stdc++.h>

using namespace std;

int team[4000005];


int find_head(int k) {
    if(team[k] == k) return k;

    return team[k] = find_head(team[k]);
}


int main() {

    vector<int> v;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    for(int i = 0;i<m;i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }

    for(int i = 0;i<=n;i++) {
        team[i] = i;
    }

    sort(v.begin(),v.end());

    for(int i = 0;i<k;i++) {
        int a;
        scanf("%d",&a);

        int num = upper_bound(v.begin(),v.end(),a)-v.begin();

        int real = find_head(num);
        
        printf("%d\n",v[real]);
        
        team[real] = find_head(team[real+1]);

    }
    return 0;
}
