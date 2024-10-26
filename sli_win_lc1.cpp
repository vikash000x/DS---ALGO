3. Longest Substring Without Repeating Characters==  Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

 int i = 0;
    int j =0;
    int ans = INT_MIN;
    unordered_map<char, int> mp;
    if(s.length()==0) return 0;
    while(j<s.length()){
    mp[s[j]]++;
    if(mp.size()==j-i+1){
        ans = max(ans, j-i+1 );
    }
    else if(mp.size()<j-i+1){
        while(mp.size()<j-i+1){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }

            i++;
        }
    }
    j++;
    }
         return ans;
    }
======================================================================================================
30. Substring with Concatenation of All Words

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

    // This is the reference map.
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;

        // Length of each word in words.
        unsigned int length = words[0].size();

        // Initializing the reference map.
        map.clear();
        for (const std::string& word : words)
            map[word]++;

        // Iterate for each offset
        // As many times as the number of characters in each word.
        for (unsigned int offset = 0; offset < length; ++offset) {
            // Sliding window size.
            unsigned int size = 0;
            // Sliding window memory.
            std::unordered_map<std::string, unsigned int> seen;

            // Iterate over the string, with the step equals to length.
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                // This is the word we're going to check.
                std::string sub = s.substr(i, length);

                // If the word is absent in the reference map,
                // we clear the sliding window and move on.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Increase the number of occurrences
                // of the word in seen map.
                ++seen[sub];
                ++size;

                // To make sure the sliding window is valid,
                // we need to check only the recent occurrence
                // against the reference,
                // because previous occurrences
                // were checked on previous iterations.
                while (seen[sub] > itr->second) {
                    // If the occurrences amount exceeds
                    // the reference amount,
                    // we shrink the window from the left until
                    // the window becomes valid again.

                    // A word at the beginning of the current sliding window.
                    std::string first = s.substr(i - (size - 1) * length, length);

                    // Remove the occurrence from the window,
                    // shrinking it from the left.
                    --seen[first];
                    --size;
                }
                
                // If we used all words from the words array,
                // we have found the correct spot
                // and we need to calculate the beginning
                // index of the current sliding window.
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }

==========================================================================================================
  76. Minimum Window Substring
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

  string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> charCount;
        for (char ch : t) {
            charCount[ch]++;
        }

        int targetCharsRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;

        for (int endIndex = 0; endIndex < s.length(); endIndex++) {
            char ch = s[endIndex];
            if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
                targetCharsRemaining--;
            }
            charCount[ch]--;

            if (targetCharsRemaining == 0) {
                while (true) {
                    char charAtStart = s[startIndex];
                    if (charCount.find(charAtStart) != charCount.end() && charCount[charAtStart] == 0) {
                        break;
                    }
                    charCount[charAtStart]++;
                    startIndex++;
                }

                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                charCount[s[startIndex]]++;
                targetCharsRemaining++;
                startIndex++;
            }
        }

        return minWindow[1] >= s.length() ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);        
    }
========================================================================================================
 187. Repeated DNA Sequences= return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
  Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

   vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() < 10) return result; // Handle short strings

        unordered_map<string, int> map;

        for (int i = 0; i <= s.length() - 10; ++i) {
            string substring = s.substr(i, 10);
            if (map.count(substring)) {
                if (map[substring] == 1) {
                    result.push_back(substring);
                }
                map[substring]++;
            } else {
                map[substring] = 1;
            }
        }
        
        return result;
    }
==========================================================================================================
  209. Minimum Size Subarray Sum
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
  
   int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,ans=0,maxi=INT_MAX;
        while(r<n)
        {
            ans+=nums[r];
            while(ans>=target)
            {
                ans-=nums[l];
                maxi=min(r-l+1,maxi);
                l++;
            }
            r++;
        }
        return maxi==INT_MAX ? 0:maxi;
        
    }

==========================================================================================================
  
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
===========================================================================================================
  239. Sliding Window Maximum
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

  
vector<int> maxSlidingWindow(vector<int>& v, int k) {
        unordered_map<int,int> mp;  
        priority_queue<int> heap;
        int j=0;
        vector<int> ans;
        while (j<v.size()) 
        {
            if (heap.size()<k)
            {
                heap.push(v[j]);
                mp[v[j]]++;
                if (heap.size() == k) 
                    ans.push_back(heap.top());
            } 
            else
            {
                mp[v[j - k]]--; 
                heap.push(v[j]);
                mp[v[j]]++;
                while (!heap.empty() && mp[heap.top()] == 0)
                    heap.pop();
                ans.push_back(heap.top());
            }
            j++;
        }
        return ans;
    }
