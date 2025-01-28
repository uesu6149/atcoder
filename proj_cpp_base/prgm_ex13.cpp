#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int total = 0;
  vector<int> v;
  for (int i = 0; i < N; i++) {
    int l_point = 0;
    cin >> l_point;
    v.push_back(l_point);
    total += l_point;
  }
  
  int avg = total / N;
  //cout<<"Avg:"<<avg<<endl;
  
  for (int i = 0; i < N; i++) {
    int diff = v.at(i) - avg;
    if (diff < 0)
      diff = diff * -1;
    cout<<diff<<endl;
  }
}