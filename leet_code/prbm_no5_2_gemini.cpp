#include <iostream>
#include <string>
using namespace std;

// �^����ꂽ������̒��ōł������񕶕����������������֐�
string longestPalindrome(string s) {
    int n = s.size(), start = 0, maxLen = 1;
    if (n == 0) return ""; // �����񂪋�̏ꍇ�A��̕������Ԃ�
    bool dp[n][n] = {false}; // dp�z����������i�S�v�f��false�ɐݒ�j

    // ����1����n�܂�A������S�̂̒����܂Ń��[�v
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            // ���������񂪉񕶂ł���������`�F�b�N
            if (s[i] == s[j] && (len < 3 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (len > maxLen) { // ���݂̉񕶂��Œ��ł���ꍇ
                    start = i; // �Œ��񕶂̊J�n�ʒu���X�V
                    maxLen = len; // �Œ��񕶂̒������X�V
                }
            }
            if (dp[i][j]) {
              cout<<"dp["<<i<<"]["<<j<<"]"<<endl;
            }
        }
    }

    return s.substr(start, maxLen); // �Œ��񕶕����������Ԃ�
}

int main() {
    string s1 = "babad";
    string s2 = "cbbd";

    cout << "Input: " << s1 << endl;
    cout << "Output: " << longestPalindrome(s1) << endl;

    cout << "Input: " << s2 << endl;
    cout << "Output: " << longestPalindrome(s2) << endl;

    return 0;
}