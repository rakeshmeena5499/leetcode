bool canWePlace(vector<int>& stalls, int dist, int k){
    int count = 1;
    int coord = stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - coord >= dist){
            count++;
            coord = stalls[i];
        }
        if(count>=k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while(low<=high){
        int mid = (high+low)/2;
        if(canWePlace(stalls, mid, k)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}