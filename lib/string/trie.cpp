#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

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

class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() {

  }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    TrieNode* node = root;
    for(auto&c:word) {
      if(!node->get(c)) {
        node->set(c);
      }
      node = node->get(c);
    }

    node->isLeaf = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return searchTrie(word, 0, root);
  }
private:
  TrieNode* root = new TrieNode();

  bool searchTrie(const string& word, int pos, TrieNode* node) {
    if(pos == word.size()) return node->isLeaf;
    if(word[pos] != '.') {
      node = node->get(word[pos]);
      return node ? searchTrie(word, pos + 1, node) : false;
    }

    for(int i = 0; i < 26; ++i) {
      if(node->children[i] && searchTrie(word, pos + 1, node->children[i])) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  //
}
