class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                //swap(nums[i],nums[i-1]);
                ind=i;
                break;
            }
        }
        
        if(ind==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>=ind;i--){
            if(nums[i]>nums[ind-1]){
                swap(nums[i],nums[ind-1]);
                break;
            }
        }
            reverse(nums.begin()+ind,nums.end());
        }
    }
};