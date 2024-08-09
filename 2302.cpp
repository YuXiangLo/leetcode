class Solution {
public:
    long long prefix_sum[100001] = {};
    long long solve(vector<int>& nums, long long k, int l, int r) {
        if (l >= r) return 0;
        if (l + 1 == r)
            return nums[l] < k;
        int m = (l + r) / 2;
        long long ret = 0;
        ret += solve(nums, k, l, m) + solve(nums, k, m, r);
        long long sum = 0, len = m - l + 1;
        sum = prefix_sum[m + 1] - prefix_sum[l];
        int lbd = l, rbd = m; // range: [l, m]
        while (lbd < m && rbd < r) {
            if (sum * len < k) {
                ret += (m - lbd);
                sum += nums[++rbd];
                ++len;
            } else {
                sum -= nums[lbd++];
                --len;
            }
        }
        return ret;

    }
    long long countSubarrays(vector<int>& nums, long long k) {
        prefix_sum[0] = 0;
        for (int i = 0; i < nums.size(); i++)
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        nums.push_back(LLONG_MAX);
        return solve(nums, k, 0, nums.size()-1);
    }
};
