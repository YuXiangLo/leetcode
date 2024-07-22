#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string traj;
    string start_traj;
    string end_traj;
    int reverse; // 0 for not met any dest, 1 for not reverse, 2 for reverse
    void dfs(TreeNode* root, int start, int end) {
        if (root == NULL) return;
        // cout << traj << '\n';
        if (root->val == start) {
            start_traj = traj;
        } else if (root->val == end) {
            end_traj = traj;
        }
        string tmp = traj;

        traj = tmp + "L";
        dfs(root->left, start, end);

        traj = tmp + "R";
        dfs(root->right, start, end);
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root, startValue, destValue);
        int cur = 0;
        while (start_traj[cur] == end_traj[cur]) ++cur;
        string ret = "";
        for (int i = 0; i < start_traj.size(); i++)
            ret += "U";
        for (int i = cur; i < end_traj.size(); i++)
            ret += end_traj[i];
        return ret;
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    cout << solution.getDirections(root, 3, 6) << '\n';
}