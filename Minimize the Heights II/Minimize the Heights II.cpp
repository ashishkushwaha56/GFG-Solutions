
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        if(n==1)
            return 0;
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];
        for(int i = 1;i<n;i++){
            if(arr[i]-k<0)
                continue;
            int _max = max(arr[i-1]+k,arr[n-1]-k);
            int _min = min(arr[0]+k,arr[i]-k);
            ans = min(ans,_max-_min);
        }
        return ans;
    }
};
