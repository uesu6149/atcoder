class Solution {
public:
    bool isPalindrome(int x) {
        // ���̐��A����і�����0��0�łȂ����͉񕶂ł͂Ȃ�
        // (��: -121, 10, 120)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // ���]���������l���i�[����ϐ�
        int reversedX = 0;

        // ���l�𔼕��������]������
        // (��: 12321 -> 123, 121 -> 12)
        while (x > reversedX) {
            // �Ō�̌������o��
            reversedX = reversedX * 10 + x % 10;

            // �Ō�̌����폜
            x /= 10;
        }

        // �񕶔���
        // ���̐��l���������̏ꍇ: x == reversedX
        // ���̐��l������̏ꍇ: x == reversedX / 10
        // (��: 12321�̏ꍇ�A���[�v�� x = 12, reversedX = 123 �ƂȂ�Ax ==
        // reversedX / 10 �Ŕ���) (��: 121�̏ꍇ�A���[�v�� x = 1, reversedX = 1
        // �ƂȂ�Ax == reversedX �Ŕ���)
        return x == reversedX || x == reversedX / 10;
    }

    bool isPalindrome2(int x) {
        // �}�C�i�X�̏ꍇ�́A���ׂ�False
        if (x < 0) {
            return false;
        }
        int originalX = x;
        unsigned int reverseX = 0;

        // ���͔��]��������
        while (x > 0) {
            int digit = x % 10;
            reverseX = reverseX * 10 + digit;
            x = x / 10;
        }
        // ���]�ƌ��̐�����������
        return (originalX == reverseX);
    }
};