#include <bits/stdc++.h>

using namespace std;

long long int arr[5001];

int main() {

    int n;
    scanf("%d",&n);

    for(int i = 0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }

    sort(arr,arr+n,less<long long int>());
    // for(int i = 0;i<n;i++) {
    //     printf("%lld ",arr[i]);
    // }
    long long int ans[4] = {LONG_LONG_MAX,-1,-1,-1};

    for(int i = 0;i<n;i++) {
        int s=i+1,e=n-1;
        long long int sum = arr[i];

        while(s < e) {
            //printf("%d %d %d %lld\n",i,s,e,sum);
            long long int nowSum = arr[s]+arr[e];

            if(abs(nowSum+sum) < ans[0]) {
                ans[0] = abs(nowSum+sum);
                ans[1] = arr[i];
                ans[2] = arr[s];
                ans[3] = arr[e];
            }
            if(sum + nowSum < 0) s+=1;
            else if(sum+nowSum > 0) e -= 1;
            else break;
        }

        if(ans[0] == 0) break;
    }
    
    for(int i = 1;i<4;i++) {
        printf("%lld ",ans[i]);
    }
    return 0;
}

