class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }

        int start = nums[0];
        for (int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" +
                                     to_string(nums[i - 1]));
                }
                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }
        return result;
    }

    vector<string> summaryRanges2(vector<int>& nums) {

        vector<string> v;
        if (nums.empty()) {
            return v;
        }
        if (nums.size() == 1) {
            stringstream ss;
            ss << nums[0];
            v.push_back(ss.str());
            return v;
        }

        int startVal = nums[0];
        int ranges = 1;
        for (int i = 1; i < nums.size(); i++) {

            printf("nums[%d]:%d, ranges:%d, startVal:%d\n", i, nums[i], ranges,
                   startVal);
            // 連続性があるかを確認
            if (nums[i - 1] != (nums[i] - 1)) {
                // もし連続性が切れたら、startValを更新
                if (ranges == 1) {
                    stringstream ss;
                    ss << startVal;
                    v.push_back(ss.str());
                    cout << "push_back:" << ss.str() << endl;
                } else {
                    stringstream ss;
                    ss << startVal << "->" << nums[i - 1];
                    v.push_back(ss.str());
                    cout << "push_back:" << ss.str() << endl;
                }
                startVal = nums[i];
                ranges = 1;
            } else {
                ranges++;
            }
        }

        // 最後の範囲を処理
        if (ranges == 1) {
            stringstream ss;
            ss << startVal;
            v.push_back(ss.str());
        } else {
            stringstream ss;
            ss << startVal << "->" << nums.back();
            v.push_back(ss.str());
        }

        return v;
    }
};