// Problem Link :- https://www.codingninjas.com/codestudio/problems/implement-trie_1387095


#include <bits/stdc++.h> 

struct TrieNode
{
    TrieNode *children[26];
    int cp=0;
    int end=0;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        cp=0;
        end=0;
    }
};

class Trie{

    public:

    TrieNode *root;
    
    
    Trie(){
        root=new TrieNode();
    }

    void insert(string &word){
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
            if(curr->children[word[i]-'a']==NULL)
            curr->children[word[i]-'a']=new TrieNode();
            curr=curr->children[word[i]-'a'];
            curr->cp+=1;
        }
         curr->end+=1;
    }

    int countWordsEqualTo(string &word){
       TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
           if(curr->children[word[i]-'a']==NULL)
           return 0;
           curr=curr->children[word[i]-'a'];
        }
        return curr->end;  
    }

    int countWordsStartingWith(string &word){
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
           if(curr->children[word[i]-'a']==NULL)
           return 0;
           curr=curr->children[word[i]-'a'];
        }
        return curr->cp;
    }

    void erase(string &word){
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++)
        {
            curr=curr->children[word[i]-'a'];
            curr->cp-=1;
        }
        curr->end-=1;
    }
};
