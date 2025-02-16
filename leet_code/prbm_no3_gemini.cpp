class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                start = max(start, charIndexMap[s[end]] + 1);
            }
            charIndexMap[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // ハッシュマップ charIndexMap を使って、各文字とその最後の出現位置（インデックス）を記録します。
        unordered_map<char, int> charIndexMap;
        // maxLength は、これまでに見つかった最長の部分文字列の長さを格納します。
        int maxLength = 0;
        // start は、現在の部分文字列の開始位置（インデックス）を格納します。
        int start = 0;

        // 文字列 s を end インデックスで走査します。
        for (int end = 0; end < s.length(); ++end) {
            // 現在の文字 s[end] が charIndexMap に存在するかどうかを確認します。
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                // もし s[end] が既に存在する場合、
                // start を、以前の s[end] の位置の次の文字まで進めます。
                // これは、重複する文字が部分文字列に含まれないようにするためです。
                // max(start, charIndexMap[s[end]] + 1) は、
                // start が以前の s[end] の位置よりも前にあった場合に、
                // start が更新されないようにします。
                start = max(start, charIndexMap[s[end]] + 1);
            }
            // 現在の文字 s[end] の位置を charIndexMap に記録します。
            // もし s[end] が既に存在する場合は、その位置が更新されます。
            charIndexMap[s[end]] = end;
            // 現在の部分文字列の長さを計算し、maxLength を更新します。
            maxLength = max(maxLength, end - start + 1);
        }

        // 最長の部分文字列の長さを返します。
        return maxLength;
    }
};