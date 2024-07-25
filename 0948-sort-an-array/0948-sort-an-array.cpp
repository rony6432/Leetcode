class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums){
        int l=low,r=mid+1;
        vector<int>temp;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            else{
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void mergesort(int low,int high,vector<int>& nums){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(0,n-1,nums);
        return nums;
    }
};