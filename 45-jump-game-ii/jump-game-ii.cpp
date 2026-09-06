class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            // Maximum position reachable from current range
            farthest = max(farthest, i + nums[i]);

            // Current jump's range is finished
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};