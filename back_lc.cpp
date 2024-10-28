17. Letter Combinations of a Phone Number
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

  vector<string>ans;
  void recur(int ind, string& digits, unordered_map<char, string> &mp, string &temp){
    if(ind>=digits.size()){
         ans.push_back(temp);
         return;
 }
    char ch =  digits[ind];
    string str = mp[ch];
    for(int i =0; i<str.length(); i++){
        temp.push_back(str[i]);
        recur(ind+1, digits, mp, temp);
        temp.pop_back();
    }
  }

    vector<string> letterCombinations(string digits) {
    if(digits.length() == 0) return {};
        unordered_map<char, string>mp;   
        mp['2'] = "abc";
         mp['3'] = "def";
          mp['4'] = "ghi";
           mp['5'] = "jkl";
            mp['6'] = "mno";
         mp['7'] = "pqrs";
          mp['8'] = "tuv";
           mp['9'] = "wxyz";
           string temp = "";
        recur(0,digits, mp, temp);
        return  ans;
    }
==========================================================================================================
  22. Generate Parentheses
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

   void helper(string curr, int o, int c, int n, vector<string>&res){
        if(o==n && c==n){
            res.push_back(curr);
            return;
        }

        if(o<n){
            helper(curr + '(', o+1, c, n, res);
        }

        if(o>c){
            helper(curr + ')', o, c+1, n, res);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> res;
        helper("", 0, 0, n, res);
        return res;
        
    }
========================================================================================================
37. Sudoku Solver
bool isSafe(int row, int col, vector<vector<char>>&board, int val){
      for(int i =0; i<board.size(); i++){
          if(board[row][i] == val)
          return false;
          if(board[i][col]==val)
          return false;
          if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
          return false;
      }  return true;
  }
  

  bool solve(vector<vector<char>> &board){
      int n= board[0].size();

      for(int row= 0; row<n; row++){
          for(int col = 0; col<n; col++){
              if(board[row][col]== '.'){
                  for(char val  = '1'; val<='9'; val++){
                      if(isSafe(row, col, board, val)){
                          board[row][col] = val;

                          bool aagesolutionposs = solve(board);
                         if(aagesolutionposs)
                         return true;
                         else {
                              board[row][col] = '.'; 
                         }
                      }
                  }

                  return false;
              }
          }
      }

      return true;
  }
  
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
=======================================================================================================
  39. Combination Sum = Two combinations are unique if the frequencyof at least one of the chosen numbers is different.
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

void combination(vector<int> &candidates, int target, vector<vector<int>>& result, vector<int>curr, int idx){
    if(target<0) return;
    if(target == 0) result.push_back(curr);

    for(int i=idx; i<candidates.size(); i++){
        curr.push_back(candidates[i]);
        combination(candidates, target-candidates[i], result, curr, i);
        curr.pop_back();
    }
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        combination(candidates, target, result, curr, 0);
        return result;
        
    }
========================================================================================================
  40. Combination Sum II== Each number in candidates may only be used once in the combination.
  Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
  
void combination(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> curr, int idx){
    if(target<0) return;
    if(target==0){
        result.push_back(curr);
        return;
    }

    for(int i=idx; i<candidates.size(); i++){
        if(i>idx && candidates[i]==candidates[i-1])
        continue;

        curr.push_back(candidates[i]);
        combination(candidates, target-candidates[i], result, curr, i+1);
        curr.pop_back();
    }
 }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        combination(candidates, target, result, curr, 0);
        return result;
    }
========================================================================================================
  46. Permutations
  Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

   vector<vector<int>>ans;

 void helper(vector<int>&nums, vector<bool>& vis, vector<int>& p){
     if(p.size()==nums.size()){
         ans.push_back(p);
         return;
     }

     for(int i=0; i<nums.size(); i++){
         if(!vis[i]){
             vis[i] = true;
             p.push_back(nums[i]);
             helper(nums, vis, p);
             vis[i] = false;
             p.pop_back();
         }
     }
 }
  vector<vector<int>> permute(vector<int>& nums) {

        vector<int>p;
        vector<bool>vis(nums.size(), false);
        helper(nums, vis, p);
        return ans;        
    }
==========================================================================================================
47. Permutations II = numbers, nums, that might contain duplicates, return all possible unique permutations in any order
void helper(vector<vector<int>>&ans, vector<int>&nums, vector<bool>&vis, vector<int>&p){
     if(p.size() == nums.size()){
         ans.push_back(p);
         return;
     }
     set<int>st;
     for(int i=0; i<nums.size(); i++){
         if(!vis[i] && st.find(nums[i])==st.end()){
             vis[i] = true;
             st.insert(nums[i]);
             p.push_back(nums[i]);
             helper(ans, nums, vis, p);
             vis[i] = false;
             p.pop_back();
         }
     }
 }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>p;
         vector<bool>v(nums.size(), false);

        helper(ans, nums, v, p);
        return ans;        
    }
