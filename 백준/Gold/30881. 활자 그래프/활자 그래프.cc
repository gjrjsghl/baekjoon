#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int to;
    int cost;
    int type; //0: edge   1:1to2    2:2to1
};


vector<vector<Edge>> v[100001]; 

long long int found[100001][3];

void count_road(int k, int type) { //1: 1to2    2:2to1
    vector<long long int> c(v[k].size()+1,-1);
    priority_queue<pair<long long int,int>> p;
    p.push({0,type});

    while(!p.empty()) {
        long long int cost = -p.top().first;
        int pos = p.top().second;
        p.pop();

        if(c[pos] != -1 and c[pos] <= cost) continue;
        

        c[pos] = cost;    
        for(Edge road : v[k][pos]) {
            long long int t;
            if(road.type != 0) {
                if(found[road.cost][road.type] == 0)
                    count_road(road.cost,road.type);
                if(found[road.cost][road.type] == -1) continue;
                t = found[road.cost][road.type];
            }
            else t = road.cost;

            t += cost;
            if(t > 1000000000000000000LL or t < 0) continue;
            p.push({-t,road.to});
        }
    }

    found[k][type] = c[type==1?2:1];
}

int main() {
    int T;
    scanf("%d",&T);

    for(int i = 1;i<=T;i++) {
        int m,n;
        scanf("%d %d",&m,&n);
        for(int k = 0;k<=m;k++) {
            vector<Edge> temp;
            v[i].push_back(temp);
        }
        for(int z = 0;z<n;z++) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            v[i][a].push_back({b,abs(c),c<0?1:0});
            if(c < 0)
                v[i][b].push_back({a,(abs(c)),2});
        }
    }

    count_road(T,1);
    printf("%lld",found[T][1]);

    return 0;
}