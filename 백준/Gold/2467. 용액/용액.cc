#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d",&n);

    long long int arr[n];
    for(int i = 0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }

    int s = 0,e=n-1;
    long long int ans[3] = {20000000001,-1,-1};

    while(s < e and e < n) {
        //printf("s: %lld, e: %lld => ans: %lld\n",arr[s],arr[e],arr[s]+arr[e]);
        if(arr[s] + arr[e] == 0) {
            printf("%lld %lld",arr[s],arr[e]);
            return 0;
        }
        if(abs(arr[s]+arr[e]) < ans[0]) {
            ans[0] = abs(arr[s]+arr[e]);
            ans[1] = arr[s];
            ans[2] = arr[e];
        }
        
        if(arr[s]+arr[e] < 0) s += 1;
        else e -= 1;
        
    }

    printf("%lld %lld",ans[1],ans[2]);

    return 0;
}