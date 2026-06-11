// Last updated: 6/11/2026, 8:12:03 AM
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // Create parent node if not present
            if (!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);

            // Create child node if not present
            if (!nodes.count(child))
                nodes[child] = new TreeNode(child);

            // Connect nodes
            if (isLeft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            children.insert(child);
        }

        // Find root
        for (auto &d : descriptions) {
            int parent = d[0];

            if (!children.count(parent))
                return nodes[parent];
        }

        return nullptr;
    }
};