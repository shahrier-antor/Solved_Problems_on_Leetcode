class Solution {
public:

    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char, int>h_map;
        set<pair<int,char>>h_set;
        int maxFreq = 0;
        for(int i=0; i<s.size();i++){
            h_map[s[i]]++;
            maxFreq = max(maxFreq, h_map[s[i]]);
        }

        if(maxFreq> (s.size()+1)/2) return "";
        for(auto& [key,value] : h_map) h_set.insert({value,key});
        
        while(!h_set.empty()){
            
            auto it = prev(h_set.end());
            pair<int,char> last_element = *it;
            h_set.erase(it);

            ans+=last_element.second;           

            if(!h_set.empty()){
                auto itt = prev(h_set.end());
                pair<int,char>second_last_element = *itt;
                h_set.erase(second_last_element);
                ans+=second_last_element.second;
                second_last_element.first--;
                if(second_last_element.first>0)h_set.insert(second_last_element);
            }

            last_element.first--;
            if(last_element.first>0)h_set.insert(last_element);
 
        }
        return ans;
        
    }
};