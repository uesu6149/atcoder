#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N, A, B;
  cin >> N ;
  vector<pair<int,int>> pairs;
  for (int i = 0; i < N; i++) {
    // B���\�[�g���Ȃ��̂ŁA���Ԃ��t�ɂ��Ă����
    cin >> A >> B;
    pairs.push_back(make_pair(B, A));
    
  }
  
  sort(pairs.begin(), pairs.end());

  // ��ʏo�� 1st <-> 2nd�Ƌt�ŕ\������
  for (int i = 0; i < pairs.size(); i++) {
    cout<< pairs.at(i).second << " " << pairs.at(i).first << endl;
  }

  return 0;
}