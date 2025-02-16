#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int S_len = S.size();
  int ans = 1;
  for (int i = 1; i < S_len; i++) {
    if (S.at(i) == '+') {
      ans++;
    }
    else if (S.at(i) == '-') {
      ans--;
    }
    else {
    }
  }  
  cout<<ans<<endl;
}
