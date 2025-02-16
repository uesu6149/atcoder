class Solution {
public:
    bool isPalindrome(int x) {
        // 負の数、および末尾が0で0でない数は回文ではない
        // (例: -121, 10, 120)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // 反転させた数値を格納する変数
        int reversedX = 0;

        // 数値を半分だけ反転させる
        // (例: 12321 -> 123, 121 -> 12)
        while (x > reversedX) {
            // 最後の桁を取り出す
            reversedX = reversedX * 10 + x % 10;

            // 最後の桁を削除
            x /= 10;
        }

        // 回文判定
        // 元の数値が偶数桁の場合: x == reversedX
        // 元の数値が奇数桁の場合: x == reversedX / 10
        // (例: 12321の場合、ループ後 x = 12, reversedX = 123 となり、x ==
        // reversedX / 10 で判定) (例: 121の場合、ループ後 x = 1, reversedX = 1
        // となり、x == reversedX で判定)
        return x == reversedX || x == reversedX / 10;
    }

    bool isPalindrome2(int x) {
        // マイナスの場合は、すべてFalse
        if (x < 0) {
            return false;
        }
        int originalX = x;
        unsigned int reverseX = 0;

        // 数は反転さえっる
        while (x > 0) {
            int digit = x % 10;
            reverseX = reverseX * 10 + digit;
            x = x / 10;
        }
        // 反転と元の数字が同じか
        return (originalX == reverseX);
    }
};