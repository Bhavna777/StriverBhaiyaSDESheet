// Problem Link :- https://www.codingninjas.com/codestudio/problems/893000 



int minCharsforPalindrome(string str) {
	int n = str.size();
    int start = 0;
    int end = n-1;
    int temp = end;
    int count = 0;
    
    while(start < end){
        if(str[start] == str[end]){
            start++;
            end--;
        }
        else{
            count++;
            start = 0;
            temp--;
            end = temp;
        }
    }
    return count; 
}
