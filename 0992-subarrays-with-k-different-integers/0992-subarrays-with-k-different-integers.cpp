class Solution{

public:
    int subarraysWithKDistinct(vector<int> &nums, int k){
        return subArraysWithAtMostKDistinct(nums, k) - subArraysWithAtMostKDistinct(nums, k-1);
    }
private:
    int subArraysWithAtMostKDistinct(vector<int>&nums, int k){
        int high = 0,low = 0,count = 0;
        map<int,int>h_map;

        while(high<nums.size()){
            h_map[nums[high]]++;
          

            while(h_map.size()>k){
                h_map[nums[low]]--;
                if(h_map[nums[low]] == 0){
                    h_map.erase(nums[low]);
                }
                low++;
            }
            count = count+high-low; 
            high++;
        }
        return count;
    }

};
