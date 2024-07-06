class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0)return 0;
        stack<char>st;
        int n=s.size();
        int par_cnt=0;
        for(int i=0;i<n;i++){
          if(s[i]=='('){
            st.push(s[i]);
          }
          else{
            if(st.empty()){
                par_cnt++;
            }
            else{
                st.pop();
            }
          }
        }

        while(!st.empty()){
            par_cnt++;
            st.pop();
        }
        return par_cnt;

    }
};