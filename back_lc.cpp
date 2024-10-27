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
  
















