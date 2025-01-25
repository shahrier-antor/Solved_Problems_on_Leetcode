class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        int m = nums1.size(), n = nums2.size();
        int median_index1 = (m + n + 1) / 2; // Left middle for odd/even
        int median_index2 = (m + n + 2) / 2; // Right middle for even
        int pointer1 = 0, pointer2 = 0, match = 0;
        int current = 0, prev = 0;

        while (pointer1 < m || pointer2 < n) {
            prev = current; // Keep track of the previous value
            if (pointer1 < m && (pointer2 >= n || nums1[pointer1] <= nums2[pointer2])) {
                current = nums1[pointer1++];
            } else {
                current = nums2[pointer2++];
            }
            match++;

            // Check if we've reached the necessary median indices
            if (match == median_index2) {
                if ((m + n) % 2 == 0) {
                    median = (prev + current) / 2.0;
                } else {
                    median = current;
                }
                break;
            }
        }

        return median;
    }
};
