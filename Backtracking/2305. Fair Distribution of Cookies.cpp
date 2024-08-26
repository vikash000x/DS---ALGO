Example 1:

Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
Example 2:

Input: cookies = [6,1,3,2,2,4,1,2], k = 3
Output: 7
Explanation: One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.

class Solution {
public:
int n;
int result = INT_MAX;

  void solve(int idx, vector<int>& cookies, vector<int> &children, int k){
    if(idx == cookies.size()) {
        int ans = *max_element(begin(children), end(children));

        result  = min(result, ans);
        return;
    }
    int candy = cookies[idx];
    for(int i=0; i<k; i++){
        children[i] += candy;
        solve(idx+1, cookies, children, k);
        children[i] -= candy;
    }

  }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int>children(k);
        solve(0, cookies,  children, k);
        return result;
    }
};
