// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;

//         for(int i = 0; i<prices.size(); i++){
//             for(int j = i + 1; j<prices.size(); j++){
//                 maxProfit = max(maxProfit, prices[j] - prices[i]);
//             }
//         }
//         return maxProfit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buyingPrice = 100000;
      int answer = 0;
      for(int price: prices){
        buyingPrice = min(buyingPrice, price);
        answer = max(answer, price - buyingPrice);
      }
      return answer;
    }
};