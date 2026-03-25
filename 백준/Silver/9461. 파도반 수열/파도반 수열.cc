#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int cnt[101];
    cnt[1] = 1;
    cnt[2] = 1;
    cnt[3] = 1;
    cnt[4] = 2;
    for(int i = 5;i<=100;i++) {
        cnt[i] = cnt[i-2]+cnt[i-3];
    }
    int t;
    scanf("%d",&t);
    while(t--) {
        int a;
        scanf("%d",&a);
        printf("%lld\n",cnt[a]);
    }
    return 0;
}
