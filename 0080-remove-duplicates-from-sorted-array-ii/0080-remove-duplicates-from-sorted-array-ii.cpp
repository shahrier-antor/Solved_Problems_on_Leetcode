class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int high = 0;
        while(1){
            if(high == nums.size()){
                break;
            }
            else if(low==high){
                high++;
            }
            else if(nums[high] == nums[low])
            {
                if(high - low == 1)
                {
                    high++;
                }
                else if(high-low>1)
                {
                    nums.erase(nums.begin() + high);
                }
            }
            else if( nums[high] != nums[low])
            {
                low=high;
            }
        }
    return nums.size();
    }
};