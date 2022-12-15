// Problem LInk :- https://leetcode.com/problems/reverse-words-in-a-string/ 


string reverseWords(string s) {
    vector<string> str;
    stringstream temp(s);
    string ans;
    while(temp>>ans)
        str.push_back(ans);

    for(int i=str.size()-2; i>=0; i--){
        ans.append(" ");
        ans.append(str[i]);
    }
    
    return ans;
}