Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

  =====================1st approach==================================================================================

  class Solution {
public:
 vector<vector<int>> result;
  void generate(vector<int>& nums, vector<int>& temp, int k, int n, int idx){
   if(n==0 && temp.size()==k){ 
   result.push_back(temp);
  return;}
   if(idx>= nums.size() || n<0) return;

   for(int i=idx; i<nums.size(); i++){
    temp.push_back(nums[i]);
    generate(nums, temp, k, n-nums[i], i+1);
    temp.pop_back();
   }
  }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums{1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        generate(nums, temp, k, n, 0);
        return result;
    }
};

=======================2nd approach=====================================

  class Solution {
public:
vector<vector<int>>result;
 void generate(int num, vector<int>& temp, int k, int n){
    if(n==0 && temp.size()==k){
        result.push_back(temp);
        return;
    }
    if(num>=10 || n<0) return;

    for(int i=num; i<10; i++){
        temp.push_back(i);
        generate(i+1, temp, k, n-i);
        temp.pop_back();
    }
 }
    vector<vector<int>> combinationSum3(int k, int n) {
        int num = 1;
        vector<int>temp;
        generate(num, temp, k, n);
        return result;
    }
};
