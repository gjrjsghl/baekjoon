#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
bool notPrime[1000001];
int n;

void find_prime() {
    for(int i = 2;i<=n;i++) {
        if(notPrime[i] != 0) continue;
        prime.push_back(i);
        
        for(int j = i*2;j<=n;j+=i) {
            notPrime[j] = 1;
        }
    }
}


int main() {
    scanf("%d",&n);

    find_prime();

    long long int cnt = 0;
    for(int i = 2;i<=n;i++) {
        if(notPrime[i] == 0) cnt += i;
        else {
            for(int check : prime) {
                if(i%check == 0) {
                    cnt += check;
                    break;
                }
            }
        }
    }
    printf("%lld",cnt);
    
    return 0;
}