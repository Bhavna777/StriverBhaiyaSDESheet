// Problem Link :- https://www.codingninjas.com/codestudio/problems/1115652 

int subarraysXor(vector<int> &arr, int x){
    unordered_map<int,int>v;
    int temp = 0;
    long long ans = 0;
    for(int i=0; i<arr.size();i++){
        temp = temp^arr[i];
        if(temp == x){
           ans++;   
        }
        int key = temp^x;
        if(v.find(key)!=v.end()){
            ans = ans + v[key];
        }
        v[temp]++;
    }
    return ans;
}