class Solution {
public:
bool ans(int f,vector<int>& position,int m){
    int c=1,mf=position[0];
    for(int i=1;i<position.size();i++){
               if(position[i]-mf>=f){
                   c++;
                   mf=position[i];
               }
    }
    return c>=m;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        
        int s=1,e=position.back()-position[0];
        while(e>=s){
          int mid=(s+e)/2;
          if(ans(mid,position,m)){
              s=mid+1;
          }
          else{
              e=mid-1;
          }
        }
        return e;
    }
};