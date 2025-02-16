#include <bits/stdc++.h>
using namespace std;

// �ȉ��ɁA24���ԕ\�L�̎��v�\���� Clock ���`����

// Clock�\���̂̃����o�ϐ�������
//   int hour    ���Ԃ�\�� (0~23�̒l���Ƃ�)
//   int minute  ����\��   (0~59�̒l���Ƃ�)
//   int second  �b��\��   (0~59�̒l���Ƃ�)

// �����o�֐� set �̒�`������
//   �֐���: set
//   ����: int h, int m, int s (���ꂼ�ꎞ�A���A�b��\��)
//   �Ԃ�l: �Ȃ�
//   �֐��̐���:
//     ���E���E�b��\��3�̈������󂯎��A
//     ���ꂼ��A�����o�ϐ� hour, minute, second �ɑ������

// �����o�֐� to_str �̒�`������
//   �֐���: to_str
//   ����: �Ȃ�
//   �Ԃ�l: string�^
//   �֐��̎d�l:
//     �����o�ϐ����\�������̕������Ԃ�
//     �����̕�����͎��̃t�H�[�}�b�g
//     "HH:MM:SS"
//     HH�AMM�ASS�͂��ꂼ�ꎞ�ԁA���A�b��2���ŕ\����������

// �����o�֐� shift �̒�`������
//   �֐���: shift
//   ����: int diff_second
//   �Ԃ�l: �Ȃ�
//   �֐��̎d�l:
//     diff_second �b���������o�ϐ����\��������ύX����(�������A���t�₤�邤�b�͍l���Ȃ�)
//     diff_second �̒l�����̏ꍇ�A������߂�
//     diff_second �̒l�����̏ꍇ�A������i�߂�
//     diff_second �̒l�� -86400 ~ 86400 �͈̔͂���Ƃ肤��

struct Clock {
  int hour;
  int minute;
  int second;
  
  void set(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
  }
  
  std::string to_str() const {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hour << ":"
       << std::setw(2) << std::setfill('0') << minute << ":"
       << std::setw(2) << std::setfill('0') << second;
    return ss.str();
  }
  
  void shift(int diff_second) {
    // ���݂̎�����b�P�ʂɕϊ�
    int total_seconds = hour * 3600 + minute * 60 + second;

    // ������ύX
    total_seconds += diff_second;

    // �͈͓��ɒ��� (24���Ԑ�)
    total_seconds %= 86400; // 86400�b = 24����
    if (total_seconds < 0) {
      total_seconds += 86400;
    }

    // ���A���A�b�ɕ���
    hour = total_seconds / 3600;
    minute = (total_seconds % 3600) / 60;
    second = total_seconds % 60;
  }

};
// -------------------
// ���������͕ύX���Ȃ�
// -------------------

int main() {
  // ���͂��󂯎��
  int hour, minute, second;
  cin >> hour >> minute >> second;
  int diff_second;
  cin >> diff_second;

  // Clock�\���̂̃I�u�W�F�N�g��錾
  Clock clock;

  // set�֐����Ăяo���Ď�����ݒ肷��
  clock.set(hour, minute, second);

  // �������o��
  cout << clock.to_str() << endl;

  // ���v��i�߂�(�߂�)
  clock.shift(diff_second);

  // �ύX��̎������o��
  cout << clock.to_str() << endl;
}
