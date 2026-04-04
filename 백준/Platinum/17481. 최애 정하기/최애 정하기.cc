#include <bits/stdc++.h>

using namespace std;


int n,m;
unordered_map<string,int> nameToindex; //아이돌 이름을 숫자번호로 바꿈

deque<int> love[1001]; //누구를 좋아하는가
int matchFrom[1001]; //누구랑 매칭됐는가

bool v[1001];
bool match(int k) {

    for(int who : love[k]) {
        if(v[who]) continue; //이미 탐색했으면 버리기
        v[who] = true;

        if(matchFrom[who] == 0) { //빈자리면 바로 먹기
            matchFrom[who] = k;
            return true;
        }

        if(match(matchFrom[who])) { //빈자리가 아니면 양보가능한지 체크하기
            matchFrom[who] = k;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1;i<=m;i++) {
        string s;
        cin >> s;
        nameToindex[s] = i;
    }
    for(int i = 1;i<=n;i++) {
        int k;
        cin >> k;
        for(int j = 0;j<k;j++) {
            string s;
            cin >> s;
            love[i].push_back(nameToindex[s]);
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++) {
        fill(v,v+m+1,0);
        bool check = match(i);
        if(check) cnt += 1;
    }


    if(cnt == n) {
        cout << "YES";
    }
    else {
        cout << "NO\n" << cnt;
    }

    return 0;
}