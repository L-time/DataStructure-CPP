#include <bits/stdc++.h>

class Tier{
private:
    bool isEnd;
    Tier*next[26];
public:
    Tier() {
        isEnd = false;
        memset(next,0, sizeof(next));
    }
    void insert(std::string word){
        Tier* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL){
                node->next[c - 'a'] = new Tier();
            }
            node = node->next[c-'a'];
        }
        node -> isEnd = true;
    }
    bool search(std::string word){
        Tier* node = this;
        for (char c: word) {
            node = node ->  next[c-'a'];
            if (node == NULL) return false;
        }
        return node -> isEnd;
    }
    bool startsWith(std::string prefix){
        Tier* node = this;
        for (char c:prefix) {
            node = node ->next[c - 'a'];
            if (node == NULL) return false;
        }
        return true;
    }
};