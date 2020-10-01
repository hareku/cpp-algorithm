#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(auto c : word) {
            if(!node->get(c)) {
                node->set(c);
            }
            node = node->get(c);
        }

        node->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchTrie(word, 0, root, 1);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchTrie(prefix, 0, root, 0);
    }

private:
    class TrieNode {
    public:
        bool isLeaf;
        TrieNode* children[26];
        TrieNode() {
            isLeaf = 0;
            memset(children, NULL, sizeof(children));
        }
        TrieNode* get(char c) {
            return children[c - 'a'];
        }
        void set(char c) {
            children[c - 'a'] = new TrieNode();
        }
    };

    TrieNode* root = new TrieNode();

    bool searchTrie(const string& word, int pos, TrieNode* node, bool exact) {
        if(pos == word.size()) {
            return exact ? node->isLeaf : true;
        }

        TrieNode* nextNode = node->get(word[pos]);
        return nextNode ? searchTrie(word, pos + 1, nextNode, exact) : false;
    }
};
