class Solution {
public:
    int countGoodSubstrings(string s) {
        // int answer = 0;
        // int low = 0, high = 2;
        
        // while(high<s.size()){
        //     vector<int>alphabetArray(26,0);
        //     bool good = 1;
        //     for(int i = low; i<=high; i++){
        //         if(alphabetArray[s[i] - 'a']!=0){
        //             good = 0;
        //             break;
        //         }
        //         else alphabetArray[s[i] - 'a'] = 1;
        //     }
        //     if(good) answer++;
        //     high++;
        //     low++;
        // }
        // return answer;


        int answer = 0;
        int high = 2;
        while(high<s.size()){
            if(s[high] != s[high-1] && s[high]!= s[high-2] && s[high-1]!=s[high-2])answer++;
            high++;
        }
        return answer;
    }
};