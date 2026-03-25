#include <bits/stdc++.h>

using namespace std;

pair<int,int> p[2500001];

bool compareSTD1(pair<int,int>&a, pair<int,int>& b) {
    return a.second > b.second;
}
bool compareSTD2(pair<int,int>&a, pair<int,int>& b) {
    return a.first > b.first;
}

int main() {

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    for(int i = 0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        p[i] = {a,b};
    }

    sort(p,p+n,compareSTD1);
    
    long long int cnt = 0;    
    for(int i = 0;i<k;i++) {
        cnt += p[i].first;
        p[i].first = 0;
    }

    sort(p,p+n,compareSTD2);

    for(int i = 0;i<m;i++) {
        cnt += p[i].first;
        p[i].first = 0;
    }


    printf("%lld",cnt);


    
    return 0;
}