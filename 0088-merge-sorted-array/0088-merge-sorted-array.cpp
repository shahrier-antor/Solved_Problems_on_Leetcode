class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last1 = m-1, last2 = n-1;
        int index = nums1.size()-1;
        while(last1 >=0 && last2 >=0){
            if(nums1[last1]>nums2[last2]){
                nums1[index--] = nums1[last1--];
            }
            else if(nums1[last1]<nums2[last2]){
                nums1[index--] = nums2[last2--];
            }
            else{
                nums1[index--] = nums2[last2--];
                nums1[index--] = nums1[last1--];
            } 
        }
        if(last1<0){
            while(last2>=0){
                nums1[index--] = nums2[last2--];
            }
        } 
        if(last2<0){
            while(last1>=0){
                nums1[index--] = nums1[last1--];
            }
        }     
  
    }
};