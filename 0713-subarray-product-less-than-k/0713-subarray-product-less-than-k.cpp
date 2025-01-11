class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int low=0,high=0, count=0;
        long long products = 1; 
        while(high<nums.size())
        {
            products*=nums[high];

            while(products>=k && low<=high){
                products/=nums[low];
                low++;
            }
            count+=high-low+1;
            high++;
        }
        return count;
    }
};