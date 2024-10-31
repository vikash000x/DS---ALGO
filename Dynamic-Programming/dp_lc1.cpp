300. Longest Increasing Subsequence
Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.



 int lengthOfLIS(vector<int>& nums) {
           if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
=================================================================================================

845. Longest Mountain in Array
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

 int longestMountain(vector<int>& arr) {
  int n = arr.size();
        vector<int>dp(n, 1);
        vector<int>dp2(n, 1);
         for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){ dp[i] = dp[i-1] + 1;}
         }
         for(int i = n-2; i>=0; i--){
            if(arr[i]>arr[i+1]) {dp2[i] = 1 + dp2[i+1];}
         }
         int ans =  0;
         for(int i=0; i<n; i++){
            if(dp[i]>1 && dp2[i]>1){
                ans = max(dp[i]+dp2[i]-1, ans);
            }
         } return ans;
===================================================================================================
  1671. Minimum Number of Removals to Make Mountain Array

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].

  int minimumMountainRemovals(vector<int>& nums) {
      int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        // Compute LIS up to each index
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Compute LDS from each index
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int maxMountainLength = 0;

        // Find the maximum mountain length
        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {  // Valid peak
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }

        return n - maxMountainLength;  
    }
=================================================================================================
  5. Longest Palindromic Substring

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
  
string lcs(string s, string t){
        int n = s.size();
        int m = t.size();
      vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i<n; i++) dp[i][0] = 0;
        for(int j = 0; j<m; j++) dp[0][j] = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(s[i-1]==t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m] ;
    }

        string longestPalindrome(string s) {
            string t= s;
            reverse(t.begin(), t.end());
            return lcs(s, t);
        }
=================================================================================================
10. Regular Expression Matching
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
  

   bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for(int i=1; i<=s.size(); i++) dp[i][0] = false;
        for(int j=1; j<=p.size(); j++){
            if(p[j-1] != '*'){
                dp[0][j] = false;
            } else {
                dp[0][j] = dp[0][j-2];
            }
        }
         for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=s.size(); j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                    if((s[i-1]==p[j-2]) || (p[j-2]=='.')) dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
         } return dp[s.size()][p.size()];
    }
==================================================================================================
44. Wildcard Matching
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
  Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

   bool matching(string &p, string &s, int i, int j, vector<vector<int>> &dp){
    if(i<0 && j<0) return 1;
    if (i<0 && j>=0) return 0;
    if(j<0){
        while(i>=0){
        if(p[i]!='*') return 0;
        i--;
    } return 1;
    }
    if(dp[i][j]!= -1) return dp[i][j];
    if(p[i]==s[i] || p[i]=='?') return dp[i][j] = matching(p,  s, i-1, j-1, dp);
    if(p[i]=='*'){
        return dp[i][j] = matching(p, s, i-1, j, dp) || matching(p, s, i, j-1, dp);
    }
    return dp[i][j] = 0;
   }
    bool isMatch(string s, string p) {
 int m=p.size(), n = s.size();
 vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
 return matching(p, s, m-1, n-1, dp);       
    }

   bool isMatch(string s, string p) {
 int m=p.size(), n = s.size();
 vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
 //return matching(p, s, m-1, n-1, dp);
   dp[0][0] = 1;
   for(int i=1; i<=m; i++){
    if(p[i-1] == '*') dp[i][0] = dp[i-1][0];
    else break; 
   }
   for(int i =1;i<=m; i++){
    for(int j =1; j<=n; j++){
        if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j] = dp[i-1][j-1];
        else if(p[i-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
      //  else dp[i][j] =0;
    }
   }
  return dp[m][n];
        
        
    }
=============================================================================================
  55. Jump Game == Return true if you can reach the last index, or false otherwise.
  Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

   bool rec(vector<int>&arr,int ind,vector<int>&dp){
        if(ind==arr.size()-1)return true;
        if(arr[ind]==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=1;i<=arr[ind];i++){ 
            if(i<arr.size() and rec(arr,i+ind,dp))
           return dp[ind]=true;
        }
        return dp[ind]=false;
    }
 bool canJump(vector<int>& arr) {
        vector<int>dp(arr.size(),-1);
        return rec(arr,0,dp);
    }
================================================================================================
  45. Jump Game II = Return the minimum number of jumps to reach nums[n - 1]
vector<int> dp; // Memoization array
    
    int solve(int index, vector<int>& nums) {
        if (index >= nums.size() - 1) return 0; // Base case: if at or beyond the last index
        if (dp[index] != -1) return dp[index]; // Return cached result if available
        
        int ans = INT_MAX / 2; // Initialize to a large value (avoid overflow)
        
        for (int i = 1; i <= nums[index]; ++i) {
            if (index + i < nums.size() - 1 && dp[index + i] != -1) {
                ans = min(ans, 1 + dp[index + i]); // Use memoized result
            } else {
                ans = min(ans, 1 + solve(index + i, nums)); // Recur for the next index
            }
        }
        
        return dp[index] = ans; // Store result in dp array
    }
    
public:
    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1); // Initialize dp array with -1
        return solve(0, nums); // Start recursion from index 0
    }
===================================================================================================
  1306. Jump Game III = When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
 Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

  bool func(vector<int>& arr, vector<int> &visited,int i)
    {
        if(i<0||i>=arr.size()||visited[i]==1) return false;
        if(arr[i]==0) return true;
        visited[i]=1;
        return func(arr,visited,i-arr[i])||func(arr,visited,i+arr[i]);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(),0);
        return func(arr,visited,start);
    }
================================================================================================
  53. Maximum Subarray


  



  
  


  















  
