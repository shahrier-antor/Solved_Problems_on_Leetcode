class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size(), 0), rightSum(nums.size(), 0), answer(nums.size(), 0);
        for(int i=1; i<nums.size(); i++) leftSum[i] = leftSum[i-1]+nums[i-1];
        for(int i=0; i<nums.size(); i++) cout<<leftSum[i]<<" ";
        cout<<endl;
        for(int i=nums.size()-2; i>=0; i--) rightSum[i] = rightSum[i+1]+nums[i+1];
        for(int i=0;i<nums.size();i++) cout<<rightSum[i]<< " ";
        cout<<endl;
        for(int i=0; i<nums.size(); i++) answer[i]= abs(leftSum[i] - rightSum[i]);
        return answer;        
    }
};