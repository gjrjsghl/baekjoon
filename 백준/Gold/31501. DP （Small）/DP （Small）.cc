#include <bits/stdc++.h>


using namespace std;


int arr[3001];

int main() {

    int n,q;
    scanf("%d %d",&n,&q);

    for(int i = 1;i<=n;i++) {
        scanf("%d ",&arr[i]);
    }
    int cnt[3001];
    cnt[1] = 1;
    for(int i = 2;i<=n;i++) {
        cnt[i] = 1;
        for(int j=1;j<i;j++) {
            if(arr[i] > arr[j])
                cnt[i] = max(cnt[i],cnt[j]+1);
        }
    }
    int cnt2[3001];
    cnt2[n] = 1;
    for(int i = n-1;i >= 1;i--) {
        cnt2[i] = 1;
        for(int j = n;j>i;j--) {
            if(arr[i] < arr[j]) 
                cnt2[i] = max(cnt2[i],cnt2[j]+1);
        }
    }
    
    while(q--) {
        int a;
        scanf("%d",&a);

        printf("%d\n",cnt[a]+cnt2[a]-1);
    }
    return 0;
}