#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  vector<int> ages(3);
  cin >> ages.at(0) >> ages.at(1) >> ages.at(2);
  
  sort(ages.begin(), ages.end());
  
  cout<<ages.at(2) - ages.at(0)<<endl;
}
