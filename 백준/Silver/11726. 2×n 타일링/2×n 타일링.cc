#include <bits/stdc++.h>

using namespace std;


long long int cnt[1001];
int main() {

    int t;
    scanf("%d",&t);
    cnt[1] = 1;
    cnt[2] = 2;

    for(int i = 3;i<=t;i++) {
        cnt[i] = (cnt[i-1]+cnt[i-2])%10007;
    }
    printf("%lld",cnt[t]);
    return 0;
}