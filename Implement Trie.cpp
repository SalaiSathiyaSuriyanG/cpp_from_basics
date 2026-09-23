

/* ================================== LeetCode Version ======================================

- Time Complexity: 
    Insert: O(L)
    Search: O(L)
    StartsWith: O(L)
    //Where L is the length of the word or prefix.

- Space Complexity: 
    Trie storage: O(T)
    //where T is the total number of characters across all inserted words
    (worst case, when there is little or no prefix sharing). 

class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];

    TrieNode(){
        isCompleteWord = false;
        memset(children, 0, sizeof(children));
    }    
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode(); 
    }
    
    /* 
     * PURPOSE: Adds a new word into the Trie letter-by-letter.
     * If a letter's node already exists, it moves down to it.
     * If it doesn't exist, it creates a new node for that letter.
    /
    void insert(string word) {
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
    
    /* 
     * PURPOSE: Checks if a exact, full word exists in the Trie.
     * Returns true ONLY if the entire character path exists AND 
     * the final node is marked as a complete word.
    /
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(!node->children[index]){
                return false;
            }    
            node = node->children[index];
        }
        return node->isCompleteWord;
    }
    
    /* 
     * PURPOSE: Checks if any inserted word begins with the given prefix.
     * Returns true as long as the complete character path of the prefix exists,
     * completely ignoring the 'isCompleteWord' flag.
    /
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(!node->children[index]){
                return false;
            }    
            node = node->children[index];
        }
        return true;
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

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode(); 
    }
    
    /* 
     * PURPOSE: Adds a new word into the Trie letter-by-letter.
     * If a letter's node already exists, it moves down to it.
     * If it doesn't exist, it creates a new node for that letter.
     */
    void insert(string word) {
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
    
    /* 
     * PURPOSE: Checks if a exact, full word exists in the Trie.
     * Returns true ONLY if the entire character path exists AND 
     * the final node is marked as a complete word.
     */
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(!node->children[index]){
                return false;
            }    
            node = node->children[index];
        }
        return node->isCompleteWord;
    }
    
    /* 
     * PURPOSE: Checks if any inserted word begins with the given prefix.
     * Returns true as long as the complete character path of the prefix exists,
     * completely ignoring the 'isCompleteWord' flag.
     */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(!node->children[index]){
                return false;
            }    
            node = node->children[index];
        }
        return true;
    }
};

int main() {
    Trie trie;
    int choice;
    string word;

    while(true) {
        cout <<"\n1. Insert Word\n";
        cout <<"2. Search Word\n";
        cout <<"3. Search Prefix\n";
        cout <<"4. Exit\n";
        cout <<"\nEnter choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout <<"\nEnter a word to insert : ";
                cin >> word;
                trie.insert(word);
                cout <<"Inserted successfully.\n";
                break;

            case 2:
                cout <<"\nEnter a word to search : ";
                cin >> word;
                if (trie.search(word))
                    cout <<"Word found.\n";
                else
                    cout <<"Word not found.\n";
                break;

            case 3:
                cout <<"\nEnter prefix : ";
                cin >> word;
                if (trie.startsWith(word))
                    cout <<"Prefix exists.\n";
                else
                    cout <<"Prefix does not exist.\n";
                break;

            case 4:
                return 0;

            default:
                cout <<"Invalid choice.\n";
        }
    }
}