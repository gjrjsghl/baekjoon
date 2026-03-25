#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    scanf("%d %d",&n,&k);
    int arr[100002];
    arr[0] = 0;
    for(int i = 1;i<=n;i++) {
        scanf("%d",&arr[i]);
        arr[i] += arr[i-1];
    }

    int s =0,e=0,len=n+1;

    while(s <= e and e <= n) {
        if(arr[e]-arr[s] < k) {
            e += 1;
        }
        else {
            len = min(e-s,len);
            s += 1;
        }
    }

    if(len == n+1) {
        printf("0");
        return 0;
    }
    printf("%d",len);
    
    return 0;
}