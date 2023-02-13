#include<bits/stdc++.h>
using namespace std;
#define CHARSET 256
class TrieNode
{
    public:
    bool isWord;
    TrieNode* children[256];
    TrieNode()
    {
        this->isWord = false;
        for(int i = 0; i < CHARSET; i++)
        {
            this->children[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode* root;
    
    bool isLeafNode(TrieNode* crawler)
    {
        for(int i = 0; i < CHARSET; i++)
        {
            if(crawler->children[i] != NULL)
                return false;
        }
        return true;
    }



    public:
    Trie()
    {
        this->root = new TrieNode;
    }

    //Insertion

    void Insert(const strng &str)
    {
        TrieNode* crawler = this->root;
        for(int i = 0; i < str.size(); i++)
        {
            if(crawler -> children[int(str[i])] == NULL)
            {
                crawler -> children[int(str[i])] = bew TrieNode;
            }
            crawler = crawler -> children[int(str[i])];
        }
        crawler->isWord = true;
    }


    bool search(const strng &str)
    {
        TrieNode* crawler = this->root;
        for(int i = 0; i < str.size(); i++)
        {
            if(!crawler -> children[int(str[i])])
            {
                return false;
            }
            crawler = crawler -> children[int(str[i])];
        }
        return crawler->isWord;
    }


    bool Remove(TrieNode* crawler,const string wprd, int curr, int &len )
    {
        if(crawler == NULL)
            return false;

        if(curr == len)
        {
            crawler -> isWord = false;
            return isLeafNode(crawler);
        }
        else{
            if(Remove(crawler->children[word[curr]], word, curr+1, len))
            {
                delete(crawler->children[word[curr]]);
                return crawler->isWord && isLeafNode(crawler) ;
            }
        }
    }
    void Remove(const string &word)
    {
        TrieNode* crawler = this-> root;
        Remove(crawler, word, 0, word.size());
    }

};

int main()
{
    Trie t;
    t.Insert("Dog");
    cout << t.search("Dog") << endl;
    t.Insert("dogmatic");
}