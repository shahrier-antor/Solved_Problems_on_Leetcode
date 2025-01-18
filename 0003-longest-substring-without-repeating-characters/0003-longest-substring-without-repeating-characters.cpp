// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int low = 0, high=0, length = 0;
//         unordered_map<char,int>h_map;

//         while(high<s.size()){
            
//             h_map[s[high]]++;
            
//             while( h_map[s[high]]>1 && low<=high){
//              h_map[s[low]]--;
//              low++;
//             }
//             length = max(length,high-low+1); 
//             high++;
//         }

//         return length;
      
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, high = 0, answer = 0;
        unordered_map<char, int>h_map;
        int temp = 0;
        while(high<s.size()){
            h_map[s[high]]++;
           

            if(h_map[s[high]]>1){
                answer = max(answer, temp);
                while(h_map[s[high]]>1){
                    h_map[s[left]]--;
                    temp--;
                    if(h_map[s[left]]==0) h_map.erase(s[left]);
                    left++;
                }
            }
            temp++;
            high++;
        }
        answer = max(answer, temp);
        return answer;
    }
};



