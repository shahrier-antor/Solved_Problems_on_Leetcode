// class Solution {
// public:
//     vector<int>twoSum( vector<int>&nums, int target){
//         unordered_map<int, int>indices_values;
//         for(int i=0; i<nums.size();i++){
//             int rest = target - nums[i];
//             if( indices_values.find(rest) != indices_values.end()){
//                 return {indices_values[rest],i};
//             }
//             else{
//                 indices_values[nums[i]] = i;
//             }
//     }
//     return {};
// }
// };



// class Solution {
// public:
//     vector<int>twoSum(vector<int>&nums, int target){
//         int high = 0;
//         unordered_map<int, int>indices;
        
//         while(high<nums.size()){
//             if(indices.find(target-nums[high])!= indices.end()) return {high, indices[target-nums[high]]};
//             else indices[nums[high]] = high;
//             high++;
//         }
//         return {};
//     }
// };





class Solution {
public:
    vector<int>twoSum(vector<int>&nums, int target){
        vector<int>answer;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }

        return answer;   
    }
};