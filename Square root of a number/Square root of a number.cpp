// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long l = 0;
        long long r = x;
        long long ans = l;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid<x){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};
