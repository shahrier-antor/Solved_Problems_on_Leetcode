class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a_pointer = 0; // Start pointer
        int b_pointer = 0; // End pointer
        int max_length = 0; // Maximum length of substring
        std::unordered_set<char> hash_set; // Set to store unique characters

        while (b_pointer < s.length()) {
            if (hash_set.find(s[b_pointer]) == hash_set.end()) {
                // Add the character to the set and move the end pointer forward
                hash_set.insert(s[b_pointer]);
                b_pointer++;
                max_length = max(static_cast<int>(hash_set.size()), max_length); // Update the max length
            } else {
                // Remove the starting character and move the start pointer forward
                hash_set.erase(s[a_pointer]);
                a_pointer++;
            }
        }

        return max_length;
    }
};