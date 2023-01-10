#include <bits/stdc++.h>

class Tier{
private:
    bool isEnd;
    Tier*next[26];
    static bool isLeaf(Tier* node){
        for (int i = 0; i < 26; ++i) {
            if (node->next[i] != NULL) return false;
        }
        return true;
    }
    void popChar(Tier *pre,Tier *child){
        for (int i = 0; i < 26; ++i) {
            if (pre->next[i]==child){
                pre->next[i]== nullptr;
                break;
            }
        }
        delete child;
    }
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
    void pops(std::string word){
        if (search(word)){
            std::stack<Tier*> TierStack;
            Tier *node = this;
            for (char c:word) {
                node = node->next[c-'a'];
                TierStack.push(node);
            }
            node -> isEnd = false;
            while (!TierStack.empty()){
                node = TierStack.top();
                TierStack.pop();
                Tier *pre = TierStack.top();
                if (isLeaf(node)){
                    popChar(pre,node);
                }
            }
        }
    }
};