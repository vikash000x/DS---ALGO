Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

=============================================================================================
class Solution {
public:
int sum(vector<int>& arr){
    int sum = 0;
    for(int i=0; i<arr.size(); i++)
        sum += arr[i];
     return sum;
}

void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx){
    if(sum(curr)>target || idx>=candidates.size()) return;

    if(sum(curr) == target){ 
    result.push_back(curr);
    return;
    }
    curr.push_back(candidates[idx]);
    combination(candidates, target, curr, result, idx);
    curr.pop_back();
    combination(candidates, target, curr, result, idx+1);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;
        combination(candidates, target, curr, result, 0);
        return result;
    }

   
};
