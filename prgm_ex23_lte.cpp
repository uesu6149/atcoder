#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  // ‰Šú‰»
  map<int, int> score;
  
  int val = 0;
  for (int i = 0; i < N; i++) {
    cin>> val ;
      score[val]++;
  }
  
  int key = 0;
  val = 0;
  for (int i = 0; i < score.size(); i++) {
    int tmp = score[i];
    if (tmp > val) {
      val = tmp;
      key = i;
    }
  }
  
  cout<<key<<" "<<val<<endl;
}
