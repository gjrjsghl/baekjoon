#include <bits/stdc++.h>

using namespace std;

pair<int,int> path[1000001];
int team[100001];

int find_team(int k) {
    if(team[k] == k) return k;

    return team[k] = find_team(team[k]);
} 

int main() {

    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 0;i<=n;i++) {
        team[i] = i;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    for(int i = 0;i<k;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        p.push({c,i});
        path[i] = {a,b};
    }

    int v = 1;
    long long int cnt = 0;
    while(!p.empty() and v < n-1) {

        int num = p.top().second;
        int cost = p.top().first;
        p.pop();

        int a = path[num].first, b = path[num].second;
        int teamA = find_team(a), teamB = find_team(b);
        if(teamA != teamB) {
            team[teamA] = teamB;
            cnt += cost;
            v += 1;
        }
    }
    printf("%lld",cnt);


    return 0;
}
