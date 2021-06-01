class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, median = nums[~~(nums.size() / 2)];
        for (auto num : nums) ans += abs(median - num);
        return ans;
    }
};