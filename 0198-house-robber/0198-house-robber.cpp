class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>max_loot(nums.size(), 0);
        max_loot[0] = nums[0];
        max_loot[1] = max(nums[1], nums[0]);

        for(int i = 2; i<nums.size(); i++){
            max_loot[i] = max(max_loot[i-2] + nums[i], max_loot[i-1]);
        }
        return max_loot[nums.size()-1];
    }
};