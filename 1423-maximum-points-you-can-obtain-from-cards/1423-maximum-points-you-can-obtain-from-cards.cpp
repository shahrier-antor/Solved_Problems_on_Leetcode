class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        vector<int>preSum(cardPoints.size(),0);
        vector<int>suffSum(cardPoints.size(),0);

        preSum[0] = cardPoints[0];
        for(int i = 1; i<cardPoints.size(); i++)preSum[i] = preSum[i-1] + cardPoints[i];

        suffSum[0] = cardPoints[cardPoints.size()-1];
        int l = 1;
        for(int i = cardPoints.size()-2; i>=0; i--){
            suffSum[l] = suffSum[l-1] + cardPoints[i];
            l++;
        }
        // for(int i = 0; i<cardPoints.size(); i++)cout<< preSum[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i<cardPoints.size(); i++)cout<< suffSum[i]<<" ";
        // cout<<endl;

        int maxPoint = 0;
        int preValue = k-1;
        int suffValue = -1;
        while(preValue>=-1){
            int sum = 0;
            if(preValue>=0)  sum+=preSum[preValue];
            if(suffValue>=0) sum+= suffSum[suffValue];
            maxPoint = max(maxPoint, sum);
            //cout<<preValue<< " " << suffValue<< " " << sum << " " << maxPoint<<endl;
            suffValue++;
            preValue--;
        }
        return maxPoint;
    }
};