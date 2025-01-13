class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int first=0, second=0;
        string answer = "";

        while(first<word1.size() && second<word2.size()){
            answer+=word1[first++];
            answer+=word2[second++];
        }
        if(first==word1.size()){
            while(second<word2.size())answer+=word2[second++];
        }
        if(second==word2.size()){
            while(first<word1.size())answer+=word1[first++];
        }
        return answer;
    }
};