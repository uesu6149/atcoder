#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  int ans = A;

  // ‚±‚±‚ÉƒvƒƒOƒ‰ƒ€‚ğ’Ç‹L
  for (int i = 1; i <= N; i++) {
    string ops;
    int B;
    cin >> ops >> B;
    
    if (ops == "+") {
      ans = ans + B;
    }
    else if (ops == "-") {
      ans = ans - B;
    }
    else if (ops == "*") {
      ans = ans * B;
    }
    else if (ops == "/" && B != 0) {
      ans = ans / B;
    }
    else {
      cout<<"error"<<endl;
      break;
    }
    cout<<i<<":"<<ans<<endl;
  }
}