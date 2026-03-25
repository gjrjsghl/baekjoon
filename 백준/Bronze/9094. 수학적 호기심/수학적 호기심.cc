#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d",&t);

    while(t--) {
        int n,m;
        scanf("%d %d",&n,&m);
        int c = 0;
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                if(i == 0 or j == 0) continue;
                if(((i*i+j*j+m)%(i*j)) == 0) c+=1;
            }
        }
        printf("%d\n",c);
    }

    return 0;
}