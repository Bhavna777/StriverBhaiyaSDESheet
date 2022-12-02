// Problem Link :- https://www.codingninjas.com/codestudio/problems/count-inversions_615 

long long getInversions(long long *arr, int n){
    long long int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }  
    }
    return count;
}