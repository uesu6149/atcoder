#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  // data�̒��ŗׂ荇���������v�f�����݂���Ȃ�"YES"���o�͂��A�����łȂ����"NO"���o�͂���
  // �����Ƀv���O������ǋL
  int isFound = 0;
  for (int i = 0; i < (data.size()-1); i++) {
    if (data.at(i) == data.at(i+1)) {
      isFound = 1;
    }
  }
  if (isFound) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  
  /*
  if (data.at(0) == data.at(1)) {
    cout<<"YES"<<endl;
  }
  else if (data.at(1) == data.at(2)) {
    cout<<"YES"<<endl;
  }
  else if (data.at(2) == data.at(3)) {
    cout<<"YES"<<endl;
  }
  else if (data.at(3) == data.at(4)) {
    cout<<"YES"<<endl;
  }
  else {
     cout<<"NO"<<endl;
  }
  */
}
