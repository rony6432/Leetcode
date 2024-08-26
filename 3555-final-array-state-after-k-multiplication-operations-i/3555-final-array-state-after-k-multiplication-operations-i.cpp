class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
            int number=pq.top().first;
            int pos=pq.top().second;
            pq.pop();
            number*=multiplier;
            pq.push({number,pos});
        }
        vector<int>ans(n);
        while(!pq.empty()){
            int number=pq.top().first;
            int pos=pq.top().second;
            pq.pop();
            ans[pos]=number;
        }
        return ans;
    }
};