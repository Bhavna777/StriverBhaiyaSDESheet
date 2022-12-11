// Problem Link :- https://www.codingninjas.com/codestudio/problems/873378 



int upper_bound(vector<int> const &arr, int start, int end, int val){

    while (start < end){
        int mid = (start + end) / 2;

        if (arr[mid] > val){
            end = mid;
        }else{
            start = mid + 1;
        }
    }

    return start;
}

int getMedian(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    int start = 1, end = 100000;

    while (start < end){

        int mid = (start + end) / 2;
        int count = 0;
        for (int i = 0; i < n; i++){
            count = count + upper_bound(matrix[i], 0, matrix[i].size(), mid);
        }

        if (count >= (n * m + 1) / 2){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return start;
}