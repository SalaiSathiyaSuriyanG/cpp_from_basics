
/* ================================== LeetCode version ======================================

- Time Complexity: O(n*m) //Where n is the no.of students and m is the average length of the attendance string
- Space Complexity: O(n*m) 

class Solution {
public:
    bool checkRecord(string s) {
        int count_A = 0;
        int count_L = 0;

        for(char ch : s){
            if(ch == 'A'){
                count_A++;
                if(count_A >= 2) return false;
            }

            if(ch == 'L'){
                count_L++;
                if(count_L >= 3) return false;
            }
            else
                count_L = 0;
        }
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int count_A = 0;
        int count_L = 0;

        for(char ch : s){
            if(ch == 'A'){
                count_A++;
                if(count_A >= 2) return false;
            }

            if(ch == 'L'){
                count_L++;
                if(count_L >= 3) return false;
            }
            else
                count_L = 0;
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n;
    string stname,attendance;

    unordered_map<string, string> record;
    vector<string> names;

    cout <<"Enter the number of students : ";
    cin >> n;

    cout <<"Enter the names of students:\n";
    for(int i = 0; i < n; i++){
        cin >> stname;
        names.push_back(stname);
    }

    cout <<"\nAttendance codes :\n";
    cout <<"A = Absent, L = Late, P = Present\n\n";

    for(string name : names){
        cout <<"Enter attendance record for " << name << ": ";
        cin >> attendance;
        record[name] = attendance;
    }

    cout <<"\nEligible students for reward :\n";

    bool found = false;

    for(string name : names){
        if(sol.checkRecord(record[name])){
            cout << name <<" ";
            found = true;
        }
    }

    if(!found){
        cout <<"No eligible students" << endl;
    }

    return 0;
}