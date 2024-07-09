class Solution {
public:
   vector<int>next(vector<int>row){
     int n=row.size();
     vector<int>next_sm(n,-1);
     stack<int>st;
     for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else {
            while(!st.empty()&&row[st.top()]>row[i]){
                next_sm[st.top()]=i;
                st.pop();
                cout<<i<<" ";
            }
             st.push(i);
           
        }

    }
     for(int i=0;i<n;i++) cout<<next_sm[i]<<" ";
     cout<<endl;
    return next_sm;

   }
   vector<int>pre(vector<int>row){
        int n=row.size();
        vector<int>pre_sm(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
        }
        else {
            while(!st.empty()&&row[st.top()]>row[i]){
                pre_sm[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
     for(int i=0;i<n;i++) cout<<pre_sm[i]<<" ";
     cout<<endl;
    return pre_sm;
   }
   int hist(vector<int>row){
    int n=row.size();
    vector<int>pre_sm=pre(row);
    vector<int>next_sm=next(row);
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int temp=row[i];

        if(next_sm[i]!=-1)
        temp=temp+(row[i]*(next_sm[i]-i-1));
        else temp=temp+(row[i]*(n-i-1));

        if(pre_sm[i]!=-1)
        temp=temp+(row[i]*(i-pre_sm[i]-1));
        else temp=temp+(row[i]*(i-0));

        maxi=max(maxi,temp);
    }
    cout<<maxi<<endl;
    return maxi;
   
   }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MIN;
        vector<int>row(m,0);
        for(int i=0;i<n;i++){   
            for(int j=0;j<m;j++){
              if(matrix[i][j]=='0') row[j]=0;
              else row[j]=row[j]+matrix[i][j]-'0';
            }
            for(int k=0;k<m;k++) cout<<row[k]<<" ";
            cout<<endl;
            int temp=hist(row);
            maxi=max(temp,maxi);
        }
        return maxi;
    }
};