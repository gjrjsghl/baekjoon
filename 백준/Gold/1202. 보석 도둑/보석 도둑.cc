#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    scanf("%d %d",&n,&k);

    priority_queue <pair<int,int>> bosuk;
    for(int i = 0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        bosuk.push({-a,b});
    }
    bosuk.push({-200000000,0});

    priority_queue<int,vector<int>,greater<int>> bag;
    for(int i = 0;i<k;i++) {
        int a;
        scanf("%d",&a);
        bag.push(a);
    }

    long long int c = 0;
    int fos = 0;
    priority_queue<int> getBosuk;
    while(!bag.empty()) {  
        int nbag = bag.top();
        bag.pop();

        for(;-bosuk.top().first <= nbag;bosuk.pop()) {
            getBosuk.push(bosuk.top().second);
        }
        
        if(getBosuk.empty()) continue;
        c += getBosuk.top();
        getBosuk.pop();
    }

    printf("%lld",c);



    return 0;
}