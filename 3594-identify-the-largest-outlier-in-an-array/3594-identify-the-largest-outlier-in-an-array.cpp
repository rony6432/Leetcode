class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans=INT_MIN,sum=0;
        unordered_map<int,int>mp;
        for(auto it: nums){
            sum+=it;
            mp[2*it]++;
        }
        for(auto it:nums){
            int t=sum-it;
            if(mp[t]>=2 ||mp[t]==1 &&(t!=2*it)) ans=max(ans,it);
        }
        return ans;
    }
};