==========================================================================================================
  395. Longest Substring with At Least K Repeating Characters
Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

   int longestSubstring(string s, int k) {
        int n = s.size(), maxlen = 0;

        for(int num_uniq = 1; num_uniq <= 26; ++num_uniq) 
          { 
            int count[128] = {0};
            int num_valid_uniq = 0, start = 0;

            for(int end = 0; end < n; ++end) {
                int index = s[end];
                if(count[index] == 0) num_valid_uniq++;
                count[index]++;

                while(num_valid_uniq > num_uniq) {
                    int index = s[start];
                    count[index]--;
                    if(count[index] == 0) num_valid_uniq--;
                    start++;
                }

                bool valid = true;
                for(int i = 0; i < 128; ++i) {
                    if(count[i] > 0 && count[i] < k) {
                        valid = false;
                        break;
                    }
                }
                if(valid) maxlen = max(maxlen, end - start + 1);
            }
        }

        return maxlen;
    }
int longestSubstring(string s, int k) {
        return longestsubstr(s, k, 0, s.length());
        
    }

    int longestsubstr(string s, int k, int start, int end){
        int count[26] = {0};
        for(int i =start; i<end; i++){
            count[s[i]-'a']++;
        }
        for(int i= start; i<end; i++){
            if(count[s[i]-'a']<k){
            int left = longestsubstr(s, k, start, i);
            int right = longestsubstr(s, k, i+1, end);
            return max(left, right);
        }
    }
    return end - start;
    }


==========================================================================================================
  413. Arithmetic Slices
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

 int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int i=0 , out=0;

        while(i<n){
            int j=i+1;
            while(j<n && nums[j]-nums[j-1] == nums[i+1]-nums[i]) j++;

            //add all subarrays of size>=3; consider a window of size x;
            //total subarrays -> x*(x+1)/2,
            //subarrays of size-1 -> x , subarrays of size-2 -> x-1;
            //thus, subarrays of size>=3 -> (x*(x+1)/2 - x - (x-1));
            int x=j-i;
            if(x>=3) out += (x*(x+1)/2 - x - (x-1));

            //for the case 1,2,3,4,6,8,10 -> first window starts at 1, 
            //and the second window should start at 4 (not 6);
            if(j<n-1 && nums[j+1]-nums[j]==nums[j]-nums[j-1]) i=j-1;    
            else i=j;
        }

        return out;
    }

 int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array.
        
        // If the array has less than 3 elements, it cannot have any arithmetic slices.
        if (n < 3)
            return 0;

        int c = 0; // Initialize the count of arithmetic slices.
        int currlen = 0; // Initialize the current length of the arithmetic slice.

        // Iterate through the array starting from the third element.
        for (int i = 2; i < n; i++) {
            // Check if the current element forms an arithmetic slice with the previous two elements.
            if ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2])) {
                currlen++; // Increment the current length of the arithmetic slice.
                c += currlen; // Add the current length to the count of arithmetic slices.
            } else {
                currlen = 0; // Reset the current length if the slice is broken.
            }
        }

        return c; // Return the total count of arithmetic slices.
==========================================================================================================
  424. Longest Repeating Character Replacement

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
    int characterReplacement(string s, int k) {
        unordered_map<char, int>alph;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxf = 0;
        for(right= 0; right<s.size(); right++){
            alph[s[right]] = 1+alph[s[right]];
            maxf = max(maxf, alph[s[right]]);

            if((right-left+1)-maxf >k){
                alph[s[left]] -= 1;
                left++;
            } else {
                ans = max(ans, (right-left+1));
            }
        } return ans;
=========================================================================================================
  438. Find All Anagrams in a String

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

  vector<int> findAnagrams(string s, string p) {
        if (p.size()>s.size())return {};
        map<char,int> freq;
        int p_len= p.size();
        for (auto val: p)freq[val]++;
        map<char,int> win;
        vector<int> ans;
        // first window;
        for (int i=0; i<p_len; i++){
            win[s[i]]++;
        }
        if (freq==win)ans.push_back(0);
        for (int i=p_len; i<s.size(); i++){
            win[s[i]]++;
            win[s[i-p_len]]--;
            if (win[s[i-p_len]]==0)win.erase(s[i-p_len]);
            if (freq==win)ans.push_back(i-p_len+1);
        }
        return ans;
    }
========================================================================================================
  480. Sliding Window Median
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
  ===========================================================================================================
  567. Permutation in String
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

   bool checkInclusion(string s1, string s2) 
    {
        unordered_map<char, int>mp, mp2;
        for(auto ch:s1) mp2[ch]++;

        int i = 0, j = 0, k = s1.size(), n = s2.size();
        while(j < n)
        {
            mp[s2[j++]]++;
            if(j - i == k)
            {
                if(mp == mp2) return true;
                mp[s2[i]]--;
                if(mp[s2[i]] == 0) mp.erase(s2[i]);
                i++;
            }
        }
        return false;
    }
===========================================================================================================
  594. Longest Harmonious Subsequence
Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].
  
 int findLHS(vector<int>& nums) {
        int res = 0, left = 0, right = 1, curIndex = 0;
        sort(nums.begin(), nums.end());
        while (right < nums.size()) {
            if (nums[right] - nums[left] == 1) {
                res = max(res, right - left + 1);
            }
            while(nums[right] - nums[left] > 1){
                ++left;
            }
            ++right;
        }
        return res;
    }
