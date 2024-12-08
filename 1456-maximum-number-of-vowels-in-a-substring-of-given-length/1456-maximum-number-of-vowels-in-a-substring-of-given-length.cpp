class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u';
    }
    int maxVowels(string s, int k) {
        int maximum = 0; 
        int low = 0, high = k-1;
        for(int i = 0; i<k; i++){
            if(isVowel(s[i]))maximum++;
        }
        int current = maximum;
        while(high<s.size()){
            high++;
            if(isVowel(s[high])) current++;
            if(isVowel(s[low])) current--;
            maximum = max(maximum, current);
            low++;
        }
        return maximum;
    }
};