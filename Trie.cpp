#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    Node *links[26];
    bool flag;

public:
    bool isContainsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void putChar(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *getLink(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    // O(word.size())
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->isContainsKey(word[i]))
            {
                node->putChar(word[i], new Node());
            }
            node = node->getLink(word[i]);
        }
        node->setEnd();
    }
    // O(word.size())
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->isContainsKey(word[i]))
            {
                return false;
            }
            node = node->getLink(word[i]);
        }
        return node->isEnd();
    }

    // O(prefix.size())
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->isContainsKey(prefix[i]))
            {
                return false;
            }
            node = node->getLink(prefix[i]);
        }
        return true;
    }
};

int main()
{
    return 0;
}