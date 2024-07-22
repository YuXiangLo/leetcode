#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		vector<int> nodesBetweenCriticalPoints(ListNode* head) {
			ListNode* prev_node = NULL;
			ListNode* next_node = NULL;
			vector<int> vec_idx;
			for(int i = 1; head->next != NULL; i++) {
				cout << head->val << '\n';
				prev_node = head;
				head = head->next;
				next_node = head->next;
				if (next_node == NULL) 
					break;
				if (head->val > prev_node->val && head->val > next_node->val ||\
						head->val < prev_node->val && head->val < next_node->val)
					vec_idx.push_back(i);
			}
			if (vec_idx.size() < 2) return {-1, -1};
			int min_dis = 1e9;
			for (int i = 1; i < vec_idx.size(); i++) {
				min_dis = min(min_dis, vec_idx[i] - vec_idx[i - 1]);
			}
			int max_dis = vec_idx.back() - vec_idx.front();
			return {min_dis, max_dis};
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ListNode* b = new ListNode(1);
	ListNode* head = new ListNode(3, b);
	Solution solution;
	auto ret = solution.nodesBetweenCriticalPoints(head);
	for (int i : ret)
		cout << i << ' ';
	return 0;
}


