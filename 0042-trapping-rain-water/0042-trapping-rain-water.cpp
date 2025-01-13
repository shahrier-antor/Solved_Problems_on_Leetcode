class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft = height[0], maxRight= height[n-1];
        int left = 0, right = n-1;
        int answer=0;
        while(left<right){
            if(maxLeft<maxRight){
                answer+= max(0,maxLeft-height[left]);
                left++;
                maxLeft = max(maxLeft, height[left]);
            }
            else{
                answer += max(0,maxRight-height[right]);
                right--;
                maxRight = max(maxRight, height[right]);
            }
        }
        return answer;
    }
};