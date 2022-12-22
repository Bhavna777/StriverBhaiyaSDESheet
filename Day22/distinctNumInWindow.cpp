// Problem Link :- https://www.interviewbit.com/problems/distinct-numbers-in-window


vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    map<int, int> m;
    
    for(int i = 0;i<B;i++){
        m[A[i]]++;
    }
    
    int k = 0;
    for(int i =B;i<A.size();i++){
        ans.push_back(m.size());
        m[A[k]]--;
        if(m[A[k]] == 0) m.erase(A[k]);
        m[A[i]]++;
        k++;
    }
    
    ans.push_back(m.size());
    return ans;
}