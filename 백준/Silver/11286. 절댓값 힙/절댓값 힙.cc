#include <bits/stdc++.h>

using namespace std;


struct compare
{
    bool operator() (int a, int b) {
        if(abs(a) > abs(b)){
            return true;
        }
        else if(abs(a) < abs(b)) {
            return false;
        }
        else return a>b;
    }
};


int main() {
    priority_queue<int,vector<int>,compare> p;

    int n;
    scanf("%d",&n);

    while(n--) {
        int a;
        scanf("%d",&a);
        if(a == 0) {
            if(p.empty()) {
                printf("0\n");
                continue;
            }
            printf("%d\n",p.top());
            p.pop();
        }
        else p.push(a);
    }

    return 0;
}