// Problem Link :- https://leetcode.com/problems/median-of-two-sorted-arrays/description/ 



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int a[2000] = {};
    int k = 0;
    int i = 0;
    int j = 0;
    float ans = 0;
    
    while(i < m){
        a[k]  = nums1[i];
        i++;
        k++;
    }
    while(j < n){
        a[k]  = nums2[j];
        j++;
        k++;
    }
    
    sort(a, a + k);
    
    cout << k;
    
    if(k%2 == 0){
        float med = a[(k/2)-1] + a[(k/2)];
        ans = med/2;
    }else{
        ans = a[k/2];
    }

    return ans;
}