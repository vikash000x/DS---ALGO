124. Binary Tree Maximum Path Sum== . A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
  Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
  
int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;  // Base case: return 0 if the node is null
        
        // Recursively calculate the maximum gain from the left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum), 0);  // Ignore negative paths
        int rightGain = max(maxGain(node->right, maxSum), 0);  // Ignore negative paths
        
        // Calculate the maximum path sum passing through the current node
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the global maximum sum if the current path sum is larger
        maxSum = max(maxSum, currentPathSum);
        
        // Return the maximum gain the current node can contribute to its parent
        return node->val + max(leftGain, rightGain);
    } 

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // Initialize the maxSum to the smallest possible value
        maxGain(root, maxSum);  // Calculate the maximum gain for the tree
        return maxSum;  // Return the final result
    }

==========================================================================================================
  129. Sum Root to Leaf Numbers
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
  
 int solve(TreeNode* root, int ans) {
        if (root == nullptr) {
            return 0;
        }

        ans = (ans * 10) + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return ans;
        }

        return solve(root->left, ans) + solve(root->right, ans);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
============================================================================================================
 173. Binary Search Tree Iterator 
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False

BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    void partialInorder(TreeNode* root){
        while(root){
            st.push(root);
            root= root->left;
        }
    }
    
    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        partialInorder(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
==========================================================================================================
  199. Binary Tree Right Side View







