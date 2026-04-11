#include <bits/stdc++.h>

using namespace std;


class Tree {

private:

    unordered_map<int,int> mask;
    long long int tree[400005];
    int length=1;
    int cnt = 0;

    int makeTree(int left, int right, int k) {
        if(left == right) return tree[k] = 1;

        int mid = (left+right)/2;

        return tree[k] = makeTree(left,mid,k*2)+makeTree(mid+1,right,k*2+1);
    }

    void updateTree(int left, int right, int k, int t) {
        if(t < left or t > right) return;

        tree[k] -=1;

        if(left == right) return;

        int mid = (left+right)/2;
        
        if(t <= mid)
            updateTree(left,mid,k*2,t);
        if(t > mid) 
            updateTree(mid+1,right,k*2+1,t);
    }

    long long int findtree(int left,int right, int k, int t) {
        if(t < left) return 0;

        if(right <= t) return tree[k];
        
        int mid = (left+right)/2;

        return findtree(left,mid,k*2,t)+findtree(mid+1,right,k*2+1,t);
    }

public:

    void append(int a) {
        mask[a] = length;
        length += 1;
    }

    void setup() {
        makeTree(1,length,1);
    }

    long long int answer(int k) {
        k = mask[k];
        long long int ans = findtree(1,length,1,k-1);
        updateTree(1,length,1,k);

        return ans;
    }
};



int main() {

    int t;
    scanf("%d",&t);

    while(t--) {
        Tree tree;
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++) {
            int a;
            scanf("%d",&a);
            tree.append(a);
        }
        tree.setup();
        long long int cnt = 0;
        for(int i = 0;i<n;i++) {
            int a;
            scanf("%d",&a);
            cnt += tree.answer(a);
        }
        printf("%lld\n",cnt);
    }

    return 0;
}