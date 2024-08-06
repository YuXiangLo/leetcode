class Solution {
public:
    int minimumPushes(string word) {
        // 8 num key can be utilized
        int cnt[26] = {};
        for (char c : word)
            cnt[c - 'a']++;
        sort(cnt, cnt + 26, [](int a, int b){return a > b;});
        int ret = 0;
        for (int i = 0, cost = 0; i < 26; i++) {
            cost += (i % 8 == 0);
            ret += cost * cnt[i];
        }
        return ret;
    }
};
