class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>>graph(rooms.size());
        
        for(int i =0; i<rooms.size(); i++){
            for(auto room : rooms[i]){
                graph[i].push_back(room);
            }   
        }

        queue<int>bfs;
        bfs.push(0);
        vector<int>answer;
        vector<int>visited(rooms.size(),0);
        visited[0]=1;
        while(!bfs.empty()){
            int current = bfs.front();
            bfs.pop();
            answer.push_back(current);
            for(auto room: graph[current]){
                if(!visited[room]) {
                    bfs.push(room);
                    visited[room]=1;
                    }
            }
        }
        return answer.size()==rooms.size();
    }
    
};