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

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//       int buyingPrice = prices[0];
//       int answer = 0;
//       for(int price: prices){
//         buyingPrice = min(buyingPrice, price);
//         answer = max(answer, price - buyingPrice);
//       }
//       return answer;
//     }
// };



class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buy = prices[0], maxprofit = INT_MIN;
      int high = 1;
      
      while(high<prices.size()){
        maxprofit = max(maxprofit,prices[high]-buy);
        buy = min(buy, prices[high]);
        high++;
      }
      return max(maxprofit,0);
    }
};