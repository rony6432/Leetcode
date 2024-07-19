class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
     int n=matrix[0].size();
     int max_n=INT_MIN;
     for(int i=0;i<m;i++){
     int min_n=INT_MAX;
         for(int j=0;j<n;++j)
             min_n=min(min_n,matrix[i][j]);
             max_n=max(min_n,max_n);
     }
     int min_n=INT_MAX;
     for(int j=0;j<n;++j){
         int max_n=INT_MIN;
         for(int i=0;i<m;i++)
             max_n=max(max_n,matrix[i][j]);
             min_n=min(max_n,min_n);
     }
        if(min_n!=max_n) return vector<int> { };
        return vector<int>{min_n};
    }
};