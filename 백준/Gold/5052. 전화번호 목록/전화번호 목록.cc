#include <iostream>
#include <string>
#include <vector>

#define MAX 26

using namespace std;

struct Trie {
    bool finish;
    Trie* next[MAX];

    Trie() : finish(false), next{} {}

    ~ Trie() {
        for (int i = 0; i < MAX; i++) {
            if (next[i] != NULL) {
                delete next[i];
            }
        }
    }

    void insert(const char* key) {
        if (*key == '\0') {
            finish = true;
        }
        else {
            int curr = *key - '0';
            if (next[curr] == NULL) {
                next[curr] = new Trie();
            }
            next[curr]->insert(key + 1);
        }
    }

    bool find(const char* key) {
        if (*key == '\0') {
            return false;
        }
        if (finish == true) {
            return true;
        }
        int curr = *key - '0';
        if (next[curr] == NULL) {
            return NULL;
        }
        return next[curr]->find(key + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        Trie* root = new Trie();
        vector<string> v;
        bool isYes = true;
        for (int j = 0; j < n; j++) {
            string input;
            cin >> input;
            v.push_back(input);
            root->insert(input.c_str());
        }

        for (string s : v) {
            if (root->find(s.c_str()) == true) {
                isYes = false;
                break;
            }
        }
        if (isYes == true) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
        delete root;
        v.clear();
    }
    return 0;
}