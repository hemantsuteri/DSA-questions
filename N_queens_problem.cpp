#include <bits/stdc++.h>
using namespace std;
class Solution{
public:      
        
    vector<vector<int>> ans;
        int row[20];
        bool is_Safe(int r, int c)
        {
            for(int i=0; i<c; i++) 
            {
                if(row[i] == r or abs(row[i] -r) == abs(i-c)){
                    return false;
                }
            }
            return true;
        }
        
        bool backtrack(int c, int n)
        {
            if(c<n){
                for(int i=0; i<n;i++){
                    if(is_Safe(i,c)==1)
                    {
                        row[c]=i;
                        backtrack(c+1, n);
                    }
                }
            }
            else
            {
                vector<int> v;
                for(int i=0; i<n; i++){
                    v.push_back(row[i]+1);
                }
                ans.push_back(v);
            }
        }
        vector<vector<int>> nQueen(int n) {
        ans.clear();
        backtrack(0,n);
        
        return ans;
        }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
} 