// Problem Link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m, int n, int i, int j, vector<string>&ans, string s, vector<vector<int>>& temp, int t1[], int t2[]){
        
        if (i == n - 1 && j == n - 1) {
          ans.push_back(s);
          return;
        }
        
        string direction = "DLRU";
        for (int index = 0; index < 4; index++) {
            
          int nexti = t1[index] + i;
          int nextj = t2[index] + j;
          
          if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !temp[nexti][nextj] && m[nexti][nextj] == 1) {
            temp[i][j] = 1;
            solve(m, n, nexti, nextj, ans, s + direction[index], temp, t1, t2);
            temp[i][j] = 0;
          }
          
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        
        vector<vector<int>>temp(n, vector < int > (n, 0));
        
        int t1[] = {+1, 0, 0, -1};
        int t2[] = {0, -1, 1, 0};
        
        if (m[0][0] == 1){
            solve(m, n, 0, 0, ans, "", temp, t1, t2);
        } 
          
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends