class Solution {
public:
    int numberOfPoints(std::vector<std::vector<int>>& nums) {
        std::set<int> points;

        for (const std::vector<int>& range : nums) {
            for (int i = range[0]; i <= range[1]; i++) {
                points.insert(i);
            }
        }

        return points.size();
    }
};