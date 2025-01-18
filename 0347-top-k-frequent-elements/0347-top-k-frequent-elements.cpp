
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         unordered_map<int,int>h_map;
//         vector<int>answer;
//         vector<queue<int>>bucket(nums.size()+1);

//         for(int i : nums)h_map[i]++;

//         for(auto& [key,freq]: h_map){
//             bucket[freq].push(key);
//         }

//         for(int i = bucket.size()-1; i>=0 && answer.size()<k ; i--){

//             while(!bucket[i].empty() && answer.size()<k)
//             {
//                 answer.push_back(bucket[i].front());
//                 bucket[i].pop();
//             }
//         }



//         return answer; 
//     }
// };








class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>h_map;
     for(auto num:nums)h_map[num]++;

     vector<queue<int>> topk(nums.size()+1);

     for(auto [num, freq]: h_map){
        topk[freq].push(num);
     }

     vector<int>answer;
     for(int i = topk.size()-1; i>=0; i--){
        if(!topk[i].empty()){
            while(!topk[i].empty() && answer.size()<k){
                answer.push_back(topk[i].front());
                topk[i].pop();
            }
        }
        if(answer.size()==k)break;  
     }

     return answer;
    }
     
};