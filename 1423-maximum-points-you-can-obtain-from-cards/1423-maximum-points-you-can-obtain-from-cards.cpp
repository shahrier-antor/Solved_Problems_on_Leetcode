// class Solution {
// public:
// // T: O(n), S: O(n)
//     int maxScore(vector<int>& cardPoints, int k) {

//         vector<int>preSum(cardPoints.size(),0);
//         vector<int>suffSum(cardPoints.size(),0);

//         preSum[0] = cardPoints[0];
//         for(int i = 1; i<cardPoints.size(); i++)preSum[i] = preSum[i-1] + cardPoints[i];

//         suffSum[0] = cardPoints[cardPoints.size()-1];
//         int l = 1;
//         for(int i = cardPoints.size()-2; i>=0; i--){
//             suffSum[l] = suffSum[l-1] + cardPoints[i];
//             l++;
//         }
//         int maxPoint = 0;
//         int preValue = k-1;
//         int suffValue = -1;
//         while(preValue>=-1){
//             int sum = 0;
//             if(preValue>=0)  sum+=preSum[preValue];
//             if(suffValue>=0) sum+= suffSum[suffValue];
//             maxPoint = max(maxPoint, sum);
//             suffValue++;
//             preValue--;
//         }
//         return maxPoint;
//     }
// };



class Solution {
public:
// T: O(n), S: O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int maximum = 0;
        for(int i = cardPoints.size()- k; i<cardPoints.size(); i++) maximum+=cardPoints[i];

        int left = 0, right = cardPoints.size()-k;
        int sum = maximum;
        
        while(right<cardPoints.size()){
            sum += cardPoints[left];
            sum -= cardPoints[right];
            maximum = max(maximum, sum);
            left++;
            right++;
        }
        return maximum;
    }
};
     