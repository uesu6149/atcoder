class Solution {
public:
    void divideDigit(vector<int>& digits, int n) {
        digits.clear();

        int digit = 0;
        while (n > 0) {
            digit = n % 10;
            digits.push_back(digit);
            n = n / 10;
        }
    }

    bool isHappy(int n) {

        unordered_map<int, int> isRepeat;
        vector<int> digits;
        divideDigit(digits, n);

        int total = 0;
        while (true) {
            divideDigit(digits, n);
            total = 0;

            for (int i = 0; i < digits.size(); i++) {
                total += (digits[i] * digits[i]);
                 //printf("%d,",total);
            }
            // printf("\n");
            if (total == 1) {
                return true;
            }

            if (isRepeat.count(total)) {
                return false;
            }
            // total‚ðMap‚É’Ç‰Á
            isRepeat[total] = 0;

            n = total;
        }

        return false;
    }

    bool isHappy2(int n) {
        std::unordered_set<int> seen;
        // n‚ªmap‚É“à‚ðŠm”F‚·‚é
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};