class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>h_map;
        vector<vector<string>>answer;
        for(string str: strs){
            string temp;
            temp = str;
            sort(temp.begin(), temp.end());
            h_map[temp].push_back(str);
        }

        for(auto& [sorted,original]: h_map){
            answer.push_back(original);
        }
        return answer;
    }
};