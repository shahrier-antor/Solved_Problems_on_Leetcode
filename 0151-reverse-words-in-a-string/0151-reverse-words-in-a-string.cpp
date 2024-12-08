class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while(s[i]==' ' && i<s.size()){
            s.erase(i,1);
        }
        while(s.back() ==' '){
            s.pop_back();
        }
        for(int i = 0; i<s.size(); i++){
            if(s[i]==' ' && s[i+1]== ' '){
                s.erase(i,1);
                i--;
            }
        }
        reverse(s.begin(), s.end());

        int startIndex = 0, endIndex;
        for(int i = 0; i<=s.size(); i++){
            if(s[i] == ' ' || i == s.size()){
                reverse(s.begin() + startIndex, s.begin() + i);
                startIndex = i+1;
            }
        }
        reverse(s.begin()+startIndex, s.end());
        return s;
    }
};






// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> stringStack;

//         // Step 1: Remove leading and trailing spaces
//         int i = 0;
//         while (i < s.size() && s[i] == ' ') {
//             s.erase(i, 1); // Erase leading spaces
//         }
//         while (!s.empty() && s.back() == ' ') {
//             s.pop_back(); // Erase trailing spaces
//         }

//         // Step 2: Remove multiple spaces between words
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == ' ' && s[i + 1] == ' ') {
//                 s.erase(i, 1);
//                 i--; // Adjust index after erasing
//             }
//         }

//         // Step 3: Push words into the stack
//         for(int i = 0; i<s.size(); i++){
//             if(s[i]!=' '){
//                 string temp ="";
//                 while(i<s.size() && s[i]!=' '){
//                     temp+=s[i];
//                     i++;
//                 }
//                 stringStack.push(temp);
//             } 
//         }

//         // Step 4: Construct the result string
//         string ans = "";
//         while (!stringStack.empty()) {
//             ans += stringStack.top();
//             stringStack.pop();
//             if (!stringStack.empty()) {
//                 ans += ' '; // Add a space only if more words exist
//             }
//         }

//         return ans;
//     }
// };
