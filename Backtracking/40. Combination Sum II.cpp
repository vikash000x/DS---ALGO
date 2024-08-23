Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

  class Solution {
public:
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
};
