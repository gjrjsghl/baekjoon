#include <bits/stdc++.h>

using namespace std;

int xy[1001][1001];
int c,n,x;
bool v[1001];

void dfs(int z) {
    v[z] =true;
    cout << z << " ";
    for(int i = 1;i<=c;i++) {
        if(xy[z][i] == 1) {
            if(!v[i]) {
                dfs(i);
            }
        }
    }
}


bool vi[1001];

void bfs(int z) {
    queue <int> q;

    q.push(z);

    vi[z] = 1;

    while(!q.empty()) {
        int zz = q.front();
        cout << zz << " ";
        q.pop();
        for(int i = 1;i<=c;i++) {
            if(xy[zz][i] == 1) {
                if(!vi[i]) {
                    q.push(i);
                    vi[i] =1;
                }
            }
        }
    }
}

int main()
{
    cin >> c >> n >> x;

    int a,b;
    for(int i = 0;i<n;i++) {
        cin >>a>>b;
        xy[a][b] = 1;
        xy[b][a] = 1;
    }
    dfs(x);
    cout << "\n";
    bfs(x);
    return 0;
}
