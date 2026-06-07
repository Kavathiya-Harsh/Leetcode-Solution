// Last updated: 6/7/2026, 10:28:49 AM
1class Solution {
2public:
3    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
4        unordered_map<int, TreeNode*> nodes;
5        unordered_set<int> children;
6
7        for (auto &d : descriptions) {
8            int parent = d[0];
9            int child = d[1];
10            int isLeft = d[2];
11
12            // Create parent node if not present
13            if (!nodes.count(parent))
14                nodes[parent] = new TreeNode(parent);
15
16            // Create child node if not present
17            if (!nodes.count(child))
18                nodes[child] = new TreeNode(child);
19
20            // Connect nodes
21            if (isLeft)
22                nodes[parent]->left = nodes[child];
23            else
24                nodes[parent]->right = nodes[child];
25
26            children.insert(child);
27        }
28
29        // Find root
30        for (auto &d : descriptions) {
31            int parent = d[0];
32
33            if (!children.count(parent))
34                return nodes[parent];
35        }
36
37        return nullptr;
38    }
39};