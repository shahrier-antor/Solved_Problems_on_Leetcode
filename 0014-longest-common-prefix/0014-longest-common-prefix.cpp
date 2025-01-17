class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int left = 0;
        string answer="";
        
        while(left<strs[0].size()){
            char current = strs[0][left];

            for(int i = 1; i<strs.size(); i++){
                if(left == strs[i].size())return answer ;
                else if(strs[i][left]!=current) return answer;
            }
            left++;
            answer+=current;
        }
        return answer;
       
    }
};