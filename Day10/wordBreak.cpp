// Problem Link :- https://www.codingninjas.com/codestudio/problems/983635 



void solve(string& s, int index, map<string, bool>& mp, string tempStr, vector<string>&ans){
    if(index == s.size()){
        ans.push_back(tempStr);
        return ;
    }
    
    for(int i=index; i<s.size(); i++){
        string key = s.substr(index, i-index+1);
        if(mp[key]){
            solve(s, i+1, mp, tempStr+key+" ", ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    map<string,bool> mp;
    for(auto& x:dictionary) mp[x]=true;
    vector<string>ans;
    solve(s, 0, mp,"",ans);
    return ans;
}