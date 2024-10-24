95. Unique Binary Search Trees II
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

vector<TreeNode*> buildTree(int start, int end) {
	vector<TreeNode*> ans;
        
    // If start > end, then subtree will be empty so add NULL in the ans and return it.
    if(start > end) {
		ans.push_back(NULL);
        return ans;
    }

    // Iterate through all values from start to end to construct left and right subtree recursively
	for(int i = start; i <= end; ++i) {
		vector<TreeNode*> leftSubTree = buildTree(start, i - 1);    // Construct left subtree
        vector<TreeNode*> rightSubTree = buildTree(i + 1, end);     // Construct right subtree
            
		// loop through all left and right subtrees and connect them to ith root  
		for(int j = 0; j < leftSubTree.size(); j++) {
			for(int k = 0; k < rightSubTree.size(); k++) {
				TreeNode* root = new TreeNode(i);   // Create root with value i
				root->left = leftSubTree[j];   // Connect left subtree rooted at leftSubTree[j]
                root->right = rightSubTree[k];   // Connect right subtree rooted at rightSubTree[k]
				ans.push_back(root);    // Add this tree(rooted at i) to ans data-structure
			}
		}
    }
        
	return ans;
}
    
vector<TreeNode*> generateTrees(int n) {
	return buildTree(1, n);
}

============================================================================================================

96. Unique Binary Search Trees
Given an integer n, return the number of structurally unique
BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

   The total number of structurally unique BSTs
formed having root i will be equal to product of these two, i.e, numTrees(i-1) * numTrees(n-i)
    int dp[20]{};
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n; i++) 
            dp[n] += numTrees(i-1) * numTrees(n-i);
        return dp[n];
    }

=============================================================================================================
  
98. Validate Binary Search Tree
Input: root = [2,1,3]
Output: true
  vector <int> nodes;
void inorder(TreeNode* root){
  if(root->left) inorder(root->left);
  nodes.push_back(root->val);
  if(root->right) inorder(root->right);
}
    bool isValidBST(TreeNode* root) {
         inorder(root);
      for(int i=0; i<nodes.size()-1; i++)
    
      if(nodes[i] >= nodes[i+1]){
      return false;
      } return true;
=============================================================================================================
  
  99. Recover Binary Search Tree== he values of exactly two nodes of the tree were swapped by mistake.
Recover the tree without changing its structure.

    void inorder (TreeNode* root, TreeNode* &prev, TreeNode* &x, TreeNode* &y) {
        if (!root) return ;
        inorder(root->left, prev, x, y);
        if (prev && root->val < prev->val) {
            if (!x) {
                x = prev;
                y = root;
            }
            else {
                y = root;
                return;
            }
        }
        prev = root;
        inorder(root->right, prev, x, y);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *x = nullptr, *y = nullptr;
        inorder (root, prev, x, y);
        swap(x->val , y->val);
    }
  
====================================================================================================
  100. Same Tree
 bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p== nullptr && q==nullptr){
           return true;
       } 
       else if(p==nullptr || q==nullptr){
            return false;
        }

  else if(p->val != q->val){
            return false;
        }
        else {
         return   isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
=======================================================================================================
  
101. Symmetric Tree = , check whether it is a mirror of itself

bool isSymmetric(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        queue<TreeNode* >q;
        q.push(root->left);
         q.push(root->right);
        while(!q.empty()){
            TreeNode*n1=(q.front());
            q.pop();
            TreeNode*n2=(q.front());
            q.pop();
            if(n1==nullptr && n2==nullptr){
            continue;
            }if(n2==nullptr || n1==nullptr){
                return false;
            }
            if(n1->val!= n2->val){
               return false;
            }
                q.push(n1->left);
                q.push(n2->right);
                q.push(n1->right);
                q.push(n2->left);
            }return true;
        
        
    }
====================================================================================================
  
102. Binary Tree Level Order Traversal

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
  vector<vector<int>>levelOrder(TreeNode* root){
   vector<vector<int>>ans;
   if(!root) return ans;
   queue<TreeNode*>q;
   q.push(root);
   while(!q.empty()){
     int sz = q.size();
     vector<int>v;
     while(sz--){
       TreeNode* f = q.front();
       v.push_back(q.front()->val);
       q.pop();
       if(f->left) q.push(f->left);
       if(f->right) q.push(f->right);
     }
     ans.push_back(v);

   }return ans;
 }
  =====================================================================================================
  103. Binary Tree Zigzag Level Order Traversal
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
  
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int>arr(n);
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                arr[i] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(c%2==0) reverse(arr.begin(), arr.end());
            ans.push_back(arr);
            c++;
        }
        return ans;
    }
  ====================================================================================================
  104. Maximum Depth of Binary Tree
