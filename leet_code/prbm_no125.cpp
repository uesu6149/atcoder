class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (left < right && tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool isPalindrome1(string s) {

        if (s.size() <= 1) {
            return true;
        }

        int j = s.size() - 1;
        for (int i = 0; i < s.size();) {
            if (i >= j) {
                return true;
            }
            char tmp_a = s[i];
            char tmp_b = s[j];

			if (isalnum(tmp_a) > 0) {
                tmp_a = tolower(tmp_a);
            } else {
                i++;
                continue;
            }

            if (isalnum(tmp_b) > 0) {
                tmp_b = tolower(tmp_b);
            } else {
                j--;
                continue;
            }
            if (tmp_a != tmp_b) {
                break;
            }
            i++;
            j--;
        }
        return false;
    }

    bool isPalindrome2(string s) {

        if (s.empty() || s.size() == 1)
            return true;

        vector<char> vec;
        for (int i = 0; i < s.size(); i++) {
            // cout<<s[i]<< " -> " << isalpha(s[i])<<endl;
            if (isalpha(s[i]) > 0 || isalnum(s[i]) > 0) {
                vec.push_back(tolower(s[i]));
            }
        }
        cout << vec.size() << endl;
        if (vec.size() <= 1) {
            return true;
        }

        int j = vec.size() - 1;
        for (int i = 0; i < vec.size(); i++, j--) {
            if (i >= j) {
                return true;
            }
            if (vec[i] != vec[j]) {
                break;
            }
        }

        return false;
    }
};