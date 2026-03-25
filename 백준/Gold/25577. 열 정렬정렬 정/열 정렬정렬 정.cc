#include <bits/stdc++.h>

using namespace std;

int goalpos[100001];
int arr[100001];


bool v[100001];

int find_team(int k) {
    if(v[k]) return 0;
    v[k] = true;
    return find_team(goalpos[k])+1;
}

int main() {
    vector<int> goal;
    int n;
    scanf("%d",&n);

    for(int i = 0;i<n;i++) {
        int a;
        scanf("%d",&a);
        goal.push_back(a);
        arr[i] = a;
    }

    sort(goal.begin(),goal.end());

    for(int i = 0;i<n;i++) {
        goalpos[i] = lower_bound(goal.begin(),goal.end(),arr[i])- goal.begin();;
    }
    
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        if(v[i] == false) {
            int c = find_team(i);
            cnt += c-1;
        }
    }
    printf("%d",cnt);
    return 0;
}