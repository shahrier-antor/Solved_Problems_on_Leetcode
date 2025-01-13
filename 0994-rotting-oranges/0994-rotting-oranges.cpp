class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)freshCount++;
            }
        }

        if(freshCount == 0) return 0;
        
        int minutes = 0;
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int size = q.size();
            bool flag = 0;
            for(int i = 0; i<size; i++ ){
                int rottenRow = q.front().first;
                int rottenColumn = q.front().second;
                q.pop();
                for(auto [dx,dy]:directions){
                   int mx = rottenRow + dx;
                   int ny = rottenColumn + dy;
                    if(mx>=0 && mx<m && ny>=0 && ny<n && grid[mx][ny]==1){
                        grid[mx][ny] = 2;
                        q.push({mx,ny});
                        flag = 1;
                        freshCount--;
                    }
                }

            }
            if(flag)minutes++;

        }
        return freshCount==0 ? minutes:-1;
    }
            
};