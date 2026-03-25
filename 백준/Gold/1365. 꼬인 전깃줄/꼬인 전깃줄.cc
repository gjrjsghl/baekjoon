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

int main() {

    int n;
    scanf("%d",&n);
    int a;
    scanf("%d",&a);
    nums.push_back(a);
    for(int i = 1;i<n;i++) {
        scanf("%d",&a);
        //printf("%d ",*(nums.end()-1));
        if(*(nums.end()-1) < a) nums.push_back(a);
        else nums[find_pos(a)] = a;
    }
    //printf("\n");
    // for(int i = 0;i<nums.size();i++) {
    //     printf("%d ",nums[i]);
    // }

    printf("%d",n-nums.size());
    return 0;
}