#include <bits/stdc++.h>

using namespace std;

long long int m, M;

int num[1000001];
int checkMUL[1000001];


int che() {
    int k = M-m+1;
    for(long long int i = 2;i*i <= M;i++) {
        if(checkMUL[i] == 1) continue;
        //printf("%lld ",i*i);
        long long int x = (m/(i*i)) * (i*i);
        if(x < m) x+=(i*i);
        for(int j = i;x<=M;x+=i*i) {
            
            if(num[x-m] == 1) continue;
            //printf("\t%lld\n",x);
            checkMUL[i] = 1;
            num[x-m] = 1;

            k -= 1;
        }
    }

    return k;
}



int main() {

    scanf("%lld %lld",&m,&M);

    printf("%d",che());
    return 0;
}