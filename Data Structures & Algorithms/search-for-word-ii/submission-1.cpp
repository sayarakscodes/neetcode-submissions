class TrieNode {
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i ++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie {
    private:
    TrieNode* root;
    public:
    Trie() {
        this->root = new TrieNode();
    }

    bool searchWord(string s) {
        TrieNode* curr = root;
        for(int i = 0; i < s.size(); i ++) {
            if(curr->children[s[i] - 'a'] != NULL) {
                curr = curr->children[s[i] - 'a'];
            } else {
                return false;
            }
        }
        return curr->isEnd;
    }

    bool isPrefix(string s) {
        TrieNode* curr = root;
        for(int i = 0; i < s.size(); i ++) {
            if(curr->children[s[i] - 'a'] != NULL) {
                curr = curr->children[s[i] - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

    void addWord(string s) {
        TrieNode* curr = root;
        for(int i = 0; i < s.size(); i ++) {
            if(curr->children[s[i]-'a'] == NULL) {
                TrieNode* node = new TrieNode();
                curr->children[s[i] - 'a'] = node;
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->isEnd = true;
    }


};

class Solution {

private:
    int fx[4] = {+1, -1, +0, -0};
    int fy[4] = {+0, -0, +1, -1};
    void dfs(int i, int j, vector<vector<char>> &board, Trie* trie, set<string> & ans, vector<vector<int>> & vis, string currWord) {
        currWord += board[i][j];
        if(trie->searchWord(currWord)) {
            ans.insert(currWord);
        }
        if(!trie->isPrefix(currWord)) {
            currWord.pop_back();
            return;
        }
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int x = 0; x < 4; x ++) {
            int xx = i + fx[x];
            int yy = j + fy[x];
            if(xx < 0 || xx > n - 1 || yy < 0 || yy > m - 1 || vis[xx][yy]) continue;
            dfs(xx, yy, board, trie, ans, vis, currWord);
        }

        currWord.pop_back();
        vis[i][j] = 0;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        int n = board.size();
        int m = board[0].size();
        for(string s : words) {
            trie->addWord(s);
        }
        set<string> ans;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                dfs(i, j, board, trie, ans, vis, "");
            }
        }
        vector<string>res;
        for(string x : ans) {
            res.push_back(x);
        }
        return res;
    }
};
