//Lazy Propogation
#include <iostream>
#include <vector>
using namespace std;

void updateRange(int start, int end, int l, int r, int idx, int val, vector<int> &ST, vector<int> &lazyTree) {
    if(lazyTree[idx] != 0) {
        ST[idx] += lazyTree[idx];
        if(l!=r) { //not a leaf node
            lazyTree[2*idx+1] += lazyTree[idx];
            lazyTree[2*idx+2] += lazyTree[idx];
        }
        lazyTree[idx] = 0;
    }

    if(end < l || start > r || l > r) {
        return;
    }

    if(l >= start && end >= r) {
        ST[idx] += val;
        lazyTree[2*idx+1] += val;
        lazyTree[2*idx+2] += val;
        return;
    }

    int mid = l + (r-l)/2;
    updateRange(start, end, l, mid, 2*idx+1, val, ST, lazyTree);
    updateRange(start, end, mid+1, end, 2*idx+2, val, ST, lazyTree);
    ST[idx] = ST[2*idx+1] + ST[2*idx+2];

    return;
}

void buildST(int l, int r, int idx, vector<int> &ST, vector<int>nums) {
    if(l == r) {
        ST[idx] = nums[l];
        return;
    }

    int mid = l + (r-l)/2;
    buildST(l, mid, 2*idx+1, ST, nums);
    buildST(mid+1, r, 2*idx+2, ST, nums);
    ST[idx] = ST[2*idx+1] + ST[2*idx+2];
    return;
}

int main() {
    vector<int> nums = {3, 1, 2, 7};
    int n = nums.size();

    vector<int> ST(4*n,0), lazyTree(4*n,0);

    buildST(0, n-1, 0, ST, nums);

    for(int x : ST) {
        cout << x << " ";
    }

    cout << endl;

    updateRange(1, 2, 0, n-1, 0, 2, ST, lazyTree);

    for(int x : ST) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}