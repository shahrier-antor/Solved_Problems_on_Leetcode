class NumMatrix {
private:
    int rows, cols;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = rows > 0 ? matrix[0].size() : 0;
        for(int i = 0; i< rows; i++){
            for(int j = 0; j<cols; j++){
                if(i>0) matrix[i][j] += matrix[i-1][j];
                if(j>0) matrix[i][j] += matrix[i][j-1];
                if(i>0 && j>0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        sums = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = sums[row2][col2];
        if(row1>0) answer -= sums[row1-1][col2];
        if(col1>0) answer -= sums[row2][col1-1];
        if(row1>0 && col1>0) answer += sums[row1-1][col1-1];
        return answer;
     }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */