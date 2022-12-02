// Problem Link :- https://leetcode.com/problems/rotate-image/ 


void transpose(vector<vector<int>>& matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverse(vector<vector<int>>& matrix, int n){
    for(int i=0; i<n; i++){
        int start = 0;
        int end = n - 1;
        while(start <= end){
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    transpose(matrix, n);
    reverse(matrix, n);
}