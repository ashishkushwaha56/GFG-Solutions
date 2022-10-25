class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        unordered_map<int,int>mb;
        for(int i = 0;i<n;i++){
            mb[a[i]]++;
        }
        int ans = 0;
        int i = n-1;
        while(i>=0){
            if(mb.find(a[i])!=mb.end() and mb.find(a[i]-1)!=mb.end()){
                ans+=a[i];
                mb[a[i]]--;
                mb[a[i]-1]--;
                if(mb[a[i]] == 0) mb.erase(a[i]);
                if(mb[a[i]-1] == 0 ) mb.erase(a[i]-1);
            }
            else if(mb.find(a[i])!=mb.end()){
                ans+=a[i];
                mb[a[i]]--;
                if(mb[a[i]] == 0) mb.erase(a[i]);
            }
            i--;
        }
        return ans;
    }

};
