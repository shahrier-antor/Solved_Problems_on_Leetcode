// get the shortest inteval task.
// perfrom the task - decrease freq -- freq > 0, push the task again with n interval 
// answer++, pop everyelement and decrease their interval and push again
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        
        for(char c: tasks)count[c]++;

        priority_queue<int>maxheap;
        for(auto [task, freq]: count){
            maxheap.push(freq);
        }

        queue<pair<int,int>>q;
        int time = 0;
        while(!maxheap.empty() || !q.empty()){
            time++;
            if(!maxheap.empty()){
                int current = maxheap.top();
                maxheap.pop();
                current--;
                if(current  ) q.push({current, time+n});
            }
            
            
            if(!q.empty()){
                if(q.front().second == time){
                    maxheap.push(q.front().first);
                    q.pop();
                }
            }
        }
        return time;
    }
};
