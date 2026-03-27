#include <bits/stdc++.h>

using namespace std;

vector<int> after[401];
bool canGo[401][401];

void search(int k,int s) {
    canGo[s][k] = true;

    for(int next : after[k]) {
        if(canGo[s][next]) continue;
        search(next,s);
    }
}

int main() {

    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 0;i<k;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        after[a].push_back(b);
    }

    for(int i = 1;i<=n;i++) {
        search(i,i);
    }

    int s;
    scanf("%d",&s);

    while(s--) {
        int a,b;
        scanf("%d %d",&a,&b);
        if(canGo[a][b] == true) printf("-1");
        else if(canGo[b][a] == true) printf("1");
        else printf("0");
        printf("\n");
    }

    

    return 0;
}