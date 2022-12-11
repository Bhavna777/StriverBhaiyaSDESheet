// Problem Link :- https://www.codingninjas.com/codestudio/problems/chess-tournament_981299 




bool canPlace(vector<int> positions,int n,int c,int dist)
{
    int coord=positions[0];
    int count=1;
    for (int i=1;i<n;i++){
        if ((positions[i]-coord) >= dist){
            count++;
            coord=positions[i];
        }
        if (count == c){
            return true;
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
    int start = 1;
    int end = (positions[n-1]-positions[0]);
    int ans;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(canPlace(positions,n,c,mid)){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}