==========================================================================================================
  51. N-Queens = Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

   vector<vector<string> > sols; // 2D vector of strings to store the solutions
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return sols; 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }
    // Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
    void solve(vector<string>& board, int row) {
	// Base condition. 
    // We reached the last row, so we have a solution so we add it to the solution vector
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	}            
	    // Try placing a queen on each column for a given row. 
        // Explore next row by placing Q at each valid column for the current row
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // Queen placed on a valid cell
			    solve(board, row + 1);    // Exploring next row
			    board[row][col] = '.';    // Backtracking to get all possible solutions
		    }
        }
    }
===========================================================================================================
52. N-Queens II== Given an integer n, return the number of distinct solutions to the n-queens puzzle.
  int x;
    int totalNQueens(int n) {
   vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return x;
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }
    // Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
    void solve(vector<string>& board, int row ) {
	// Base condition. 
    // We reached the last row, so we have a solution so we add it to the solution vector
	    if(row == size(board)) { 
		x++;
        return;
		    
    	}            
	    // Try placing a queen on each column for a given row. 
        // Explore next row by placing Q at each valid column for the current row
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // Queen placed on a valid cell
			    solve(board, row + 1);    // Exploring next row
			    board[row][col] = '.';    // Backtracking to get all possible solutions
		    }
        }
    }
==========================================================================================================
  77. Combinations
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

   void helper(int n, int k, vector<vector<int>>&ans,int ind, vector<int>&temp){

      //base cond-- if comb. size becomes equal to k , add it to result and return
      if(temp.size()== k){
          ans.push_back(temp);
          return;
      }
  
   // generate comb. by selecting elem from ind to n
      for(int i=ind; i<=n; i++){
          temp.push_back(i); //include cur el in comb
          helper(n, k, ans, i+1, temp); // recur to include the next elem
          temp.pop_back(); //backtrack by removing the last added elem
      }
  }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(n, k, ans, 1, temp);
        return ans;
        
    }
  ======================================================================================================
  78. Subsets
  Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

   void solve(vector<int>& nums, int i, vector<int>v , vector<vector<int>>& ans){
      if(i==nums.size()){
          ans.push_back(v);
          return;
      }
      solve(nums, i+1, v, ans); //either we exclude
      v.push_back(nums[i]);  //either we include
      solve(nums, i+1, v, ans);
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums, 0, v, ans);
        return ans;        
    }
==========================================================================================================
  79. Word Search
  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

   bool find(vector<vector<char>>& board, vector<vector<int>>& vis, string& word, vector<pair<int, int>>& dirc, int
 row, int col, int idx){
    if(idx==word.size()) return true;
  if(row<0 || row>=board.size() || col<0 || col>= board[0].size() || vis[row][col] || board[row][col]!= word[idx]){
    return false;
  } vis[row][col] = 1;
  for(auto &d : dirc){
    int newrow = row + d.first; int newcol = col + d.second;
    if(find(board, vis, word, dirc, newrow, newcol, idx+1)){
        return true;
    }
  }  vis[row][col] = 0;
  return false;
 }
   bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

       vector<vector<int>>vis(n, vector<int>(m, 0));
       vector<pair<int, int>>dirc = {{1,0}, {0,-1}, {-1,0}, {0,1}};
       for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0] && find(board, vis, word, dirc, i, j, 0)){
                return true;
            }
        }
       } return false;
        
    }
===========================================================================================================
  89. Gray Code
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].

   vector<int> grayCode(int n) {
        vector<int>ans(1<<n);

        for(int i=0; i<(1<<n); i++)
            ans[i] = i^(i>>1);
            return ans;
     ======================================================================================================
       90. Subsets II == The solution set must not contain duplicate subsets. Return the solution in any order.
       
   void helper(vector<int>& nums, vector<vector<int>>& ans, int i,
                vector<int>& temp) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        helper(nums, ans, i + 1, temp);
        temp.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        helper(nums, ans, i + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, 0, temp);
        return ans;
    }  
