// class Solution {
// public:

//     string reorganizeString(string s) {
//         string ans = "";
//         unordered_map<char, int>h_map;
//         set<pair<int,char>>h_set;
//         int maxFreq = 0;
//         for(int i=0; i<s.size();i++){
//             h_map[s[i]]++;
//             maxFreq = max(maxFreq, h_map[s[i]]);
//         }

//         if(maxFreq> (s.size()+1)/2) return "";
//         for(auto& [key,value] : h_map) h_set.insert({value,key});
        
//         while(!h_set.empty()){
            
//             auto it = prev(h_set.end());
//             pair<int,char> last_element = *it;
//             h_set.erase(it);

//             ans+=last_element.second;           

//             if(!h_set.empty()){
//                 auto itt = prev(h_set.end());
//                 pair<int,char>second_last_element = *itt;
//                 h_set.erase(second_last_element);
//                 ans+=second_last_element.second;
//                 second_last_element.first--;
//                 if(second_last_element.first>0)h_set.insert(second_last_element);
//             }

//             last_element.first--;
//             if(last_element.first>0)h_set.insert(last_element);
 
//         }
//         return ans;
        
//     }
// };



// class Solution {
// public:

//     string reorganizeString(string s) {
//         string ans = "";
//         unordered_map<char,int>h_map;
//         priority_queue<pair<int,char>>pq;
//         int maxfreq=0;
//         for(char c : s) {
//             h_map[c]++;
//             maxfreq = max(maxfreq,h_map[c]);
//         }

//         if(maxfreq> (s.size()+1)/2) return "";
//         for(auto& [key,value]:h_map){
//             pq.push({value,key});
//         }
//         while(pq.size()>1){
//             auto [freq1, char1] = pq.top(); pq.pop();
//             auto [freq2,char2] = pq.top(); pq.pop();
//             ans+=char1;
//             ans+=char2;
//             freq1--;
//             freq2--;
//             if(freq2>0){
//                 pq.push({freq2,char2});
//             }
//             if(freq1>0){
//                 pq.push({freq1,char1});
//             }
//         }

//         if(!pq.empty()){
//             int freq = pq.top().first;
//             while(freq>0){
//                 ans+=pq.top().second;
//                 freq--;
//             }
//         }
//         return ans;
        
//     }
// };



class Solution {
public:

    string reorganizeString(string s) {

        if(s.size()==1)return s;
        string answer ="";
        
        map<char,int>h_map;
        for(char c: s){
            h_map[c]++;
        }

        int maxfreq = 0;
        priority_queue<pair<int,char>> pq;
        for(auto it: h_map){
            maxfreq = max(maxfreq, it.second);
            pq.push({it.second,it.first});
        }
        if(maxfreq>(s.size()+1)/2) return answer;

  
        while(!pq.empty()){
            auto [freq1,charctr1] = pq.top();
            pq.pop();
            answer+=charctr1;
            h_map[charctr1]--;
           
            if(!pq.empty()){
                auto [freq2, charctr2] = pq.top();
                pq.pop();
                answer+=charctr2;
                h_map[charctr2]--;
                if( h_map[charctr2] == 0) h_map.erase(charctr2);
                else pq.push({h_map[charctr2], charctr2});
            }
            if( h_map[charctr1] == 0) h_map.erase(charctr1);
            else pq.push({h_map[charctr1], charctr1});
        }
        return answer;
    }
};