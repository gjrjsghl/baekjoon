#include <bits/stdc++.h>

using namespace std;

int v[1000001];

int main() {
    queue<pair<int,int>> q;

    int n;
    scanf("%d",&n);
    q.push({n,0});

    while(!q.empty()) {
        int num = q.front().first;
        int times = q.front().second;
        if(num == 1) {
            printf("%d",times);
            break;
        }
        if(num%2 == 0) {
            if(v[num/2] == 0) {
                q.push({num/2,times+1});
                v[num/2] = 1;
            }
        }
        if(num%3 == 0) {
            if(v[num/3] == 0) {
                q.push({num/3,times+1});
                v[num/3] = 1;
            }
        }
        if(v[num-1] == 0) {
            q.push({num-1,times+1});
            v[num-1] =1;
        }

        q.pop();
    }
    return 0;
}