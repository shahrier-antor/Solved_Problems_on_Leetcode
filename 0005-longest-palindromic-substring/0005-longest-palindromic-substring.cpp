// class Solution {
// public:
//     bool isPalindrome(string str){
//         int left = 0, right = str.size()-1;
//         while(left<right){
//             if(str[left]!=str[right])return false;
//             else{
//                 left++;
//                 right--;
//             }
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         string answer="";
//         answer+=s[0];

//         for(int i = 0; i<s.size(); i++){
//             for(int j = i+1; j<s.size(); j++){
//                 string subStr = s.substr(i, j-i+1);
//                 if(isPalindrome(subStr)){
//                     if(answer.size()<subStr.size())answer = subStr;
//                 }
//             }
//         }
//         return answer;
//     }
// };


class Solution {
public:
    pair<int,int> palindromIndices(int left, int right,string s){
        while(left>=0 && right<s.size()){
            if(s[left] == s[right]){
                left--;
                right++;
            }
            else{
                return {left+1, right-1};
            }
        }
        return {left+1, right-1};
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0;
        string answer;
        for(int i=0; i<n; i++){
            
            pair<int,int> indices = palindromIndices(i,i,s);
            cout<<indices.first<<" "<<indices.second<<endl;
            if(indices.second - indices.first + 1 > maxLength){
                answer = s.substr(indices.first,indices.second - indices.first + 1);
                maxLength = answer.size();
            }
            if(i<s.size()-1){
                indices = palindromIndices(i,i+1,s);
                if(indices.second - indices.first + 1 > maxLength){
                    answer = s.substr(indices.first,indices.second - indices.first + 1);
                    maxLength = answer.size();
                 }
                cout<<indices.first<<" "<<indices.second<<endl;
            }
            cout<<endl<<endl;
            
        }
        return answer;
    }
};