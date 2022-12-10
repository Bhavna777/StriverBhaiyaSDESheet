// Problem Link :- https://leetcode.com/problems/n-queens 



bool isValidPosition(vector<int>& temp, int index, int col){
    int n = temp.size(), i;
    for(i=0; i<index; i++){
        if(col==temp[i] || abs(index-i) == abs(col-temp[i])){
            return false;
        }
    }
    
    return true;
}

vector<string> convertFormat(vector<int> temp){
    int n = temp.size(), i;
    vector<string> result;
    result.resize(n);
    for(i=0; i<n; i++)
        result[i].resize(n, '.');
        
    for(i=0; i<n; i++)
        result[i][temp[i]] = 'Q';
        
    return result;
}

void solve(vector<int>& temp, int index, vector<vector<string>>& ans){
    int n = temp.size();
    for(int i=0; i<n; i++){
        if(isValidPosition(temp, index, i)){
            temp[index] = i;
            if(index == n-1){
                ans.push_back(convertFormat(temp));
                break;
            }else{
                solve(temp, index+1, ans);
            }       
        }
    }
}    

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>>ans;
    vector<int>temp(n);
    solve(temp, 0, ans);
    return ans;
}