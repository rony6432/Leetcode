class Node{
public:
 Node*link[26];
 bool flag=false;
 bool contain_Key(char ch){
    return (link[ch-'a']!=NULL);
 }
 void put(char ch,Node*node){
    link[ch-'a']=node;
 }
 Node* get(char ch){
    return link[ch-'a'];
 }
 void setEnd() {
    flag=true;
 }
 bool isEnd() {
 return flag;
 }
 
};
class Trie {
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
           if(!node->contain_Key(word[i])){
              node->put(word[i],new Node());
           }
           node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node*node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
          if(!node->contain_Key(word[i])) return false;
          node=node->get(word[i]);
        }
        if(node->isEnd())
         return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        int n=prefix.size();
        for(int i=0;i<n;i++){
            if(!node->contain_Key(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
        }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */