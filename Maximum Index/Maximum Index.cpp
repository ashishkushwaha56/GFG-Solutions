   class Solution{ 
     public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        vector<int> left_min(N),right_max(N);
        left_min[0] = A[0];
        for(int i = 1;i<N;i++){
            left_min[i] = min(left_min[i-1],A[i]);
        }
        right_max[N-1] = A[N-1]; 
        for(int i = N-2;i>=0;i--){
            right_max[i] = max(right_max[i+1],A[i]);
        }
        int ans = INT_MIN;
        int i = 0;
        int j = 0;
        while(i<N and j<N){
            if(left_min[i]<=right_max[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