======================================================================================================
  93. Restore IP Addresses
  Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

    vector<string> ans;
    void find_ip(string s, int count){
        int ind;
         //no dots placed yet
        if(count == 0) ind = -1;
        else ind = s.find_last_of('.');
        if(count == 4 && ind == s.size()-1){
             //remove last dot
            s.erase(s.begin()+s.size()-1);
            ans.push_back(s);
            return;
        }  if(count >= 4) return;
        for(int i=1; i<=3; i++){
            if(ind+i>=s.size()) break;
            string temp = s.substr(ind+1, i);
            int num = stoi(temp);
            //Check for leading zeroes
            if(num==0 && temp.size()>1) break;
            if(num!=0 && temp[0] == '0' ) break;
            if(num<=255){
                s.insert(ind + i + 1, 1, '.');
                find_ip(s, count+1);
                //remove dot for next iteration
                s.erase(s.begin()+ind+i+1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        find_ip(s, 0);
        return ans;
    }
=======================================================================================================
  95. Unique Binary Search Trees II

Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

   map<pair<int, int>, vector<TreeNode*>> mp;


  vector<TreeNode*> helper(int start, int end){
      if(start>end) return {NULL};

      if(start == end){
      TreeNode* root = new TreeNode(start);
       return  mp[{start, end}] = {root};
       }

       if(mp.find({start, end}) != mp.end()){
           return mp[{start, end}];
       }

  vector<TreeNode*>result;

      for(int i= start; i<=end; i++){
          vector<TreeNode*> left_bst = helper(start, i-1);
          vector<TreeNode*> right_bst = helper(i+1, end);

      for(TreeNode* leftRoot : left_bst){
          for(TreeNode* rightRoot : right_bst){
              TreeNode* root = new TreeNode(i);
              root->left = leftRoot;
              root->right = rightRoot;

              result.push_back(root);
          }
      }

      }  return  mp[{start, end}] = result;

  }

    vector<TreeNode*> generateTrees(int n) {

        return helper(1, n);
        
    }
=======================================================================================================
113. Path Sum II  
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

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
===========================================================================================================
  
126. Word Ladder II== Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
  
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

  ======================================================================================================
  131. Palindrome Partitioning== Given a string s, partition s such that every 
substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

   bool checkPal(string &str, int start, int end){
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void generatePalindrome(int idx, vector<string> &temp, vector<vector<string>> &result, string &s){
        if(idx == s.size()){
            result.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(checkPal(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                generatePalindrome(i + 1, temp, result, s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        generatePalindrome(0, temp, result, s);
        return result;
    }
  =====================================================================================================
    140. Word Break II= construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

   set<string> dict;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict)dict.insert(x);
        vector<string> res;
        rec(s, 0, "", res);
        return res;
    }

    void rec(string s, int beg, string curr, vector<string>& res) {
        if(beg==s.size()) {
            if(curr[0]==' ')curr = curr.substr(1);
            res.push_back(curr);
        }
        string temp = "";
        for(int i=beg;i<s.size();i++) {
            temp.push_back(s[i]);
            if(dict.count(temp)) {
                rec(s, i+1, curr + " " + temp, res);
            }
        }
    }
========================================================================================================
  
212. Word Search II = 

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

  Avoid Duplicate Words: Mark nodes in the Trie as visited once a word is found to avoid adding the same word multiple times.
Pruning: Stop exploring paths as soon as it is determined that they cannot form any valid word based on the Trie.

Trie Construction
Objective: Efficiently manage and search prefixes of the words.

What is a Trie?: A Trie (or prefix tree) is a data structure used to store a dynamic set of strings where keys are usually strings. It is particularly useful for problems involving prefix matching.

Building the Trie:

Insert Each Word: For each word in the list, insert it into the Trie. Each node represents a character, and the path from the root to a node represents a prefix.
Mark End of Words: At the end of each word, mark the node to indicate that a complete word ends at this node.

  Efficiency: By using the Trie, prefix matching is fast, and DFS ensures all potential words are found.
Avoidance of Redundant Computations: Proper use of the visited matrix and Trie node marking avoids unnecessary searches and duplicate results.
Complete Exploration: DFS ensures that every potential path is explored from each starting point on the board.
  
class TrieNode {
public:
    TrieNode* child[26] = {NULL};
    bool isWord = false;
};

class Solution {
public:
    //direction array
    int dir[5] = {-1, 0, 1, 0, -1};

    //function to add word in Trie
    void addWord(TrieNode* cur, string word) {
        for (auto ch : word) {
            if (!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new TrieNode();
            cur = cur->child[ch - 'a'];
        }
        cur->isWord = true;
    }

    void dfs(vector<string>& ans, string ds, TrieNode* cur, int i, int j,vector<vector<char>>& board,vector<vector<bool>> &vis) {
        if (!cur)   return;

        //if a word is found add it and mark it as false, to avoid redundancy 
        if (cur->isWord){
            ans.push_back(ds);
            cur->isWord = false;
        }

        vis[i][j] = true; //marking path as visited

        for (int del = 0; del < 4; del++) {
            int next_i = i + dir[del], next_j = j + dir[del + 1];
            //checking for out of bound condition, moving to next letter
            if (next_i < board.size() and next_j < board[0].size() and !vis[next_i][next_j] and cur->child[board[next_i][next_j] - 'a'])
                dfs(ans, ds + board[next_i][next_j],cur->child[board[next_i][next_j] - 'a'], next_i, next_j,board,vis);
        }
        vis[i][j]= false; //resetting the path to unvisited
    }

    vector<string> findWords(vector<vector<char>>& board,vector<string>& words) {
        //initializations
        TrieNode* trie = new TrieNode();
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        //adding all the words to Trie
        for (auto word : words)
            addWord(trie, word);

        vector<string> ans; //decalring answer array
        for (int i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                char ch = board[i][j];
                if(trie->child[ch-'a']) //if word exists call dfs
                    dfs(ans,string(1, ch), trie->child[ch-'a'], i, j, board,vis);
            }
        }
        return ans; //returning the answer array
    }
};
========================================================================================================
  
216. Combination Sum III
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

vector<vector<int>>result;

  void generate(int k, int n, vector<int>& nums, vector<int> &temp, int idx){
    if(n==0 && temp.size()==k){
        result.push_back(temp);
        return;
    }
    if(idx>= nums.size() || n<0) return;

    for(int i=idx; i<nums.size(); i++){
        temp.push_back(nums[i]);
        generate(k, n-nums[i], nums, temp, i+1);
        temp.pop_back();
        
    }
  }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums{1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        generate(k, n, nums, temp, 0);
        return result;
    }
========================================================================================================
  257. Binary Tree Paths
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
  
 void dfs(TreeNode* root, string temp, vector<string>& ans){
        // bc
        if(!root) return;
        if(!root->left && !root->right){
            temp+= to_string(root->val);
            ans.push_back(temp);

        }

        //task
        temp+= to_string(root->val) + "->";
        // rr
        dfs(root->left, temp, ans);
        dfs(root->right, temp, ans);

        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        dfs(root, temp, ans);
        return ans;

        
    }
=======================================================================================================
  282. Expression Add Operators
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.


vector<string>result;
int target;
string s;

   void solve(int i, const string& path, long prev, long prevnum){
    if(i==s.length()) {
        if(prev==target){
            result.push_back(path);
        }
        return;
    }
    string numstr;
    long num =0;
    for(int j = i; j<s.length(); j++){
        if(j>i && s[i]=='0') break;
        numstr += s[j];
        num = num*10 + s[j]-'0';
        if(i==0){
            solve(j+1, path+numstr, num, num);
        } else {
            solve(j+1, path+ "+" +numstr, prev+num , num);
            solve(j+1, path+ "-" +numstr, prev-num, -num);
            solve(j+1, path+ "*" +numstr, prev-prevnum+prevnum*num, prevnum*num);
        }
    }
   }

    vector<string> addOperators(string s, int target) {
        result = {};
        this->target = target;
        this->s = s;
        solve(0, "", 0, 0);
        return result;
    }
=======================================================================================================
  301. Remove Invalid Parentheses
Input: s = "()())()"
Output: ["(())()","()()()"]
  Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

     vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_removed = 0;
        int right_removed = 0;
        for(auto c : s) {
            if(c == '(') {
                ++left_removed;
            }
            if(c == ')') {
                if(left_removed != 0) {
                    --left_removed;
                }
                else {
                    ++right_removed;
                }
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", result);
        return vector<string>(result.begin(), result.end());
    }
private:
    void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()) {
            if(left_removed == 0 && right_removed == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        }
        else {
            if(s[index] == '(') {
                if(left_removed > 0) {
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result);
                }
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result);
            }
            if(s[index] == ')') {
                if(right_removed > 0) {
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result);
                }
            }
        }
    }
======================================================================================================
  

306. Additive Number
Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

  
Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199

  
 public boolean isAdditiveNumber(String num) {
        if (num.length() < 3) return false;

        return dfs(num, -1, -1, 0, false);
    }

    public boolean dfs(String nums, long ppre, long pre, int idx, boolean flag) {
        if (idx == nums.length()) {
            return flag;
        }

        long cur = 0;
        long n = ppre + pre;

        if (nums.charAt(idx) == '0') {
            if (ppre == -1 || cur == n) {
                return dfs(nums, pre, cur, idx + 1, ppre != -1);
            } else {
                return false;
            }
        } else {
            for (int i = idx; i < nums.length(); i++) {
                cur = cur * 10 + (nums.charAt(i) - '0');

                if (ppre == -1 || cur == n) {
                    if (dfs(nums, pre, cur, i + 1, ppre != -1)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
=======================================================================================================
357. Count Numbers with Unique Digits = Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.
  Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

 int countNumbersWithUniqueDigits(int n) {
     if(n==0) return 1;
     int total = 10; 
     int prod = 9;
     for(int i=2; i<n+1; i++){
        total += prod * (11 - i);
        prod*= 11-i;
     }
     return total;
=======================================================================================================
  473. Matchsticks to Square





















  








