#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // �����Ƀv���O������ǋL
  // (������"�������ʂ̕\"��2�����z���錾)
   vector<vector<char>> board(N, vector<char>(N));
 // cout << "1" <<endl;
  // ������
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = '-';
    }
  }
  //cout << "2:" << M <<endl;
  for (int i = 0; i < M; i++) {
 //   cout << "2 >> " << i << ":" << A.at(i) << ":" << B.at(i)<< endl;
    board[A.at(i)-1][B.at(i)-1] = 'o';
    board[B.at(i)-1][A.at(i)-1] = 'x';
    
  }
  
  //cout << "3" <<endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board.at(i).at(j);
      if (j == N - 1) {
        cout << endl;  // �s���Ȃ���s
      }
      else {
        cout << " ";  // �s���łȂ��Ȃ�󔒂��o��
      }
    }
  }
}
