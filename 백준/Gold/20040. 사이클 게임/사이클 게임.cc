#include <bits/stdc++.h>

using namespace std;

int team[500005];

int find_head(int n) {
    if(team[n] == n) return n;
    
    return team[n] = find_head(team[n]);
}

void join(int a, int b) {
    team[a] = b;
}

int main() {

    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 0;i<=n;i++) {
        team[i] = i;
    }

    for(int i = 1;i<=k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);

        int teamA = find_head(a);
        int teamB = find_head(b);
        if(teamA == teamB) {
            printf("%d",i);
            return 0;
        } 
        join(teamA,teamB);
    }
    printf("0");

    return 0;
}
