class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Remove more than 3 appears 
        int totals = nums.size();
        int duplicated = 0;
        int nums_size = nums.size();

        // 2�ȉ��̏ꍇ�́A�ύX�͂Ȃ��̂ŁA�z�񐔂͂��̂܂܂���
        if (nums.size() < 3)
            return nums.size();

        if (nums.at(0) == nums.at(1))
            duplicated = 1;

        // i2����n�߂��
        for (int i = 2; i < totals; i++) {
            
                // (i��i+1)�ƃt���b�O���r���āA�����ł���΁A�l���ړ����鏈��������
                if ( (nums.at(i) == nums.at(i-1))) {
                    if (duplicated) {
                        //printf("�d��: [%d]:%d = [%d]:%d, flag:%d\n", i-1, nums.at(i-1), i, nums.at(i), duplicated);
                        // �ق��̏d�����m�F���郋�[�v
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
                    // �l���d�����Ȃ��̂ŁA�t���b�O�����Z�b�g����
                    duplicated = 0;
                }
                
                
            
        }
      //  cout<<"Totals:"<<totals;
        return totals;
    }
};