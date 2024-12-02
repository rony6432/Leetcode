class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream s(sentence);
        string word;
        int i=0;
        while(s>>word) 
		    if(++i && word.find(searchWord) == 0 ) return i;
        return -1;
    }
};