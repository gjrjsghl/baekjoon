#include <bits/stdc++.h>

using namespace std;


vector<int> nums;
int find_pos(int k) {

    int size =nums.size();
    int s=0,e=size-1;
    int mid;
    while(s < e) {
        mid = (s+e)/2;
        if(nums[mid] < k) {
            s = mid+1;
        }
        else if(nums[mid] >= k) {
            e = mid;
        }
    }
    return s;
}

int pos[1000001];
pair<int,int> z[100001];
int main() {
    int n;
    scanf("%d",&n);
    pos[0] = 0;
    int a;


    for(int i = 0;i<n;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        z[i] = {a,b};
    }

    sort(z,z+n,less<pair<int,int>>());

    nums.push_back(z[0].second);
    pos[0] = 0;
    for(int i = 1;i<n;i++) {
        if(nums.back() < z[i].second) {
            pos[i] = nums.size();
            nums.push_back(z[i].second);
        }
        else {
            int t = find_pos(z[i].second);
            pos[i] = t;
            nums[t] = z[i].second;
        }
    }

    printf("%d\n",n-nums.size());

    int t = nums.size()-1;
    vector<bool> lis(n,false);

    for(int i = n-1;i>=0;i--) {
        if(pos[i] == t) {
            lis[i] = true;
            t -= 1;
        }
        if(t < 0) break;
    }
    
    for(int i = 0;i<n;i++) {
        if(lis[i] == false) printf("%d\n",z[i].first);
    }


    return 0;
}