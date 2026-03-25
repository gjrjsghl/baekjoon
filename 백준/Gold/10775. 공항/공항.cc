#include <bits/stdc++.h>

using namespace std;

int main() {

    int g;
    scanf("%d",&g);
    int p;
    scanf("%d",&p);

    set<int> gate;

    for(int i = 0;i<=g;i++) {
        gate.insert(i);
    }
    int cnt = 0;
    for(int z = 0;z<p;z++) {
        int a;
        scanf("%d",&a);
        auto lower = gate.upper_bound(a);
        lower--;
        //printf("%d\n",*(--lower));
        if(*lower == 0) {
            break;
        }
        gate.erase(lower);
        cnt += 1;

    }
    printf("%d",cnt);
    return 0;
}
