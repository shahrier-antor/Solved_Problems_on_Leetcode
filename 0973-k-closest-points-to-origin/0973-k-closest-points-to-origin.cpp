class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair <int, pair<int,int>> > max_heap;
        vector<vector<int>>result;
        for(auto point:points){
            int dist = point[0]*point[0] + point[1]*point[1];
            max_heap.push({dist,{point[0],point[1]}});
            if(max_heap.size()>k)max_heap.pop();
        }
        while(!max_heap.empty()){
            auto point = max_heap.top().second;
            result.push_back({point.first, point.second});
            max_heap.pop();
        }

        return result;
    }
};