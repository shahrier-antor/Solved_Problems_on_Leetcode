// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         vector<vector<int>>answer;

//         for(auto interval:intervals){
//             if(answer.empty() || answer[answer.size()-1][1] <interval[0]){
//                 answer.push_back(interval);
//             }
//             else{
//                 answer[answer.size()-1][1] = max(answer[answer.size()-1][1], interval[1] );
//             }
//         }


//         return answer;
//     }
// };




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if(intervals.size()==1)return intervals;
       sort(intervals.begin(), intervals.end());
       int low = intervals[0][0], high = intervals[0][1];
       vector<vector<int>>answer;
       
       for(int i = 1; i< intervals.size(); i++){
            if(intervals[i][0]<=high) high = max(high,intervals[i][1]);
            else{
                answer.push_back({low,high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
       }
       
       answer.push_back({low,high});
       return answer;
    }
};