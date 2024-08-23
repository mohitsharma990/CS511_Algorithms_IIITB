#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> matMul(vector<vector<long long>> A, vector<vector<long long>> B) {
  vector<vector<long long>> result;
  for(int i=0; i<100; i++) {
    vector<long long> temp(100,0);
    result.push_back(temp);
  }
  
  for(int i=0; i<100; i++) {
    for(int j=0; j<100; j++) {
      long long temp = 0;
      for(int k=0; k<100; k++) {
        temp += (A[i][k] * B[k][j]);
      }
      result[i][j] = temp;
    }
  }

  return result;
}

void powOfA(vector<vector<long long>> &A, int n) {
  vector<vector<long long>> powA;
  for(int i=0; i<100; i++) {
    vector<long long> temp(100,0);
    temp[i] = 1;
    powA.push_back(temp);
  }

  for( ; n>0; n/=2) {
    if(n % 2) {
      powA = matMul(powA, A);
    }
    
    A = matMul(A,A);
  }

  A = powA;
}

long long laggedFib(long long n) {
  if(n <= 99) {
    return n;
  }
  
  //Forming matrix 'A' for this problem;
  vector<vector<long long>> A;
  vector<long long> temp(100,0);
  temp[98] = 1;
  temp[99] = 1;
  A.push_back(temp);

  for(int i=0; i<99; i++) {
    vector<long long> temp(100,0);
    temp[i] = 1;
    A.push_back(temp);
  }

  powOfA(A,n-99);

  long long value = 0;
  long long startVal = 99;
  for(int i=0; i<100; i++) {
    value += ((startVal--)*A[0][i]);
  }

  return value;
}

int main() {
  long long n;
  cin >> n;

  cout << laggedFib(n);

  return 0;
}
