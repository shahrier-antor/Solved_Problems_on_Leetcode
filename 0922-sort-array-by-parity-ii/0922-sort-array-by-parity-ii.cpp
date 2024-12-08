class Solution {
public:
    vector<int>sortArrayByParityII (vector<int>&nums){
        int j = 1;
        for(int i =0; i<nums.size(); i+=2){
            if (nums[i] % 2 != 0){

                while(j < nums.size()){
                if( nums[j] % 2 == 0) break;
                else j+=2;
                }
            swap ( nums[i], nums[j]);
            }
        }
    return nums;
}
};