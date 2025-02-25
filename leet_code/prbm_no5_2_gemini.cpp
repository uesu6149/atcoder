#include <iostream>
#include <string>
using namespace std;

// 与えられた文字列の中で最も長い回文部分文字列を見つける関数
string longestPalindrome(string s) {
    int n = s.size(), start = 0, maxLen = 1;
    if (n == 0) return ""; // 文字列が空の場合、空の文字列を返す
    bool dp[n][n] = {false}; // dp配列を初期化（全要素をfalseに設定）

    // 長さ1から始まり、文字列全体の長さまでループ
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            // 部分文字列が回文である条件をチェック
            if (s[i] == s[j] && (len < 3 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                if (len > maxLen) { // 現在の回文が最長である場合
                    start = i; // 最長回文の開始位置を更新
                    maxLen = len; // 最長回文の長さを更新
                }
            }
            if (dp[i][j]) {
              cout<<"dp["<<i<<"]["<<j<<"]"<<endl;
            }
        }
    }

    return s.substr(start, maxLen); // 最長回文部分文字列を返す
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