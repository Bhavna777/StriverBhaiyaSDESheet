// Problem link :- https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769 


#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	int i = 0;
    int j = n-1 ; 
    
    while(i < j ){
        if( i == j )
            continue; 
        if(knows(i , j ))
            i++ ; 
        else
            j -- ;
    }
    
    int celebrity = i ; 
    
    for(int k=0; k<n; k++ ){
        if(k == celebrity )
            continue ; 

        if(!knows(k , celebrity) || knows(celebrity , k))
            return -1 ; 
    }

    return celebrity; 
}