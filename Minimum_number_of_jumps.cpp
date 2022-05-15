#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int minJumps(int arr[], int n){
        int maxr=arr[0];
        int step=arr[0];
        int jump=1;
        if(n==1) return 0;
        else if(arr[0]==0) return -1;
        else{
            for(int i=1;i<n;i++){
                if(i==n-1){
                    return jump;
                }
                maxr=max(maxr,i+arr[i]);
                step--;
                if(step==0){
                    jump++;
                    if(i>=maxr){
                        return -1;
                    }
                    step=maxr-i;
                }
            }
            return maxr;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        n=5;
        int arr[]={2,3,1,2,1};
        // cin>>n;
        // int arr[n];
        // for(int i=0; i<n; i++)
        //     cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}