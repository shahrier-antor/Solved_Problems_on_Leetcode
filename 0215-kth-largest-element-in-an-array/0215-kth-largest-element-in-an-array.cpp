// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
        
//       priority_queue<int, vector<int>, greater<int>> pq;
//       for(auto num:nums){
//         pq.push(num);
//         if(pq.size()>k)pq.pop();
//       }
//       return pq.top();
        
//     }
// };



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        vector<int>answer(20001,0);
        for(auto num:nums){
            answer[num+10000]++;
        }
        int kthlarge;

        for(int i = answer.size()-1; i>=0; i--){
            if(answer[i]!=0) {
                kthlarge = i-10000;
                k-= answer[i];
                }
                if(k<=0) break;
        }
        return kthlarge;
        
    }
};