Input: root = [3,9,20,null,null,15,7]
Output: 3
  int maxi(TreeNode* root){
    if(!root) return 0;
    return max(maxi(root->left), maxi(root->right)) + 1;
}
    int maxDepth(TreeNode* root) {
        return maxi(root);
    }
===================================================================================================
  105. Construct Binary Tree from Preorder and Inorder Traversal
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
  TreeNode* buildtreehelper(vector<int>& preorder, vector<int>& inorder, int left, int right, 
     unordered_map<int, int>& mapping, int& pIndex){
        if(left>right) return nullptr;
        int curr = preorder[pIndex++];
        TreeNode* root = new TreeNode(curr);
        if(left==right) return root;
        int inIndex = mapping[curr];
        root->left = buildtreehelper(preorder, inorder, left,  inIndex-1, mapping, pIndex);
        root->right = buildtreehelper(preorder, inorder, inIndex+1, right, mapping, pIndex);
        return root;
     }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int pIndex = 0;
        unordered_map<int, int>mapping;
        for(int i=0; i<inorder.size(); i++) mapping[inorder[i]] = i;
        return buildtreehelper(preorder, inorder, 0, preorder.size()-1, mapping, pIndex);
    }

====================================================================================================
  106. Construct Binary Tree from Inorder and Postorder Traversal

   TreeNode* solve(int& postindex, int ini, int inj, vector<int>& inorder, vector<int>& postorder ){
    if(postindex<0 || ini>inj) return NULL;
    TreeNode* root = new TreeNode(postorder[postindex--]);
    int i;
    for(i= ini; i<inj; i++){
        if(inorder[i]== root->val) break;
    }
    // inorder(left root right)
// the right side of i is the root'right , i+1 right side hoga
    root->right = solve(postindex, i+1, inj, inorder, postorder);
    // the left side of i is the root's left
    root->left= solve(postindex, ini, i-1, inorder, postorder);
    return root;
  }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     int ind = postorder.size()-1;
     return solve(ind, 0, inorder.size()-1, inorder, postorder);
    }
};
=========================================================================================================
107. Binary Tree Level Order Traversal II  == , from left to right, level by level from leaf to root).
, from left to right, level by level from leaf to root).  
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
  
vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(it) temp.push_back(it->val);
            if(!it){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            } else{
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }  reverse(ans.begin(), ans.end());
        return ans;
        
    }
  ==========================================================================================
  
, the idea is to construct a balanced binary search tree (BST) from a sorted array.
  The middle element of the array can naturally serve as the root, ensuring balance. The elements to the left of the middle become the left subtree, and the elements to the right become the right subtree. 
  This approach recursively constructs subtrees and ensures the BST property and balance.

   if (nums.empty()) {
            return nullptr;
        }

        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> leftPart(nums.begin(), nums.begin() + mid);
        root->left = sortedArrayToBST(leftPart);

        vector<int> rightPart(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(rightPart);

        return root;
================================================================================================
  
109. Convert Sorted List to Binary Search Tree
  ListNode* findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        
        // Use the slow-fast pointer technique to find the middle of the list
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If there is a previous node, disconnect the left half
        if (prev) {
            prev->next = nullptr;
        }
        
        return slow;  // The 'slow' pointer will be at the middle of the list
    }


    TreeNode* sortedListToBST(ListNode* head) {
          if (!head) return nullptr;  // Base case: if the list is empty, return null
        if (!head->next) return new TreeNode(head->val);  // If there's only one node, create a TreeNode and return it
        
        // Find the middle element of the list
        ListNode* mid = findMiddle(head);
        
        // The middle element becomes the root of the BST
        TreeNode* root = new TreeNode(mid->val);
        
        // Recursively build the left and right subtrees
        root->left = sortedListToBST(head);        // Left subtree from the left half of the list
        root->right = sortedListToBST(mid->next);  // Right subtree from the right half of the list
        
        return root;
    }

