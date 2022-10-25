class Solution {
  public:
  vector<int> ans;
  void f(vector<vector<int>> &a,int i, int j,int temp,int &upper,int &lower, int &left,int &right){
    //   cout<<a[i][j]<<" "<<"("<<i<<", "<<j<<")"<<endl;
      if(temp == 0){
          if(j<right){
            f(a,i,j+1,temp,upper,lower,left,right);
            ans.push_back(a[i][j]);
          }
          else if(i<lower){
              upper++;
              f(a,i+1,j,1,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else{
              ans.push_back(a[i][j]);
          }
      }
      else if(temp == 1){
          if(i<lower){
              f(a,i+1,j,temp,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else if(j>left){
              right--;
              f(a,i,j-1,2,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else{
              ans.push_back(a[i][j]);
          }
      }
      else if(temp == 2){
          if(j>left){
              f(a,i,j-1,temp,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else if(i>upper){
              lower--;
              f(a,i-1,j,3,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else{
              ans.push_back(a[i][j]);
          }
      }
      else if(temp == 3){
          if(i>upper){
              f(a,i-1,j,temp,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else if(j<right){
              left++;
              f(a,i,j+1,0,upper,lower,left,right);
              ans.push_back(a[i][j]);
          }
          else{
              ans.push_back(a[i][j]);
          }
      }
  }
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        int upper = 0,left = 0;
        int lower = R-1,right = C-1;
        f(a,0,0,0,upper,lower,left,right);
        return ans;
    }
};
