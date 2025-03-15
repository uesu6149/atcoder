class Solution {
public:
    // Time Limit‚·‚¤‚’
    int longestConsecutive_gemini(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        std::unordered_set<int> num_set(nums.begin(), nums.end()); // O(n)
        int longest_streak = 0;

        for (int num : nums) {                            // O(n)
            if (num_set.find(num - 1) == num_set.end()) { // O(1)
                int current_num = num;
                int current_streak = 1;

                while (num_set.find(current_num + 1) !=
                       num_set.end()) { // Åˆ«‚Ìê‡O(n)‚¾‚ªA‘S‘Ì‚Å‚ÍO(n)
                    current_num++;
                    current_streak++;
                }

                longest_streak =
                    std::max(longest_streak, current_streak); // O(1)
            }
        }

        return longest_streak;
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int consecive = 0;
        int currentNum = 1;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i - 1] == (nums[i] - 1)) {
                //     printf("1: %d,%d\n",nums[i-1],nums[i]);
                currentNum++;
            } else if (nums[i - 1] == (nums[i])) {

            } else {
                //      printf("2: %d,%d\n",nums[i-1],nums[i]);

                consecive = max(consecive, currentNum);
                currentNum = 1;
            }
        }

        consecive = max(consecive, currentNum);

        return consecive;
    }
};