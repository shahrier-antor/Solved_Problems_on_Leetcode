class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int swap_index = -1;
        for(int i = n-2; i>=0; i--){
             if(nums[i]<nums[i+1]){
                swap_index = i;
                break;
             }
        }
        if(swap_index == -1) {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(int i = n-1; i>=0; i--){
                if(nums[i] > nums[swap_index])
                {
                    swap (nums[i], nums[swap_index]);
                    break;
                }
            }
            reverse(nums.begin()+swap_index+1, nums.end());
        }
        
        
    }
};