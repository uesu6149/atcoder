#include <bits/stdc++.h>
using namespace std;

void isOddOrEven(int a, int b) {
  if ((a*b)%2 == 1) {
    cout<<"Odd"<<endl;
  }
  else {
    cout<<"Even"<<endl;
  }
}

int main() {
  int a=0, b=0;
  cin>>a>>b;
  
  isOddOrEven(a,b);
  
  return 0;
}