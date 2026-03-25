#include <bits/stdc++.h>

using namespace std;


int team[100001];

int find_head(int n) {
    if(team[n] == n) return n;
    return team[n] = find_head(team[n]);
}

void join(int a, int b) {
    team[find_head(a)] = b;
}

int main() {

    int v,e;
    scanf("%d %d",&v,&e);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> num;
    pair<int,int> path[100001];

    for(int i = 1;i<=v;i++) {
        team[i] = i;
    }

    for(int i = 1;i<=e;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        path[i] = {a,b};
        num.push({c,i});
    }  
    //printf("\n");

    int p = 0;
    long long int sum = 0;
    while(!num.empty() and p < v-1) {
        int a = path[num.top().second].first, b = path[num.top().second].second;
        int cost = num.top().first;
        //printf("%d %d %d\n",a,b,cost);
        num.pop();

        if(find_head(a) != find_head(b)) {
            join(a,b);
            sum += cost;
            p += 1;
        }
    }
    printf("%lld",sum);


    return 0;
}
