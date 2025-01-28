class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit  = 0;
        int buying_price = prices[0];

        for(int i = 1; i<prices.size(); i++){
            if(prices[i]<=buying_price) buying_price = prices[i];
            else {
                max_profit += prices[i] - buying_price;
                buying_price = prices[i];
            }
        }
        return max_profit;
    }
};