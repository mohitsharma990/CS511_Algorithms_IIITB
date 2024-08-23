#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int l, int r) {
  int pivot = a[r];

  int i=l;
  for(int j=l; j<r; j++)  {
    if(a[j] < pivot) {
      swap(a[i], a[j]);
      i++;
    }
  }   

  swap(a[i], a[r]);
  return i;
}

int findRank(vector<int> &a, int l, int r, int k) {
  if(l<=r) {
    int pivot = rand()%(r-l+1) + l;

    swap(a[pivot], a[r]);

    int i = partition(a,l,r);
    int rank = r-i+1;
    if(rank == k) {return i;}
    else if(k > rank) {
      return findRank(a, l, i-1, k-r+i-1);
    }
    else{
      return findRank(a, i+1, r, k);
    }
  }

  return -1;
}

int main() {

  int n, k;
  cin >> n >> k;

  vector<int> a;
  for(int i=0; i<n; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }

  int l = 0, r = n-1;

  int idx = findRank(a,l,r,k);
  cout << a[idx];

  return 0;
}
