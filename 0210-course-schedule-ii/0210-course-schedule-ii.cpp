class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>graph[n];
        for(auto prerequisite : prerequisites){
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
       
        vector<int>InDegree(n,0);

        for(int i =0; i<n; i++){
            for(auto d : graph[i])InDegree[d]++;
        }


        queue<int>q;

        for(int i = 0; i<n; i++) {
            if(InDegree[i]==0)q.push(i);
        }
        vector<int>answer;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            answer.push_back(current);
            for(auto x: graph[current]){
                InDegree[x]--;
                if(InDegree[x]==0)q.push(x);
            } 
        }
        if(answer.size()==n) return answer;
        return {};
        
    }
};