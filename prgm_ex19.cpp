#include <bits/stdc++.h>
using namespace std;

// 参照渡しを用いて、呼び出し側の変数の値を変更する
void saiten(vector<vector<int>> &A, int &corret_count, int &wrong_count) {
  // 呼び出し側のAの各マスを正しい値に修正する
  // Aのうち、正しい値の書かれたマスの個数を correct_count に入れる
  // Aのうち、誤った値の書かれたマスの個数を wrong_count に入れる

  // ここにプログラムを追記
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0 ; j < A.at(i).size(); j++) {
      int val = (i+1) * (j+1);
      if (val == A.at(i).at(j)) {
        corret_count++;
      }
      else {
        A.at(i).at(j) = val;
        wrong_count++;
      }
      //cout << A.at(i).at(j) << " ";
    }
   // cout << endl;
  }
  
}


// -------------------
// ここから先は変更しない
// -------------------
int main() {
  // A君の回答を受け取る
  vector<vector<int>> A(9, vector<int>(9));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> A.at(i).at(j);
    }
  }

  int correct_count = 0; // ここに正しい値のマスの個数を入れる
  int wrong_count = 0;   // ここに誤った値のマスの個数を入れる
  //cout<<"1"<<endl;
  // A, correct_count, wrong_countを参照渡し
  saiten(A, correct_count, wrong_count);
  //cout<<"2"<<endl;
  // 正しく修正した表を出力
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << A.at(i).at(j);
      if (j < 8) cout << " ";
      else cout << endl;
    }
  }
  // 正しいマスの個数を出力
  cout << correct_count << endl;
  // 誤っているマスの個数を出力
  cout << wrong_count << endl;
}
