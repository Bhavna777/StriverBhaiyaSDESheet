// Problem Link :- https://leetcode.com/problems/merge-sorted-array/ 

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int nums3[1000] = {0};
    int k = 0;
    int i = 0;
    int j = 0;
    while(i<m && j<n){
        if(nums1[i]<=nums2[j]){
            nums3[k] = nums1[i];
            k++;
            i++;
        }else{
            nums3[k] = nums2[j];
            k++;
            j++;
        }
    }

    while(i<m){
        nums3[k] = nums1[i];
        k++;
        i++;
    }
    while (j<n)
    {           
        nums3[k] = nums2[j];
        k++;
        j++;
    }
    
    for (int l = 0; l < m+n; l++) {
        nums1[l] = nums3[l];
    }
}