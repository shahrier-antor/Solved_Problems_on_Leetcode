class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool up = 0, down = 0, right = 1, left = 0;
        vector<int>answer;
        int  i = 0, j = -1;
        int m = matrix.size();
        int n = matrix[i].size();
        while(answer.size()< m*n){

            if(right){
                j++;
                while(j<n && matrix[i][j]!= -1000){
                    cout<<matrix[i][j]<<" ";
                    answer.push_back(matrix[i][j]);
                    matrix[i][j] = -1000;
                    j++;
                }
                right = 0;
                down = 1;
                cout<<endl;
                j--;
            }
            if(down){
                i++;
                while(i<m && matrix[i][j]!= -1000){
                    cout<<matrix[i][j]<<" ";
                    answer.push_back(matrix[i][j]);
                    matrix[i][j] = -1000;
                    i++;
                }
                down = 0;
                left = 1;
                cout<<endl;
                i--;
            }
            if(left){
                j--;
                while(j>=0 && matrix[i][j]!= -1000){
                    cout<<matrix[i][j]<<" ";
                    answer.push_back(matrix[i][j]);
                    matrix[i][j] = -1000;
                    j--;
                }
                left = 0;
                up = 1;
                cout<<endl;
                j++;
            }

            if(up){
                i--;
                while(i>=0 && matrix[i][j]!= -1000){
                    cout<<matrix[i][j]<<" ";
                    answer.push_back(matrix[i][j]);
                    matrix[i][j] = -1000;
                    i--;
                }
                up = 0;
                right = 1;
                cout<<endl;
                i++;
            }
            //cout<<answer.size()<<endl;
        }
        return answer;
    }
};