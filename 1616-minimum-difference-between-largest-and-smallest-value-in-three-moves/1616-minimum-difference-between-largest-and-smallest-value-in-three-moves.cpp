class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4)
        return 0;
        int mini=INT_MAX;
       int n=nums.size();
       int diff=(abs(nums[nums.size()-1]-nums[3]));
        diff=min((abs(nums[nums.size()-4]-nums[0])),diff);
        diff=min(diff,abs(nums[n-2]-nums[2]));
        diff=min(diff,abs(nums[n-3]-nums[1]));
       return diff;
    }
};