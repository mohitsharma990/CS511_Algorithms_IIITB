//How to answer Range Sum Query:
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

int RSQ(vector<int> ST, int idx, int l_range, int r_range, int l, int r) {
    //Range query out of bound
    if(r_range < l || r < l_range) return 0;

    //Range query superset
    if(l >= l_range && r_range >= r) return ST[idx];

    //Range query is subset
    int mid = (l+r)/2;
    return RSQ(ST, 2*idx+1, l_range, r_range, l, mid) + RSQ(ST, 2*idx+2, l_range, r_range, mid+1, r);
}

int main() {

    vector<int> nums = {3, 1, 2, 7, 2, 1, 2, 3};
    int n = nums.size();
    vector<int> ST(4*n, 0); //n left nodes + n-1 internal nodes
    int rootIdx = 0;
    buildST(ST, rootIdx, nums, 0, n-1);

    for(int x : ST) {
        cout << x << " ";
    }
    cout << "\n";

    cout << RSQ(ST, 0, 2, 4, 0, n-1) << "\n";
    return 0;
}
