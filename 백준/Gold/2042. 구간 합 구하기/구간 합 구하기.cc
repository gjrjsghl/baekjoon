#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long int> tree;
long long int arr[1000001];

long long int init(int s, int e,int idx) {

    if(s == e) return tree[idx] = arr[s];

    int mid = (s+e)/2;

    return tree[idx] = init(s,mid,idx*2) + init(mid+1,e,idx*2+1);
}

long long int getSum(int s,int e,int left, int right, int idx) { 
    //right, left : 구할것,  s, e : 노드포함
    if(right < s || left > e) return 0;

    if(left <= s && e <= right) return tree[idx];

    int mid = (s+e)/2;

    return getSum(s,mid,left,right,idx*2) + getSum(mid+1,e,left,right,idx*2+1);

}

void update(int s,int e, int pos,long long int value,int idx) {
    if(s > pos or e < pos) return;

    if(s <= pos and e >= pos) {
        tree[idx] += value;
        int mid = (s+e)/2;
        if(s == e) return;
        update(s,mid,pos,value,idx*2);
        update(mid+1,e,pos,value,idx*2+1);
    }
}

int main() {
    int m,k;

    scanf("%d %d %d",&n,&m,&k);
    tree.resize(4*n);

    for(int i = 0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }

    init(0,n-1,1);

    for(int i = 0;i<m+k;i++) {
        int a,b;
        long long int c;
        scanf("%d %d %lld",&a,&b,&c);
        if(a == 1) {
            update(0,n-1,b-1,c-arr[b-1],1);
            arr[b-1] = c;
        }
        else {
            printf("%lld\n",getSum(0,n-1,b-1,c-1,1));
        }
    }

    return 0;
}