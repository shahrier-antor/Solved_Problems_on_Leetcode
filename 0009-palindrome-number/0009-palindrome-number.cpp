class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str = to_string(x);  
        string rev = str;
        reverse(str.begin(), str.end());
        if(str == rev) return true;
        else return false;
    }
};