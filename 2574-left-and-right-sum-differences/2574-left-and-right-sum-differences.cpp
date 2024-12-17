class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size(), 0), rightSum(nums.size(), 0), answer(nums.size(), 0);
        int totalSum = 0;
        for(int i = 0; i<nums.size();i++)totalSum += nums[i];
        for(int i=1; i<nums.size(); i++) answer[i] = answer[i-1]+nums[i-1];
        for(int i = 0; i<nums.size();i++){
            int sum = totalSum;
            sum-=answer[i];
            sum-=nums[i];
            answer[i] = abs(answer[i]-sum);
        }
        //for(int i=nums.size()-2; i>=0; i--) rightSum[i] = rightSum[i+1]+nums[i+1];
        //for(int i=0; i<nums.size(); i++) answer[i]= abs(leftSum[i] - rightSum[i]);
        return answer;        
    }
};