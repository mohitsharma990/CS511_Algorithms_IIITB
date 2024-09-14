//Building ST for purpose of range sum query:
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

int main() {

    vector<int> nums = {3, 1, 2, 7};
    int n = nums.size();
    vector<int> ST(4*n, 0); //n left nodes + n-1 internal nodes = total 2*n - 1 nodes needed in actual
    // but when your n is not a power of 2 then you need to take some dummy nodes in your segment tree, becoz if at a certain
    // level of tree, the nodes are odd then they all can't form a pair with any other node, so to make their pairing,
    // we need to add these dummy nodes
    int rootIdx = 0;
    buildST(ST, rootIdx, nums, 0, n-1);

    for(int x : ST) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}