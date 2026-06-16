
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n) //Sorting takes O(n log n) time
- Space Complexity: O(n) 

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result;
        vector<int> Score = score;
        sort(Score.begin(),Score.end(),greater<int>());

        vector<string> medals = {"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int,string> rank; 

        for(int i = 0; i < score.size(); i++){
            if(i < 3){
                rank[Score[i]] = medals[i];
            }
            else
                rank[Score[i]] = to_string(i + 1);
        }
        for(int s : score){
            result.push_back(rank[s]);
        }
        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result;
        vector<int> Score = score;
        sort(Score.begin(),Score.end(),greater<int>());

        vector<string> medals = {"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int,string> rank; 

        for(int i = 0; i < score.size(); i++){
            if(i < 3){
                rank[Score[i]] = medals[i];
            }
            else
                rank[Score[i]] = to_string(i + 1);
        }
        for(int s : score){
            result.push_back(rank[s]);
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of scores : ";
    cin >> n;

    vector<int> score(n);
    cout <<"Enter the scores : ";
    for(int i = 0; i < n; i++){
        cin >> score[i];
    }

    cout <<"Their ranks are : ";
    vector<string> ranks = sol.findRelativeRanks(score);
    for(const string& rank : ranks){
        cout <<"\""<< rank <<"\" ";
    }
    cout << endl;

    return 0;
}