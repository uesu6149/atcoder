#include <bits/stdc++.h>
using namespace std;

// ��蕶�̌`����vec�l���o��
void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

// �ϐ�����ǂݎ��C�R�[����ǂݔ�΂�
string read_name() {
  string name, equal;
  cin >> name >> equal;
  return name;
}

// int���̍���1�ǂݎ��B
// �����Ȃ炻�̒l��Ԃ��A�����łȂ��Ȃ�ϐ��Ƃ��ĉ��߂��ϐ��̒l��Ԃ�
// var_int : int�̕ϐ���ێ�����map
int read_int(map<string, int> &var_int) {
  string val;
  cin >> val;

  // �ŏ��̕������������ǂ����Ő������ϐ����𔻒�i3.06�ŏЉ���������Z�q���g�p�Bif���ŏ����Ă��ǂ��B�j
  return isdigit(val.at(0))
    ? stoi(val) // ���l�̏ꍇ
    : var_int.at(val); // �ϐ��̏ꍇ

  // isdigit�֐���3.06�ŁAstoi�֐���3.01�ŏЉ�Ă���
  // �������g�킸�����ŕϊ����鏈���������Ă��ǂ�
}

// int���S�̂�ǂݎ���Čv�Z����
// var_int : int�̕ϐ���ێ�����map
int calc_int(map<string, int> &var_int) {

  string symbol = ""; // ���Z�q���󂯎��ϐ�
  int result = 0; // ���ʂ�ێ�����ϐ�

  // ���̏I���ł���";"���o�Ă���܂œǂݎ��
  while (symbol != ";") {
    // ����1�ǂݎ��
    int val = read_int(var_int);

    // �L�������͂���ĂȂ��ꍇ�i���̍ŏ��̍��j�͌��ʂɂ��̂܂ܑ��
    if (symbol == "") {
      result = val;
    }
    // �����Z�̏ꍇ
    if (symbol == "+") {
      result += val;
    }
    // �����Z�̏ꍇ
    if (symbol == "-") {
      result -= val;
    }

    // symbol�ɂ�"+", "-", ";"�̂����ꂩ�����͂����
    cin >> symbol;
  }

  return result;
}

// vec�l��ǂݎ��
// �ŏ���"["�͓ǂݎ���Ă���O��ł��邱�Ƃɒ���
// var_int : int�̕ϐ���ێ�����map
vector<int> read_vec_val(map<string, int> &var_int) {

  vector<int> result; // ���ʂ�ێ�����ϐ�
  string symbol = ""; // vec�l���̋L�����󂯎��ϐ�

  // vec�l�̏I���ł���"]"���o�Ă���܂œǂݎ��
  while (symbol != "]") {
    // ���l��1�ǂݎ����vec�ɒǉ�
    int val = read_int(var_int);
    result.push_back(val);

    // symbol�ɂ�","��"]"�����͂����
    cin >> symbol;
  }

  return result;
}

// vec���̍���1�ǂݎ��
// vec�l�Ȃ炻�̒l��Ԃ��A�����łȂ��Ȃ�ϐ��Ƃ��ĉ��߂��ϐ��̒l��Ԃ�
// var_int : int�̕ϐ���ێ�����map
// var_vec : vec�̕ϐ���ێ�����map
vector<int> read_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec) {

  string val;
  cin >> val;

  // "["���ǂ�����vec�l���ϐ����𔻒�i3.06�ŏЉ���������Z�q���g�p�Bif���ŏ����Ă��ǂ��B�j
  return val == "["
    ? read_vec_val(var_int) // vec�l�̏ꍇ
    : var_vec.at(val); // �ϐ��̏ꍇ
}

// vec���S�̂�ǂݎ���Čv�Z����
// var_int : int�̕ϐ���ێ�����map
// var_vec : vec�̕ϐ���ێ�����map
vector<int> calc_vec(map<string, int> &var_int, map<string, vector<int>> &var_vec) {

  string symbol; // ���Z�q���󂯎��ϐ�
  vector<int> result; // ���ʂ�ێ�����ϐ�

  // ���̏I���ł���";"���o�Ă���܂œǂݎ��
  while (symbol != ";") {

    // ����1�ǂݎ��
    vector<int> vec = read_vec(var_int, var_vec);

    // �L�������͂���ĂȂ��ꍇ�i���̍ŏ��̍��j�͌��ʂɂ��̂܂ܑ��
    if (symbol == "") {
      result = vec;
    }
    // �����Z�̏ꍇ
    if (symbol == "+") {
      for (int i = 0; i < result.size(); i++) {
        result.at(i) += vec.at(i);
      }
    }
    // �����Z�̏ꍇ
    if (symbol == "-") {
      for (int i = 0; i < result.size(); i++) {
        result.at(i) -= vec.at(i);
      }
    }

    // symbol�ɂ�"+", "-", ";"�̂����ꂩ�����͂����
    cin >> symbol;
  }

  return result;
}

int main() {

  // ���߂̍s�����擾
  int N;
  cin >> N;

  map<string, int> var_int; // int�̕ϐ����Ǘ�����map
  map<string, vector<int>> var_vec; // vector�̕ϐ����Ǘ�����map

  // �s�����̏���
  for (int i = 0; i < N; i++) {

    // ���߂��󂯎��
    string s;
    cin >> s;

    // int���߂̏���
    if (s == "int") {
      // �ϐ�����ǂݎ��
      string name = read_name();
      // �E�ӂ̎����v�Z���ĕϐ��ɑ��
      var_int[name] = calc_int(var_int);
    }

    // vec���߂̏���
    if (s == "vec") {
      // �ϐ�����ǂݎ��
      string name = read_name();
      // �E�ӂ̎����v�Z���ĕϐ��ɑ��
      var_vec[name] = calc_vec(var_int, var_vec);
    }

    // print_int���߂̏���
    if (s == "print_int") {
      // �����v�Z���ďo��
      cout << calc_int(var_int) << endl;
    }

    // print_vec���߂̏���
    if (s == "print_vec") {
      // �����v�Z���ďo��
      print_vec(calc_vec(var_int, var_vec));
    }
  }
}
