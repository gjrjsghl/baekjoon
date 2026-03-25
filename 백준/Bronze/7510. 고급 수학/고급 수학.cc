#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d ",&t);

    for(int i = 1;i<=t;i++) {
        int arr[3];
        for(int k = 0;k<3;k++) {
            scanf("%d",&arr[k]);
        }
        sort(arr,arr+3);
        printf("Scenario #%d:\n",i);
        if(arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) printf("yes\n");
        else printf("no\n");
        if(i != t) printf("\n");
    }
    return 0;
}