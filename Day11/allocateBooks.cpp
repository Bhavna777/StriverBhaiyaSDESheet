// Problem Link :- https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574 



bool isPossible(vector<int>& time, int n, int m, int mid){
    long long int studentCount=1 , chapterSum=0;     
    for(int i=0;i<m;i++){   
        if(chapterSum + time[i] <= mid){  
            chapterSum= chapterSum + time[i];
        } else  {
            studentCount++;  
            if(studentCount > n || time[i] > mid){
                return false;
            }        
            chapterSum = time[i];
        } 
        if(studentCount>n){  
            return false;  
        }
    }
    return true; 
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) {	
	  long long int start=0, sum=0;   
      for(int i=0;i<m;i++){
           sum=sum+time[i];    
      }
      long long int end=sum, ans=-1, mid=start+(end-start)/2;
          while(start<=end){ 
          if(isPossible(time,n, m,mid)){
               ans=mid;
               end=mid-1;
           }else {
               start=mid+1;   
            }
           mid=start+(end-start)/2;
       }   

       return ans; 
}