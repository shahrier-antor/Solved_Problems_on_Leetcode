class Solution {   
public:
    int subarraySum(vector<int>& nums, int k) {
        int high = 0, sum = 0, count=0;
        unordered_map<int,int>h_map;

        while(high<nums.size()){
            sum+=nums[high];
            if(sum == k) count++;
            count+= h_map[sum-k];
            h_map[sum]++;
            high++;
        }
        return count;
    }
};