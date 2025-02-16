class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        
        for (int i = 0; i < prices.size()-1; i++) {
            if (prices.at(i) < prices.at(i+1)) {
                maxP += prices.at(i+1) - prices.at(i);
            }
        }
        return maxP;
    }
};