class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    temp[i][j]==0;
                }
                else{
                    if(i!=0  && j!=0)
                    temp[i][j]=1+(min(temp[i-1][j],min(temp[i][j-1],temp[i-1][j-1])));
                    else temp[i][j]=matrix[i][j];

                }
                cout<<temp[i][j]<<" ";
                maxi+=temp[i][j];
            }
            cout<<endl;
        }
        return maxi;
    }
};