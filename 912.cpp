class Solution {
public:

    void merge(vector<int>& nums, const int l, const int r) {
        vector<int> buf;
        const int m = (l + r) / 2;
        int rb = m, lb = l;
        while (lb != m && rb != r) {
            if (nums[lb] < nums[rb])
                buf.push_back(nums[lb++]);
            else
                buf.push_back(nums[rb++]);
        }
        while (lb != m)
            buf.push_back(nums[lb++]);
        while (rb != r)
            buf.push_back(nums[rb++]);
        
        for (int i = l, j = 0; i < r; i++, j++)
            nums[i] = buf[j];
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l + 1 >= r) return;
        mergesort(nums, l, (l + r) / 2);
        mergesort(nums, (l + r) / 2, r);
        merge(nums, l, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size());
        return nums;
    }
};
