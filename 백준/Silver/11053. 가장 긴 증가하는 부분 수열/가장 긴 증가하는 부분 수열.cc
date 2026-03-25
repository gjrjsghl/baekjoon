#include <bits/stdc++.h>


using namespace std;

int num[1001];
int cnt[1001];

int main() {

    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++) {
        scanf("%d",&num[i]);
    }
    cnt[0] = 1;
    for(int i = 1;i<n;i++) {
        cnt[i] = 1;
        for(int j = 0;j<i;j++) {
            if(num[i] > num[j]) {
                cnt[i] = max(cnt[i],cnt[j]+1);
            }
        }
    }
    int k = 0;
    for(int i = 0;i<n;i++) {
        k = max(k,cnt[i]);
    }

    printf("%d",k);

    return 0;
}