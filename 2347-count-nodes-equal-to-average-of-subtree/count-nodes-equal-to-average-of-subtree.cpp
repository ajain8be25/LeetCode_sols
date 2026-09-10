class Solution {
public:
    int answer = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);

        int totalSum = left.first + right.first + node->val;
        int totalCount = left.second + right.second + 1;

        if (totalSum / totalCount == node->val) {
            answer++;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return answer;
    }
};