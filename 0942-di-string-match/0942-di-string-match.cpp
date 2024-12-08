class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>results;
        int high = n, low = 0;
        for(int i =0; i<n; i++){
            if(s[i]=='I'){
                results.push_back(low);
                low++;
            }
            else{
                results.push_back(high);
                high--;
            }
        }
        results.push_back(low);
        return results;
        
    }

};