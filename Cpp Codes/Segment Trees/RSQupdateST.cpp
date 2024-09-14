//Updating segment tree if one value in the array nums got changed:
#include <iostream>
#include <vector>
using namespace std;

void buildST(vector<int> &ST, int idx, vector<int> nums, int l, int r) {
    //Base Case:
    if(l == r) {
      ST[idx] = nums[l];
      return;
    }

    //Recursion:
    int mid = (l+r)/2;
    buildST(ST,2*idx + 1, nums, l, mid);
    buildST(ST, 2*idx + 2, nums, mid+1, r);
    ST[idx] = ST[2*idx + 1] + ST[2*idx + 2];

    return;
}

void updateST(vector<int> &ST, int idx, int nums_idx, int val, int l, int r) {
    //Base Condition:
    if(l == r) {
        ST[idx] = val;
        return;
    }

    int mid = (l+r)/2;
    if(nums_idx <= mid) updateST(ST, 2*idx+1, nums_idx, val, l, mid);
    else updateST(ST, 2*idx+2, nums_idx, val, mid+1, r);
    ST[idx] = ST[2*idx+1] + ST[2*idx+2];

    return;
}

int main() {

    vector<int> nums = {3, 1, 2, 7};
    int n = nums.size();
    vector<int> ST(4*n, 0); //n left nodes + n-1 internal nodes
    int rootIdx = 0;
    buildST(ST, rootIdx, nums, 0, n-1);

    for(int x : ST) {
        cout << x << " ";
    }
    cout << "\n";

    updateST(ST, 0, 2, 3, 0, n-1);

    for(int x : ST) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
