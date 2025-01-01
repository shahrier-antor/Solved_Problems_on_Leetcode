class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>productArray(nums.size(),1);
        productArray[0] = nums[0];
        for(int i = 1; i<nums.size(); i++) productArray[i] = nums[i]*productArray[i-1];
        int temp = nums[nums.size()-1];
        productArray[nums.size()-1] = productArray[nums.size()-2];
        for(int i = nums.size()-3; i>=0; i--){
            productArray[i+1] = productArray[i] * temp;
            temp *= nums[i+1];
        }
        productArray[0] = temp;
        return productArray;
    }
};