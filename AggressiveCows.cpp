    bool isPossible(vector<int> &stalls, int k, int mid){
        int cowCount = 1;
        int lastPos = stalls[0];
        for(int i=0; i < stalls.size(); i++){
            if(stalls[i] - lastPos >= mid){
                cowCount++;
                if(cowCount == k){
                    return true;
                }
                lastPos = stalls[i];
            }
        }
        return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort( stalls.begin(), stalls.end());

    int min = 0;
    int maxi = -1;
    for(int i=0; i <stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }
    
    
    int ans = -1;
    int mid= (min+ (maxi-min)/2);
    while(min <= maxi){
        if(isPossible(stalls, k, mid)){
            ans = mid;
            min = mid + 1;
        }
        else{
            maxi = mid-1;
        }
        mid = min + (maxi-min)/2;
    }
    return ans;
}
