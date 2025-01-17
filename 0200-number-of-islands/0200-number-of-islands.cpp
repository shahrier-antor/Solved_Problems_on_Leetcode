class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i =0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    queue<pair<int,int>>bfs;
                    bfs.push({i,j});
                    while(!bfs.empty()){
                        auto current = bfs.front();
                        bfs.pop();
                        for(auto direction:directions){
                            int dx = current.first + direction.first;
                            int dy = current.second + direction.second;
                            if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]=='1'){
                                grid[dx][dy]='0';
                                bfs.push({dx,dy});
                            }
                        }
                    }
                    islands++;
                }
            }
        }

        return islands;
        
    }
};