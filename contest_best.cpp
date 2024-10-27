3332. Maximum Points Tourist Can Earn== Each day, the tourist has two choices:

Stay in the current city: If the tourist stays in their current city curr during day i, they will earn stayScore[i][curr] points.
Move to another city: If the tourist moves from their current city curr to city dest, they will earn travelScore[curr][dest] points.
Return the maximum possible points the tourist can earn.
Input: n = 2, k = 1, stayScore = [[2,3]], travelScore = [[0,2],[1,0]]
Output: 3
  Explanation
The tourist earns the maximum number of points by starting in city 1 and staying in that city.

  int solve(int i , int d,int& n, int& k, vector<vector<int>>& s, vector<vector<int>>& t, vector<vector<int>>&dp ){
         if(i>=n || d>=k) return 0;
          if(dp[i][d]) return dp[i][d];

          int p1= 0, p2 = 0;
          p1 = s[d][i] + solve(i, d+1, n, k,  s, t, dp);
          for(int j =0; j<n; j++){
            if(i==j) continue;
            int temp = t[i][j] + solve(j, d+1, n, k, s, t, dp);
            p2 = max(p2, temp);
          }
          return  dp[i][d] = max(p1, p2);
     }

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>>dp(n, vector<int>(k, 0));
        int res = 0;
    for(int  i=0; i<n; i++){
        int temp = solve(i, 0, n, k, stayScore, travelScore, dp);
        res = max(res, temp);
    }
    return res;
    }
==========================================================================================================
3336. Find the Number of Subsequences With Equal GCD
The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
  Return the total number of such pairs.

Input: nums = [1,2,3,4]

Output: 10

Explanation:

The subsequence pairs which have the GCD of their elements equal to 1 are:

([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])
([1, 2, 3, 4], [1, 2, 3, 4])...............

  const int mod = 1e9+7;
int dp[200][201][201];
   
   int solve(vector<int>&nums, int i, int first, int second){
    if(i==nums.size()){
        return (first && second) && (first==second);
    }
    if(dp[i][first][second] != -1) return dp[i][first][second];

    int skip = solve(nums, i+1, first, second);
    int take1 = solve(nums, i+1, __gcd(first, nums[i]), second);
    int take2 = solve(nums, i+1, first, __gcd(second, nums[i]));
    
    return dp[i][first][second] = (0LL + skip + take1 + take2)%mod;
   }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
========================================================================================================
  

  




















  
