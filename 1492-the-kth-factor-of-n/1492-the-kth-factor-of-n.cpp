class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 0;
        while(k && i<=n){
            i++;
            if(n%i==0){
                k--;
                
            }
        }
        return k>0? -1:i;
    }
    
};