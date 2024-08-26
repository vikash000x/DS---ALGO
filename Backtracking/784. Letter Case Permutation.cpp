Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]

 void gen_2(int start, string s, vector<string>& result){
    result.push_back(s);
    if(start==s.length()){

        return;
    }
    for(int i =start; i<s.length(); i++){
        if(!isalpha(s[i])) continue;
        s[i] = islower(s[i])? (char)toupper(s[i]):(char)tolower(s[i]);
        gen_2(i+1, s, result);
        s[i] = islower(s[i])?(char)toupper(s[i]): (char)tolower(s[i]);
    }
 }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        gen_2(0, s, result);
     //   generate_1("", s, result);
        return result;
    }
};
  
