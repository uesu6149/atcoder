#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// ���������ǂ����𔻒肷��֐�
bool isSqrt(long long n) {
    if (n < 0) {
        return false; // ���̐��͕������ł͂Ȃ�
    }
    long long root = round(sqrt(n)); // ���������v�Z���A�ł��߂������Ɋۂ߂�
    return root * root == n; // ��悵�Č��̐��Ɠ��������m�F
}

int main() {
    int a, b;
    cin >> a >> b;

    // a��b�𕶎���ɕϊ����A��������
    string combined = to_string(a) + to_string(b);

    // ���������������long long�^�����ɕϊ�����
    long long combinedNum = stoll(combined);

    // ���������ǂ������肵�A���ʂ��o�͂���
    if (isSqrt(combinedNum)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}