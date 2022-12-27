// Problem LInk :- https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292


class Trie {
    public:
    Trie *child[26]={0};
    bool end=0;
};

int countDistinctSubstrings(string &s)
{
    int i;
    int j;
    int n = s.size();
    int ans = 0;
    Trie *root = new Trie();
    for(i=0; i<n; i++) {
       Trie *p=root;
        for(j=i; j<n; j++) {
            int index = s[j]-'a';
            if(p -> child[index] == 0) {
                ans++;
                p -> child[index] = new Trie();
            }
            p = p -> child[index];
        }
        p -> end = 1;
    }
    return ans+1;
}