===============================================================================================
  110. Balanced Binary Tree
Input: root = [3,9,20,null,null,15,7]
Output: true

  int checkHeight(TreeNode* node) {
        if(node == NULL){
            return 0;
        }
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight); 
    }
public:
    bool isBalanced(TreeNode* root) {
        if(checkHeight(root) != -1) return true;
        else return false;
    }
============================================================================================
 111. Minimum Depth of Binary Tree 
 int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+ minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+ min(minDepth(root->left), minDepth(root->right));

    }
=================================================================================================
  112. Path Sum== return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
  
      bool hasPathSum(TreeNode* root, int targetSum) {
          if (!root) {
            return false;
        }
        
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);
        
        return left_sum || right_sum;
    }
===========================================================================================
  113. Path Sum II  == return all root-to-leaf paths where the sum of the node values in the path equals targetSum
  . Each path should be returned as a list of the node values, not node references.

  void dfs(TreeNode *root, int target, int curr, vector<int> ds, vector<vector<int>>& ans){
    if(root==NULL) return;
    curr+= root->val;
    ds.push_back(root->val);
    if(root->left==NULL && root->right==NULL && curr==target){
        ans.push_back(ds);
        return;
    }
    dfs(root->left, target, curr, ds, ans);
    dfs(root->right, target, curr, ds, ans);
    curr-=root->val;
    ds.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>ds;
        if(root==NULL) return ans;
         dfs(root, targetSum, 0, ds, ans);
        return ans;

    }
==============================================================================================
  114. Flatten Binary Tree to Linked List
   TreeNode* linkedlist(TreeNode* root){
        if(root == NULL) return NULL;

        TreeNode* left = linkedlist(root->left);
        TreeNode* right = linkedlist(root->right);

        if (left) {
            TreeNode* trav = left;

            while (trav->right != NULL) {
                trav = trav->right;
            }
            trav->right = right;
            
            root->right = left;
            root->left = NULL;
        }

        return root;
    }

    void flatten(TreeNode* root) {
        linkedlist(root);
    }
==================================================================================================
  116. Populating Next Right Pointers in Each Node
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]

   Node* connect(Node* root) {
         if(root==NULL)
    return NULL;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* node=q.front();
            q.pop();
            if(node==NULL)
            {
                q.push(NULL);
                continue;
            }
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);

            node->next=q.front();
        }
    }
    return root;
        
    }
  ==============================================================================================
117. Populating Next Right Pointers in Each Node II

   Node* connect(Node* root) {
        if(!root) return NULL;

			vector<vector<Node*>> lvl;
			queue <Node*> q;
			q.push(root);

			while(!q.empty()){
				int size = q.size();
				vector <Node*> temp;

				for(int i = 0 ; i < size ; i++){
					Node* node = q.front();
					q.pop();
					if(node -> left) q.push(node -> left);
					if(node -> right) q.push(node -> right);
					temp.push_back(node);
				}

				temp.push_back(NULL);
				lvl.push_back(temp);
			} 

			for(int i = 0 ; i < lvl.size() ; i++){
				for(int j = 0 ; j < lvl[i].size() - 1 ; j++) lvl[i][j] -> next = lvl[i][j + 1];
			}

			return root;
        
    }
================================================================================================
  
  















  











