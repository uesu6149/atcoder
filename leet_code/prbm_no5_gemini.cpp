はい、C++での回文探索のサンプルコードを提供します。

C++

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < s.length(); ++i) {
        // 奇数長の回文を探索
        int left = i;
        int right = i;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            --left;
            ++right;
        }

        // 偶数長の回文を探索
        left = i;
        right = i + 1;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            --left;
            ++right;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s1 = "babad";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << longestPalindrome(s2) << endl;

    return 0;
}