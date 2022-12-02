// Problem Link :- https://www.codingninjas.com/codestudio/problems/873366 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> temp(n+1);
    pair<int,int> ans;
    for(int i=0;i<n;i++){
        int ind = arr[i];
        temp[ind]++;
    }
    
    for(int i=1;i<=n;i++){
        if(temp[i]==0){
            ans.first = i;
        }
        if(temp[i]>1){
            ans.second = i;
        }
    }
    return ans;
}
