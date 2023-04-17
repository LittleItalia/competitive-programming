struct TrieNode {
    TrieNode* child[26];
    int cnt;
    bool seen;
    TrieNode() {
        for(int i = 0; i < 26; i++) 
            child[i] = NULL;
        cnt = 0;
        seen = false;
    }
};

TrieNode* root = new TrieNode();

void TrieInsert(const string &s) {
    int n = s.size();
    TrieNode* p = root;
    for(int i = 0; i < n; i++) {
        int nxt = s[i] - 'a';
        if(p->child[nxt] == NULL)
            p->child[nxt] = new TrieNode();
        p = p->child[nxt];
        p->cnt++;
    }
}

bool TrieFind(const string &s) {
    int n = s.size();
    TrieNode* p = root;
    for(int i = 0; i < n; i++) {
        int nxt = s[i] - 'a';
        if(p->child[nxt] == NULL)
            return false;
        p = p->child[nxt];
    }
    return p->cnt>0;
}

