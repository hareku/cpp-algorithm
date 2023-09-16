#ifndef LIB_TRIE_HPP
#define LIB_TRIE_HPP 1

#include <bits/stdc++.h>

namespace lib::sequence {

class Trie {
    public:
        Trie() {}

        void add(std::string& word) {
            TrieNode* node = root;
            for(auto c : word) {
                if(!node->get(c)) {
                    node->set(c);
                }
                node = node->get(c);
            }
            node->isLeaf = true;
        }

        bool search(std::string& word) {
            return searchTrie(word, 0, root, true);
        }

        bool startsWith(std::string& prefix) {
            return searchTrie(prefix, 0, root, false);
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

        bool searchTrie(const std::string& word, int pos, TrieNode* node, bool exact) {
            if(pos == word.size()) {
                if(exact) {
                    return node->isLeaf;
                }
                return true;
            }

            TrieNode* next = node->get(word[pos]);
            if(next) {
                return searchTrie(word, pos + 1, next, exact);
            }
            return false;
        }
};

}  // namespace lib::sequence

#endif  // LIB_TRIE_HPP
