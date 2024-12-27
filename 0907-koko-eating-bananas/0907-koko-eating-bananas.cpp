class Solution {
public:
bool cnt(int mid,vector<int>& piles,int h){
    long long a=0;
    for(int i=0;i<piles.size();i++){
        if(piles[i]<=mid) a++;
        else{
            int x=piles[i]/mid;
            a+=x;
            int y=piles[i]%mid;
            if(y) a+=1;
        }
    }
    return a<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(cnt(mid,piles,h)) {
                ans=min(ans,mid);
                r=mid-1;
            } 
            else l=mid+1;
        }
        return ans;

    }
};