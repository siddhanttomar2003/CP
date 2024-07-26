#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode *bit[2];
    TrieNode() {
        bit[0] = NULL;
        bit[1] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--) {
            int temp = (num >> i) & 1;
            if (curr->bit[temp] == NULL) {
                curr->bit[temp] = new TrieNode();
            }
            curr = curr->bit[temp];
        }
    }

    int travel(int num) {
        TrieNode *curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int flip = bit ^ 1;
            if (curr->bit[flip] != NULL) {
                ans |= (1 << i);
                curr = curr->bit[flip];
            } else {
                curr = curr->bit[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (int num : nums) {
            t.insert(num);
        }
        int ans = 0;
        for (int num : nums) {
            ans = max(ans, t.travel(num));
        }
        return ans;
    }
};


