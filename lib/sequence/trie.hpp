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
                node->cnt++;
            }
            node->leafCnt++;
        }

        bool search(std::string& word) {
            return search_trie(word, 0, root, true);
        }

        bool starts_with(std::string& prefix) {
            return search_trie(prefix, 0, root, false);
        }

    private:
        class TrieNode {
        public:
            long long leafCnt, cnt;
            TrieNode* children[26];
            TrieNode() {
                leafCnt = 0;
                cnt = 0;
                memset(children, 0, sizeof(children));
            }
            TrieNode* get(char c) {
                return children[c - 'a'];
            }
            void set(char c) {
                children[c - 'a'] = new TrieNode();
            }
        };

        TrieNode* root = new TrieNode();

        bool search_trie(const std::string& word, int pos, TrieNode* node, bool exact) {
            if(pos == (int)word.size()) {
                if(exact) {
                    return node->leafCnt > 0;
                }
                return true;
            }

            TrieNode* next = node->get(word[pos]);
            if(next) {
                return search_trie(word, pos + 1, next, exact);
            }
            return false;
        }
};

}  // namespace lib::sequence

#endif  // LIB_TRIE_HPP
