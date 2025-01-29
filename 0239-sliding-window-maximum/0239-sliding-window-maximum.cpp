class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>maxwindow;
        int left = 0;
        int right = k-1;
        priority_queue<pair<int,int>>max_heap;
        for(int i = 0; i<k-1; i++)max_heap.push({nums[i],i});
        while(right<nums.size()){

            max_heap.push({nums[right], right});
            while(max_heap.top().second<left && !max_heap.empty())max_heap.pop();
            maxwindow.push_back(max_heap.top().first);
            left++;
            right++;

        }
        return maxwindow;
    }
};