=========================================================================================================
  632. Smallest Range Covering Elements from K Lists
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

========================================================================================================
  
643. Maximum Average Subarray I
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
  

double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        double ans=sum;
        for(int i=k;i<n;i++)
        {
            sum=sum-nums[i-k]+nums[i];
            ans=max(ans,sum);
        }
        return ans/k;
    }

========================================================================================================
  658. Find K Closest Elements== An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

 vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> m;
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m.push_back({abs(arr[i]-x),i});
        }
        sort(m.begin(),m.end(),[](const pair<int, int>& a,
            const pair<int, int>& b) {
             if(a.first==b.first){
                return a.second<b.second;
             }
             else return a.first<b.first;
    });
    
    for(auto i:m){
        if(k)ans.push_back(arr[i.second]),k--;
        else break;
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
=====================================================================================================
713. Subarray Product Less Than K
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0 || k==1) return 0;
        int left=0,right=0;
        int mul = 1;
        int ans =0;
        while(right < n){
            mul *= nums[right];
            while(mul>=k && left < n){
                ans += right - left ;
                mul /= nums[left];
                left++;
            }
            right++;
        }

        return ans + (right - left) *(right - left + 1)/2 ;

    }
===========================================================================================================
  
718. Maximum Length of Repeated Subarray = return the maximum length of a subarray that appears in both arrays.

 Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

  int dp[1021][1002];
    int rec(int i , int j ) {
        if (i >= a.size() or j >= b.size() ) return  0 ;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (a[i] == b[j])
            ans  =   1 + rec(i + 1, j + 1);
        else ans  = 0 ;
        return dp[i][j] = ans ;
    }
    int findLength(vector<int>& a, vector<int>& b) {
        int ans = 0 ;
        for (int i = 1 ; i <= a.size() ; i++) {
            for (int j = 1 ; j <= b.size() ; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans  ;

    }
=======================================================================================================
  837. New 21 Game

Input: n = 6, k = 1, maxPts = 10
Output: 0.60000
Explanation: Alice gets a single card, then stops.
In 6 out of 10 possibilities, she is at or below 6 points.


=======================================================================================================
  862. Shortest Subarray with Sum at Least K===return the length of the shortest non-empty subarray of nums with a sum of at least k

Input: nums = [2,-1,2], k = 3
Output: 3

  
   int shortestSubarray(vector<int>& nums, int k) {
			int len = INT_MAX;
			long long sum = 0;
			vector<int> positive;
			for (int i = 0, j = 0; j < nums.size(); ++j) {
				sum += nums[j];
				if (nums[j] < 0) {
					// Incorporate negative nums[j] into positive elements before it
					int r = nums[j];
					while (!positive.empty()) {
						int cur = positive.back();
						r += nums[cur];
						nums[cur] = r;
						nums[j] = 0;
						positive.pop_back();
						if (r < 0 && !positive.empty() && positive.back() >= i) {
							nums[cur] = 0;
						}
						else {
							positive.push_back(cur);
							break;
						}
					}
				}
				else { // positive nums[j]
					positive.push_back(j);

					while (i <= j && (sum-nums[i] >= k || nums[i]<=0))
						sum -= nums[i++];
					
					if (sum >= k) 
						len = min(len, j - i + 1);
				}
			}
			return len == INT_MAX ? -1 : len;
    }
======================================================================================================
  904. Fruit Into Baskets
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

  int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> feq;
        int maxf = 0, n = fruits.size(), uf = 0;
        for(int l = 0, r = 0; l < n; l++) {
            feq[fruits[l]]++;
            if(feq[fruits[l]] == 1)
                uf++;
            while(uf > 2) {
                feq[fruits[r]]--;
                if(feq[fruits[r]] == 0)
                    uf--;
                r++;
            }
            maxf = max(maxf, l - r + 1);
        }
        return maxf;
    }
=============================================================================================================
 930. Binary Subarrays With Sum
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

   int countgoal(vector<int>& nums, int goal){
        int n = nums.size(), ans = 0, sum = 0;
        int left = 0, right = 0;
        
        while(right < n){
            sum += nums[right];

            while(sum > goal && left <= right){
                sum -= nums[left];
                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int x = countgoal(nums, goal);
        int y = countgoal(nums, goal - 1);
        Compute the number of subarrays with sum exactly equal to the goal by subtracting the count of subarrays with sum ≤ goal - 1 from the count of subarrays with sum ≤ goal.
        return x - y;
    }

==============================================================================================================
  978. Longest Turbulent Subarray







  





  
