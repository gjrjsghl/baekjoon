#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k,d;
    scanf("%d %d %d",&n,&k,&d);

    int rule[10001][3];

    for(int i = 0;i<k;i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        rule[i][0] = a;
        rule[i][1] = b;
        rule[i][2] = c;
    }

    int m = 1;
    int M = n;
    int mid = 0;

    while(m < M) {
        mid = (m+M)/2;
        long long int cnt = 0;
        for(int i = 0;i<k;i++) {
            if(rule[i][0] > mid) continue;
            cnt += (min(mid,rule[i][1])-rule[i][0])/rule[i][2] +1;
        }
        if(cnt >= d) {
            M = mid;
        }
        else if(cnt < d) {
            m = mid+1;
        }
    }

    printf("%d",m);

    return 0;
}