// Problem Link :- https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool compare(Item &a,Item &b)

    {
        double c1 = (double) a.value/a.weight;
        double c2 = (double) b.value/b.weight;

        
        if(c1>c2) return true;

        return false;

    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        
        sort(arr, arr + n, compare);
        
        for(int i=0; i<n; i++){
            int itemWeight = arr[i].weight;
            int itemValue = arr[i].value;
            if(itemWeight <= W){
                ans = ans + itemValue;
                W = W - itemWeight;
            }else {
                ans = ans + itemValue * (double)W/itemWeight;
                break;
            }
        }

        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends