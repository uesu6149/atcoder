class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Remove more than 3 appears 
        int totals = nums.size();
        int duplicated = 0;
        int nums_size = nums.size();

        // 2以下の場合は、変更はないので、配列数はそのままだよ
        if (nums.size() < 3)
            return nums.size();

        if (nums.at(0) == nums.at(1))
            duplicated = 1;

        // i2から始めるよ
        for (int i = 2; i < totals; i++) {
            
                // (iとi+1)とフラッグを比較して、同じであれば、値を移動する処理をする
                if ( (nums.at(i) == nums.at(i-1))) {
                    if (duplicated) {
                        //printf("重複: [%d]:%d = [%d]:%d, flag:%d\n", i-1, nums.at(i-1), i, nums.at(i), duplicated);
                        // ほかの重複を確認するループ
                        int dup_num = 1;
                        for (int j = i+1; j < totals; j++) {
                            if (j < nums.size()) {
                                if (nums.at(i) == nums.at(j)) {
                                    dup_num++;
                                }
                           }
                        }

                       for (int j = i; j < (nums.size()-dup_num); j++) {
                            nums.at(j) = nums.at(j+dup_num);
                        }
                        totals -= dup_num;
                       // printf("dup_num:%d\n",dup_num);
                        duplicated = 0;
                    }
                    else {
                        duplicated = 1;
                    }
                }
                else {
                    // 値が重複しないので、フラッグをリセットする
                    duplicated = 0;
                }
                
                
            
        }
      //  cout<<"Totals:"<<totals;
        return totals;
    }
};