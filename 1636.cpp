class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {};
        for (int i : nums)
            freq[i+100]++;
       
        sort(nums.begin(), nums.end(), [&](int a, int b){return freq[a+100] < freq[b+100] || freq[a+100] == freq[b+100] && a > b;});
        return nums;
    }
};
