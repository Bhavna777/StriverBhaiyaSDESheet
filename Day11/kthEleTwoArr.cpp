// Problem Link :- https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1 



int kthElement(int arr1[], int arr2[], int n, int m, int k){
    int i=0,j=0,temp=0;
    while(i<n && j<m){   
        if(arr1[i]<arr2[j]){
            temp++;
            if(temp==k)
                return arr1[i];
            i++;
        }else{
            temp++;
            if(temp==k)
                return arr2[j];
            j++;
        }
    }

    while(i<n){
        temp++;
        if(temp==k)
            return arr1[i];
        i++;
    }

    while(j<m){
        temp++;
        if(temp==k)
            return arr2[j];
        j++;
    }
}