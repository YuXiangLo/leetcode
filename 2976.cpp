class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int dp[26][26] = {};
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dp[i][j] = 1e9;

        for (int i = 0; i < original.size(); i++)
            dp[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], dp[original[i] - 'a'][changed[i] - 'a']);

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }

        long long ret = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (dp[source[i] - 'a'][target[i] - 'a'] >= 1e9)
                    return -1;
                ret += dp[source[i] - 'a'][target[i] - 'a'];
            }
        }
            
        return ret;
    }
};
