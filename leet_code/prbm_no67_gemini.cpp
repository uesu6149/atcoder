class Solution {


public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry > 0) {
            int digitA = (i >= 0) ? a[i] - '0' : 0;
            int digitB = (j >= 0) ? b[j] - '0' : 0;

            int sum = digitA + digitB + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;

            if (i >= 0) i--;
            if (j >= 0) j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }


    string addBinary2(string a, string b) {
        if (a.size() > b.size()) {
            int diff = a.size() - b.size();
            for (int i = 0; i < diff; i++) {
                b.insert(0, "0");
            }
        }
        if (a.size() < b.size()) {
            int diff = b.size() - a.size();
            for (int i = 0; i < diff; i++) {
                a.insert(0, "0");
            }
        }



        int carryOver = 0;
        string val("");

        for (int i = a.size() - 1; i >= 0; i--) {

            int val_a = a[i] == '1' ? 1 : 0;
            int val_b = b[i] == '1' ? 1 : 0;
            // cout<<"val_a:"<<val_a<<", val_b:"<<val_b<<endl;

            if (carryOver) {
                if ((val_a + val_b) == 2) {
                    carryOver = 1;
                    val.push_back('1');
                } else if ((val_a + val_b) == 1) {
                    carryOver = 1;
                    val.push_back('0');
                } else if ((val_a + val_b) == 0) {
                    carryOver = 0;
                    val.push_back('1');
                }
            } else {
                if ((val_a + val_b) == 2) {
                    carryOver = 1;
                    val.push_back('0');
                } else if ((val_a + val_b) == 1) {
                    carryOver = 0;
                    val.push_back('1');
                } else if ((val_a + val_b) == 0) {
                    carryOver = 0;
                    val.push_back('0');
                }
            }
        }

        if (carryOver) {
            val.push_back('1');
        }

        reverse(val.begin(), val.end());

        // cout<<"Val:"<<val<<endl;
        return val;
    }
};