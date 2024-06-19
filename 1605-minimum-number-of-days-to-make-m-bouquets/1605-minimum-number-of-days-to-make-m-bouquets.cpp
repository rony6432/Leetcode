class Solution {
public:
    bool cal(int mid,vector<int>& bloomDay,int m,int k){
          int x=0;
          int b=0;
          int n=bloomDay.size();
          for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid) {
                x++;
            }
            else{
                b+=x/k;
                x=0;
            }
          }
          b+=x/k;
          return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(l<=r){
            int mid=(l+r)/2;
            if(cal(mid,bloomDay,m,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};