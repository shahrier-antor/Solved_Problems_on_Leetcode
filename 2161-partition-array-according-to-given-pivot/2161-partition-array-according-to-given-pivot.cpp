class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less=0, greater = 0, equal = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot) less++;
            else if (nums[i] > pivot) greater++;
            else equal++;
        }
        vector<int>results(nums.size(),0);
        for(int i=0; i<equal; i++){
            results[less++] = pivot;
        }
        int low=0, high = less;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                results[low++] = nums[i];
            }
            else if(nums[i]>pivot){
                results[high++] = nums[i];
            }
            else continue;
        }
    return results;
    }

};