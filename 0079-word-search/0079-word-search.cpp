class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, vector<vector<int>> &visited, int i, int j, int current, int m, int n){
        if(current == word.size()-1) return true;
        visited[i][j] = 1;

        bool left = 0, right = 0, up = 0, down = 0;
        if(j>0 && board[i][j-1] == word[current + 1] && !visited[i][j-1])  left = solve(board, word, visited, i, j-1, current + 1, m, n);
        if(j<n-1 && board[i][j+1] == word[current + 1] && !visited[i][j+1]) right = solve(board, word, visited, i, j+1, current + 1, m, n);
        if(i>0 && board[i-1][j] == word[current + 1] && !visited[i-1][j])  up = solve(board, word, visited, i-1, j, current + 1, m, n);
        if(i<m-1 && board[i+1][j] == word[current + 1] && !visited[i+1][j]) down = solve(board, word, visited, i+1, j, current + 1, m, n);
        visited[i][j] = 0;
        return left||right||up||down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(board.size());
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                visited[i].push_back(0);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word, visited, i, j, 0,m,n)) return true;
                }
                 
            }
        }
        return false;
    }
};