// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         unordered_map<int,int>h_map;
//         priority_queue<pair<int,int>>pq;
//         vector<int>answer;
//         for(int i:nums){
//             h_map[i]++;
//         }
//         for(auto& [key,value]:h_map){
//             pq.push({value,key});
//         }
        
//         while(k-- > 0){
//             int key = pq.top().second;
//             answer.push_back(key);
//             pq.pop();
//         }

//         return answer;

    
//     }
// };

// 2 -- 3
// 3 -- 3

// 3
// {2,3}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>h_map;
        vector<int>answer;
        vector<queue<int>>bucket(nums.size()+1);

        for(int i : nums)h_map[i]++;

        for(auto& [key,freq]: h_map){
            bucket[freq].push(key);
        }

        for(int i = bucket.size()-1; i>=0 && answer.size()<k ; i--){

            while(!bucket[i].empty() && answer.size()<k)
            {
                answer.push_back(bucket[i].front());
                bucket[i].pop();
            }
        }

        

        return answer; 
    }
};