
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        int writeIndex = 2; // 3�Ԗڂ̗v�f���珑�����݂��J�n
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[writeIndex - 2]) {
            nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};