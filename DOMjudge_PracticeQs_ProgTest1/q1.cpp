#include <iostream>
using namespace std;

int main() {
  int t;
  long long n;
  int k;
  
  cin >> t;

  for(int i=1; i<=t; i++) {
    cin >> n >> k;
    long long count = 0;
    if(n == 0 && k == 0) {
      count = 1;
    }
    else {
      while(n) {
        if(n % 10 == k) {
          count++;
        }
        n /= 10;
      }
    }
    cout << count << endl;
  }


   return 0;
}
