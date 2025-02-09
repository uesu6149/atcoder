
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        int writeIndex = 2; // 3”Ô–Ú‚Ì—v‘f‚©‚ç‘‚«ž‚Ý‚ðŠJŽn
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[writeIndex - 2]) {
            nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};