// class Solution {
// public:
//     void rotate(vector<int>&nums, int k){
//         vector<int>rotated(nums.size(), 0);
//         for(int i = 0; i<nums.size(); i++){
//             rotated[(i+k) % nums.size()] = nums[i];
//         }
//     nums = rotated;
//     }
// };


class Solution {
public:
    void rotate(vector<int>&nums, int k){
        k%=nums.size();
        reverse(nums.begin(), nums.end());
        // reverse first k element 
        reverse(nums.begin(),nums.begin() + k);
        // reverse the elements after kth element 
        reverse(nums.begin() + k, nums.end());
    }
    
};