class Solution {
public:
    int smallestNumber(int n) {
        int num=0;
        int cnt=0;
        while(n){
            cnt++;
            n=n>>1;
        }
        while(cnt){
           num=num<<1;
            num=num|1;
            cnt--;
        }
        return num;
    }
};