class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
    int majorityElement2(vector<int>& nums) {
        map<int, int> m;

        for (auto it = nums.begin(); it != nums.end(); it++) {
            int elem = (*it);
            if (m.find(elem) != m.end()) {
                // elem‚ÍŠù‚É‚ ‚éI
                m[elem]++;
            } else {
                m[elem] = 1;
            }
        }

        // Get maximum
        int maxVal = 0;
        int maxNum = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > maxVal) {
                maxNum = it->first;
                maxVal = it->second;
            }
        }
        return maxNum;
    }
};