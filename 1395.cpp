class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ret = 0;
        for (int i = 0, l1, l2, r1, r2; i < rating.size(); i++) {
            l1 = l2 = r1 = r2 = 0;
            for (int j = 0; j < i; j++)
                l1 += rating[i] > rating[j], l2 += rating[i] < rating[j];
            for (int j = rating.size() - 1; j > i; j--)
                r1 += rating[i] < rating[j], r2 += rating[i] > rating[j];
            ret += l1 * r1 + l2 * r2;
        }
        return ret;
    }
};
