
/* ================================== LeetCode version ======================================

- Time Complexity: O(n + m) //where n and m are the sizes of the two input lists.
- Space Complexity: O(n) //For storing the elements of one list in a hash map.

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;

        //Preprocess one list into a hash map
        for(int i = 0; i < list1.size(); i++){
            map[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for(int i = 0; i < list2.size(); i++){
            //For each element in list2,check if it exists in the map.
            if(map.count(list2[i])){ 
                int sum = i + map[list2[i]];

                if(sum < minSum){ 
                    /*If an element with least index sum is found,update the minSum, clear the result vector and push the current least index sum element./
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if(sum == minSum){ //If another element with same index sum is found,push that too.
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> map;

        //Preprocess one list into a hash map
        for(int i = 0; i < list1.size(); i++){
            map[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for(int i = 0; i < list2.size(); i++){
            //For each element in list2,check if it exists in the map.
            if(map.count(list2[i])){ 
                int sum = i + map[list2[i]];

                if(sum < minSum){ 
                    /*If an element with least index sum is found,update the minSum, clear the result vector and push the current least index sum element.*/
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if(sum == minSum){ //If another element with same index sum is found,push that too.
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n,m;
    cout <<"Enter the size of the first list : ";
    cin >> n;

    vector<string> list1(n);
    cout <<"Enter the elements of the first list : ";
    for(int i = 0; i < n; i++){
        cin >> list1[i];
    }

    cout <<"Enter the size of the second list : ";
    cin >> m;

    vector<string> list2(m);
    cout <<"Enter the elements of the second list : ";
    for(int i = 0; i < m; i++){
        cin >> list2[i];
    }

    vector<string> result = sol.findRestaurant(list1,list2);

    cout <<"The common strings with the least index sum are : ";
    for(const string& s : result){
        cout<< s <<" ";
    }
    cout << endl;

    return 0;
}