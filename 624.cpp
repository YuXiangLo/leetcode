class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = 1e9, max_val = -1e9, min_id = -1, max_id = -1;
        int sec_min_val, sec_max_val;
        int cnt = 0;
        for (auto &v : arrays) {
            if (v.front() < min_val) {
                min_id = cnt;
                sec_min_val = min_val;
                min_val = v.front();
            } else if (v.front() < sec_min_val) {
                sec_min_val = v.front();
            }
            if (v.back() > max_val) {
                max_id = cnt;
                sec_max_val = max_val;
                max_val = v.back();
            } else if (v.back() > sec_max_val) {
                sec_max_val = v.back();
            }
            ++cnt;
        }

        // cout << min_val << ' ' << sec_min_val << '\n';
        // cout << max_val << ' ' << sec_max_val << '\n';
        if (min_id == max_id) return max(max_val - sec_min_val, sec_max_val - min_val);
        return max_val - min_val;
    }
};
