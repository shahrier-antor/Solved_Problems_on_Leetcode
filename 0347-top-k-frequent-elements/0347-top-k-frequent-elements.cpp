class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>h_map;
        priority_queue<pair<int,int>>pq;
        vector<int>answer;
        for(int i:nums){
            h_map[i]++;
        }
        for(auto& [key,value]:h_map){
            pq.push({value,key});
        }
        
        while(k-- > 0){
            auto key = pq.top();
            answer.push_back(key.second);
            pq.pop();
        }

        return answer;

    
    }
};