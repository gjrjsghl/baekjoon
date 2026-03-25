#include <bits/stdc++.h>

using namespace std;

int n;
int tree[100001];
int treeSize;

void swap(int* a, int* b) {
    int k = *a;
    *a = *b;
    *b = k;
}

void insertHeap(int num) {
    treeSize += 1;
    tree[treeSize] = num;
    int pos = treeSize;

    while(pos/2 > 0) {
        if(tree[pos] < tree[pos/2]) {
            swap(&tree[pos],&tree[pos/2]);
            pos /= 2;
        }
        else break;
    }
}

void sortHeap() {
    int pos = 1;

    while(1) {
        if(pos*2 <= treeSize) {
            if(pos*2+1 <= treeSize) {
                if(tree[pos*2] > tree[pos*2+1]) {
                    if(tree[pos] > tree[pos*2+1]) {
                        swap(&tree[pos*2+1],&tree[pos]);
                        pos = pos*2+1;
                    }
                    else break;
                }
                else {
                    if(tree[pos] > tree[pos*2]) {
                        swap(&tree[pos*2],&tree[pos]);
                        pos = pos*2;
                    }
                    else break;
                }
            }
            else {
                if(tree[pos] > tree[pos*2]) {
                    swap(&tree[pos*2],&tree[pos]);
                    pos = pos*2;
                }
                else break;
            }
        }
        else break;
    }
}

int main() {
    scanf("%d",&n);

    while(n--) {
        int o;
        scanf("%d",&o);

        if(o == 0) {
            if(treeSize == 0) printf("0\n");
            else {
                printf("%d\n",tree[1]);
                tree[1] = tree[treeSize--];
                
                sortHeap();
            }
        }
        else {
            
            insertHeap(o);
        }
    }

    return 0;
}