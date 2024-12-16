// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//         for(int i = 1; i<arr.size(); i++)
//         {
//             arr[i]+=arr[i-1];
//         }
//         int left = 0, right = k-1;
//         int count = 0;
//         while(right<arr.size()){
//             int sum; 
//             if(left == 0){
//                 sum = arr[right];
//             }
//             else {
//                 sum = arr[right] - arr[left-1];
//             }
//             if(sum>= k* threshold) count++;
//             left++;
//             right++;
//         }
//         return count;	
//     }
// };


class Solution {
    // T:O(N),S: O(1)
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0, right = k-1;
        int sum = 0, count = 0;
        for(int i = 0; i<k; i++)sum+=arr[i];
        while(right<arr.size()){

            if(sum>= threshold*k)count++;
            sum-=arr[left];
            left++;
            right++;
            if(right<arr.size())sum+=arr[right];
        }
        return count;
    }
};
