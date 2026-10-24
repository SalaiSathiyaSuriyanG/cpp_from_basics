
/* ================================== LeetCode Version ======================================

- Time Complexity: O(N * L) //Where N is the number of words and L is the max length of a word.
- Space Complexity: O(1) 

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++){
            // By using constant reference, we can reduce the space
            // by avoiding copying the strings entirely.
            // Now it points directly to the strings inside words.
            const string& s1 = words[i];
            const string& s2 = words[i + 1];
            
            int i1 = 0, i2 = 0;
            bool found_mismatch = false;
            
            while(i1 < s1.size() && i2 < s2.size()){
                if(s1[i1] != s2[i2]){
                    // Check the custom order at the first mismatch.
                    if(mp[s1[i1]] > mp[s2[i2]]){
                        return false;
                    }

                    // If the right order is found skip the remaining. We don't need to check further.
                    found_mismatch = true;
                    break; 
                }
                i1++;
                i2++;
            }
            
            // Prefix rule: If one word is a prefix of the other, the shorter word must come first.
            if(!found_mismatch && s1.size() > s2.size())
                return false;
        }
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++){
            // By using constant reference, we can reduce the space
            // by avoiding copying the strings entirely.
            // Now it points directly to the strings inside words.
            const string& s1 = words[i];
            const string& s2 = words[i + 1];
            
            int i1 = 0, i2 = 0;
            bool found_mismatch = false;
            
            while(i1 < s1.size() && i2 < s2.size()){
                if(s1[i1] != s2[i2]){
                    // Check the custom order at the first mismatch.
                    if(mp[s1[i1]] > mp[s2[i2]]){
                        return false;
                    }

                    // If the right order is found skip the remaining. We don't need to check further.
                    found_mismatch = true;
                    break; 
                }
                i1++;
                i2++;
            }
            
            // Prefix rule: If one word is a prefix of the other, the shorter word must come first.
            if(!found_mismatch && s1.size() > s2.size())
                return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int n;
    string order;

    cout <<"Enter the number of words : ";
    cin >> n;

    vector<string> words(n);
    cout <<"Enter the words :" << endl;
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    cout <<"Enter the alien order : ";
    cin >> order;

    if(sol.isAlienSorted(words, order))
        cout <<"\nThe words are sorted in accordance with the alien language."<< endl;
    else
        cout <<"\nThe words are not sorted in accordance with the alien language."<< endl;

    return 0;
}