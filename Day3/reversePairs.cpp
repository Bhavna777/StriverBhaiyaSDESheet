// Problem Link :- https://leetcode.com/problems/reverse-pairs 

void merge(vector<int>&nums,int low,int mid,int high,int &count){
    int i=low;
    int j=mid+1;
    
    while(i<=mid and j<=high)
    {
        if(nums[i]>2*1ll*nums[j])
        {
            count+=(mid-i+1);
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(nums.begin()+low,nums.begin()+high+1);
}


void mergeSort(vector<int>&nums,int low,int high,int &count){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(nums,low,mid,count);
        mergeSort(nums,mid+1,high,count);
        
        merge(nums,low,mid,high,count);
    }
}


int reversePairs(vector<int>& nums) {
    int n=nums.size();
    
    int count=0;
    mergeSort(nums,0,n-1,count);
    return count;
}