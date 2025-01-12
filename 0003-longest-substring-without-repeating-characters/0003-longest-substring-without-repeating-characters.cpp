// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int a_pointer = 0; 
//         int b_pointer = 0; 
//         int max_length = 0; 
//         unordered_set<char> hash_set; 

//         while (b_pointer < s.length()) {
//             if (hash_set.find(s[b_pointer]) == hash_set.end()) {
//                 hash_set.insert(s[b_pointer]);
//                 b_pointer++;
//                 int size = hash_set.size();
//                 max_length = max(size, max_length); 
//             } else {
//                 hash_set.erase(s[a_pointer]);
//                 a_pointer++;
//             }
//         }
//         return max_length;
//     }
// };

// abcabcbb
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high=0, length = 0;
        unordered_map<string,int>h_map;

        while(high<s.size()){
            
            string right = "";
            right+=s[high];
           // cout<< "input :"<< right<<"inputends"<<endl;
            h_map[right]++;
            
            while(h_map[right]>1 && low<=high){
             string left = "";
             left+=s[low];
             h_map[left]--;
             low++;
            }
            length = max(length,high-low+1); 
             high++;
        }

        return length;
      
    }
};


