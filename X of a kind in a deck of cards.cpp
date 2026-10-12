
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(u) //Where u is the number of unique cards in the deck 

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        int result = 0;

        //Find the frequency of each card
        for(int card : deck) freq[card]++;

        //Find the GCD of all card frequencies 
        for(auto card : freq) result = gcd(card.second, result);

        //Return true if we can split the deck into groups of 2 or more
        return result > 1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        int result = 0;

        //Find the frequency of each card
        for(int card : deck) freq[card]++;

        //Find the GCD of all card frequencies 
        for(auto card : freq) result = gcd(card.second, result);

        //Return true if we can split the deck into groups of 2 or more
        return result > 1;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of cards in the deck : ";
    cin >> n;

    vector<int> deck(n);
    cout <<"Enter the card values :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> deck[i];
    }

    cout <<"Can the deck be split into groups of 2 or more? : "
         << (sol.hasGroupsSizeX(deck) ? "Yes" : "No") << endl;

    return 0;     
}