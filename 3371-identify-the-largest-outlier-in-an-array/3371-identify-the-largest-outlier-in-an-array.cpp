class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size(), sum = 0; 
        map<int,int>h_map;
        int answer = INT_MIN;
        for(auto num:nums){
            sum+=num;
            h_map[num*2]++;
        }
        for(auto num:nums){
            int temp = sum - num;
            if(h_map.find(temp)!= h_map.end()){
                if(num*2 == temp){
                    if(h_map[temp]>1)answer = max(answer, num);
                }
                else answer = max(answer, num);
            }
        }
        return answer;
    }
};