#include <bits/stdc++.h>

using namespace std;

bool isPrime(int k) {
    if(k == 1 or (k%2 == 0 and k != 2)) return false;
    for(int i = 1;i*i<=k;i+=2) {
        if(i == 1) continue;
        if(k%i == 0) return false;
    }
    return true;
}

int canNum[6] = {1,2,3,5,7,9};
int n;

void getPrime(int k) {
    if(k/int(pow(10,n-1)) > 0) {
        printf("%d\n",k);
        return;
    }

    for (int next : canNum) {
        int cur = k*10+next;
        if(isPrime(cur)) getPrime(cur);
    }
}

int main() {

    scanf("%d",&n);
    getPrime(0);
    return 0;
}