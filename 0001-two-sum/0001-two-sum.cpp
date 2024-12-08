class Solution {
public:
    vector<int>twoSum( vector<int>&nums, int target){
        unordered_map<int, int>indices_values;
        for(int i=0; i<nums.size();i++){
            int rest = target - nums[i];
            if( indices_values.find(rest) != indices_values.end()){
                return {indices_values[rest],i};
            }
            else{
                indices_values[nums[i]] = i;
            }
    }
    return {};
}


};