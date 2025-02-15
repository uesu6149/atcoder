#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 平方数かどうかを判定する関数
bool isSqrt(long long n) {
    if (n < 0) {
        return false; // 負の数は平方数ではない
    }
    long long root = round(sqrt(n)); // 平方根を計算し、最も近い整数に丸める
    return root * root == n; // 二乗して元の数と等しいか確認
}

int main() {
    int a, b;
    cin >> a >> b;

    // aとbを文字列に変換し、結合する
    string combined = to_string(a) + to_string(b);

    // 結合した文字列をlong long型整数に変換する
    long long combinedNum = stoll(combined);

    // 平方数かどうか判定し、結果を出力する
    if (isSqrt(combinedNum)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}