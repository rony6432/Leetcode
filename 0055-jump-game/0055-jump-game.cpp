class Solution {
public:
    bool canJump(vector<int>& nums) {
        int p=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            p=max(p,nums[i]);
            if(p==0) return false;
            p--;
        }

        return true;
    }
};