#include <bits/stdc++.h>


using namespace std;

int n;

vector<int> alp[30]; //가능한 문자 저장
int v[30]; //탐색했는지 1탐색중 2탐색완료 0미방문
int parent[30]; //어디서 왔는가?
pair<int,int> s; //가장 긴 깊이
pair<int,int> point; //사이클 끝
bool find_cycle; //사이클 발견 여부
int child[30];

int dis[30]; //여기 뒤에 깊이가 어느정도지?

int dfs(int k,int p, int d) {
    if(find_cycle) return -1;

    v[k] = 1;
    parent[k] = p;

    
    int back = 0;

    for(int next : alp[k]) {
        if(v[next] == 1) {
            find_cycle = 1;
            point = {next,k};
            return -1;
        }
        if(v[next] == 0) {
            int z = dfs(next,k,d+1);
            if(z > back) {
                child[k] = next;
                back = z;
            }
        } 
        if(find_cycle) return -1;
        if(v[next] == 2) {
            int z = dis[next];
            if(z > back) {
                back = z;
                child[k] = next;
            }
        }
    }
    v[k] = 2;
    if(s.second < back+1) s = {k,back+1};
    return dis[k] = back+1;
}

string get_cycle(int k, int p) {
    string ans = "";
    ans += char(k+'a'-1);
    k = p;
    while(1) {
        if(char(k+'a'-1) == ans[0]) break;
        ans += char(k+'a'-1);
        k = parent[k];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string get_path(int k, int c) {
    string ans = "";
    for(int i = 0;i<c;i++) {
        ans += char(k+'a'-1);
        k = child[k];
    }
    return ans;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int grid[30][30];
        for(int i = 1;i<=26;i++) {
            for(int j = 1;j<=26;j++) {
                grid[i][j] = 1;
            }
        }
        s = {0,0};
        point = {0,0};
        find_cycle = 0;
        for(int i = 0;i<30;i++) {
            v[i] = 0;
            parent[i] = 0;
            alp[i].clear();
            child[i] = 0;
            dis[i] = 0;
        }
        for(int i = 0;i<n;i++) {
            char a,b;
            scanf(" %c %c",&a,&b);
            grid[a-'a'+1][b-'a'+1] = 0;
        }

        for(int i = 1;i<=26;i++) {
            for(int j = 1;j<=26;j++) {
                if(grid[i][j] == 1)
                    alp[i].push_back(j);
            }
        }

        for(int i = 1;i<=26;i++) {
            if(v[i] == 0) {
                dfs(i,0,1);
            }
            if(find_cycle) break;
        }

        if(find_cycle) {
            string cycle = get_cycle(point.first,point.second);

            for(int i = 0;i<20;i++) {
                for(int j = 0;j<20;j++) {
                    printf("%c",cycle[(i+j)%cycle.size()]);
                }
                printf("\n");
            }
        }
        else {
            string path = get_path(s.first,s.second);

            int n = (path.size()+1)/2;

            for(int i = 0;i<n;i++) {
                for(int j = 0;j<n;j++) {
                    printf("%c",path[i+j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}