
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n * m) //Where n is the number of emails and m is the average length of each email.
- Space Complexity: O(n * m) //We are storing unique emails in an unordered_set, 
                             //which can take up to O(n * m) space in the worst case.

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for(string mail : emails){
            string local = "";

            auto pos = mail.find('@');
            string domain = mail.substr(pos + 1);

            int i = 0;
            while(mail[i] != '@' && mail[i] != '+'){
                if(mail[i] != '.'){
                    local += mail[i];
                }
                i++;
            }
            st.insert(local + "@" + domain);
        }
        return st.size();
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for(string mail : emails){
            string local = "";

            auto pos = mail.find('@');
            string domain = mail.substr(pos + 1);

            int i = 0;
            while(mail[i] != '@' && mail[i] != '+'){
                if(mail[i] != '.'){
                    local += mail[i];
                }
                i++;
            }
            st.insert(local + "@" + domain);
        }
        return st.size();
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of emails : ";
    cin >> n;

    vector<string> emails(n);
    cout <<"\nEnter the emails :\n";
    for(int i = 0; i < n; i++){
        cin >> emails[i];
    }

    cout <<"\nNumber of unique emails : " << sol.numUniqueEmails(emails) << endl;

    return 0;
}