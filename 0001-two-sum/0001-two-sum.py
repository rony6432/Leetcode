class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i in range(len(nums)):
            if(dict.get(target-nums[i])!=None):
                return [dict[target-nums[i]],i]
            else:
                dict[nums[i]] =i   
        print(dict)        