#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N, A, B;
  cin >> N ;
  vector<pair<int,int>> pairs;
  for (int i = 0; i < N; i++) {
    // Bをソートしないので、順番を逆にしていれる
    cin >> A >> B;
    pairs.push_back(make_pair(B, A));
    
  }
  
  sort(pairs.begin(), pairs.end());

  // 画面出力 1st <-> 2ndと逆で表示する
  for (int i = 0; i < pairs.size(); i++) {
    cout<< pairs.at(i).second << " " << pairs.at(i).first << endl;
  }

  return 0;
}