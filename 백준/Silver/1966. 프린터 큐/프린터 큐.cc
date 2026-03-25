#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    while(t--) {
        int n,k;
        scanf("%d %d",&n,&k);
        queue<pair<int,int>> q;
        priority_queue<int> imp;
        for(int i = 0;i<n;i++) {
            int a;
            scanf("%d",&a);
            imp.push(a);
            if(i == k)
                q.push({a,1});
            else q.push({a,0});
        }
        int c = 0;
        while(!q.empty()) {
            if(q.front().first != imp.top()) {
                q.push(q.front());
                q.pop();
            }
            else {
                c += 1;
                if(q.front().second == 1) {
                    printf("%d\n",c);
                    break;
                }
                imp.pop();
                q.pop();
            }
        }
    }

    

    return 0;
}