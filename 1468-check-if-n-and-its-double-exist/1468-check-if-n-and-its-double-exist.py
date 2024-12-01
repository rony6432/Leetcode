class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
       for i in range(len(arr)):
        if(arr.count(2*arr[i])):
            if(i!=arr.index(2*arr[i])):
             return True
       return False     
