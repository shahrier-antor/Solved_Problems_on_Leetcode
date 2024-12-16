
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
     