
class Disjoint_set{
vector<int>size,parent;
   public:
   Disjoint_set(int n){
    size.resize(n);
    parent.resize(n);
    for(int i=0;i<n;i++){
        size[i]=1;
        parent[i]=i;
    }
   }
   int find_parent(int node){
    if(parent[node]==node) return node;

    return parent[node]=find_parent(parent[node]);
   }
   void Union(int node1,int node2){
    int ult_par1=find_parent(node1);
    int ult_par2=find_parent(node2);
    if(ult_par1==ult_par2) return;
    else if(size[ult_par1]>=size[ult_par2]){
        parent[ult_par2]=ult_par1;
        size[ult_par1]+=size[ult_par2];
    }
    else{
         parent[ult_par1]=ult_par2;
        size[ult_par2]+=size[ult_par1];
    }
   }
   int Distint_provinces(){
    int cnt=0;
    for(int i=0;i<parent.size();i++){
        if(parent[i]==i) cnt++;
    }
    return cnt;
   }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       Disjoint_set D(n);
       int cnt=0;
       for(int i=0;i<connections.size();i++){
        int node1=connections[i][0];
        int node2=connections[i][1];
        int par1=D.find_parent(node1);
        int par2=D.find_parent(node2);
        if(par1==par2) cnt++;
        else{
            D.Union(node1,node2);
        }
       }
       int check=D.Distint_provinces();
       cout<<cnt<<" "<<check;
       if(check-1<=cnt) return check-1;

       return -1; 
        
    }
};