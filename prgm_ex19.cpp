#include <bits/stdc++.h>
using namespace std;

// �Q�Ɠn����p���āA�Ăяo�����̕ϐ��̒l��ύX����
void saiten(vector<vector<int>> &A, int &corret_count, int &wrong_count) {
  // �Ăяo������A�̊e�}�X�𐳂����l�ɏC������
  // A�̂����A�������l�̏����ꂽ�}�X�̌��� correct_count �ɓ����
  // A�̂����A������l�̏����ꂽ�}�X�̌��� wrong_count �ɓ����

  // �����Ƀv���O������ǋL
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
// ���������͕ύX���Ȃ�
// -------------------
int main() {
  // A�N�̉񓚂��󂯎��
  vector<vector<int>> A(9, vector<int>(9));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> A.at(i).at(j);
    }
  }

  int correct_count = 0; // �����ɐ������l�̃}�X�̌�������
  int wrong_count = 0;   // �����Ɍ�����l�̃}�X�̌�������
  //cout<<"1"<<endl;
  // A, correct_count, wrong_count���Q�Ɠn��
  saiten(A, correct_count, wrong_count);
  //cout<<"2"<<endl;
  // �������C�������\���o��
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << A.at(i).at(j);
      if (j < 8) cout << " ";
      else cout << endl;
    }
  }
  // �������}�X�̌����o��
  cout << correct_count << endl;
  // ����Ă���}�X�̌����o��
  cout << wrong_count << endl;
}
