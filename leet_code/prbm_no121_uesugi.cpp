class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 1)
            return 0;

        // Get first buy day
        int buyIdx = 0;
        int profit = 0;
        for (int i = buyIdx; i < prices.size()-1; i++) {
            // buyIdxの値がとprices[i]を比較して、prices[i]が低い場合、更新する
            if (prices[i] < prices[buyIdx]) {
                buyIdx = i;
            }
            int gain = prices[i+1] - prices[buyIdx];
            if (gain > profit) {
                profit = gain;
            }
        }
        return profit;
    }
};