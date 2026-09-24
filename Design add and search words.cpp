
/* ================================== LeetCode Version ======================================

- Time Complexity: 
    Insert: O(L)
    Search: O(N*L)
    //Where N is the number of nodes in the Trie and L is the length of the word being searched.

- Space Complexity: 
    Trie storage: O(T) 
    //where T is the total number of characters across all inserted words
    (worst case, when there is little sharing). 

class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];

    TrieNode(){
        isCompleteWord = false;
        memset(children, 0, sizeof(children));
    }    
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode();
            }    
            node = node->children[index];
        }
        node->isCompleteWord = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int index, TrieNode* node) {
        if (index == word.length()) return node->isCompleteWord;

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }
        else{
            if (node->children[ch - 'a'] == nullptr) {
                return false;
            }
            return (searchHelper(word, index + 1, node->children[ch - 'a']));
        }
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];

    TrieNode(){
        isCompleteWord = false;
        memset(children, 0, sizeof(children));
    }    
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode();
            }    
            node = node->children[index];
        }
        node->isCompleteWord = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int index, TrieNode* node) {
        if (index == word.length()) return node->isCompleteWord;

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }
        else{
            if (node->children[ch - 'a'] == nullptr) {
                return false;
            }
            return (searchHelper(word, index + 1, node->children[ch - 'a']));
        }
    }
};

int main(){
    WordDictionary dict;
    int choice;
    string word;

    while(true) {
        cout <<"\n1. Insert Word\n";
        cout <<"2. Search Word\n";
        cout <<"3. Exit\n";
        cout <<"\nEnter choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout <<"\nEnter a word to insert : ";
                cin >> word;
                dict.addWord(word);
                cout <<"Inserted successfully.\n";
                break;

            case 2:
                cout <<"\nEnter a word to search : ";
                cin >> word;
                if (dict.search(word))
                    cout <<"Word found.\n";
                else
                    cout <<"Word not found.\n";
                break;

            case 3:
                return 0;

            default:
                cout <<"Invalid choice.\n";
        }
    }
}