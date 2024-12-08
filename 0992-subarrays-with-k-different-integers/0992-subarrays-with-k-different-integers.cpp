class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

private:
    int atMostKDistinct(const vector<int>& nums, int k) {
        int low = 0, high = 0, count = 0;
        unordered_map<int, int> h_map;

        while (high < nums.size()) {
            // Add nums[high] to the map
            h_map[nums[high]]++;
            high++;

            // Shrink the window if there are more than k distinct integers
            while (h_map.size() > k) {
                h_map[nums[low]]--;
                if (h_map[nums[low]] == 0) {
                    h_map.erase(nums[low]);
                }
                low++;
            }

            // Add the number of subarrays ending at high-1
            count += high - low;
        }

        return count;
    }
};
