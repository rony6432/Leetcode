class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
       int n=arr.size();
       int f=0;
       int t=0;
       int tw=0;
       for(int i=0;i<n;i++){
           if(arr[i]==5) f++;
           else if(arr[i]==10){
            if(f==0) return false;
            f--;
            t++;
           }
           else{
            if(f==0) return false;
            if(t!=0){
                t--;
                f--;
            }
            else{
                if(f<3) return false;
                 f-=3;
            }
           }
       }
       return true;
    }
};