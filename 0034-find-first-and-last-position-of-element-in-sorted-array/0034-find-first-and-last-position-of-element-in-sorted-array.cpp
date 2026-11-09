class Solution {
    int findBound(vector<int>& nums, int target, bool first) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;

                if (first)
                    right = mid - 1;
                else
                    left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true),
                findBound(nums, target, false)};
    }
};
