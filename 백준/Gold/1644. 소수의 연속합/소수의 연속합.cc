#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> prime;
int nums[4000001];

void che() {
    for(int i = 2;i*i<=n;i++) {
        if(nums[i] != 0) continue;
        for(int j = i*i;j<=n;j+=i) {
            nums[j] = 1;
        }
    }

    for(int i = 2;i<=n;i++) {
        if(nums[i] == 0) prime.push_back(i);
    }
}

int main() {
    prime.push_back(0);
    scanf("%d",&n);
    if(n == 1) {
        printf("0");
        return 0;
    }
    if(n == 2) {
        printf("1");
        return 0;
    }

    che();

    // for(int i = 0;i<prime.size();i++) {
    //     printf("%d ",prime[i]);
    // }

    
    for(int i = 1;i<prime.size();i++) {
        prime[i] += prime[i-1];
    }


    // printf("\n");
    // for(int i = 0;i<prime.size();i++) {
    //     printf("%d ",prime[i]);
    // }

    //printf("\n");
    int c = 0;
    int s = 0,e=1;
    while(s <= e and e < prime.size()) {
        //printf("s: %d, e: %d => %d\n",s,e,prime[e]-prime[s]);
        if(prime[e]-prime[s] > n) {
            s += 1;
        }
        else if(prime[e] - prime[s] < n) {
            e += 1;
        }
        else {
            //printf("ans found : %d %d\n",s+1,e);
            c += 1;
            e += 1;
            s += 1;
        }
    }
    printf("%d",c);
    return 0;
}