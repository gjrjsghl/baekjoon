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
int inp[1000001];
int main() {

    int n;
    scanf("%d",&n);
    pos[0] = 0;
    int a;
    scanf("%d",&a);
    nums.push_back(a);
    inp[0] = a;
    for(int i = 1;i<n;i++) {
        scanf("%d",&a);
        inp[i] = a;
        //printf("%d ",*(nums.end()-1));
        if(*(nums.end()-1) < a) {
            nums.push_back(a);
            pos[i] = nums.size()-1;
        } 
        else {
            int t = find_pos(a);
            nums[t] = a;
            pos[i] = t;
        } 
    }
    //printf("\n");
    // for(int i = 0;i<nums.size();i++) {
    //     printf("%d ",nums[i]);
    // }

    printf("%d\n",nums.size());
    int t = nums.size()-1;
    vector<int> ans;
    for(int i = n-1;i>=0;i--) {
        if(pos[i] == t) {
            ans.push_back(inp[i]);
            t -= 1;
        }
        if(t == -1) break;
    }

    while(!ans.empty()) {
        printf("%d ",ans.back());
        ans.pop_back();
    }
    

    return 0;
}