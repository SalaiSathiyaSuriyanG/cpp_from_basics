
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) { 
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }    
        digits.insert(digits.begin(),1);
        return digits;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) { 
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }    
        digits.insert(digits.begin(),1);
        return digits;
    }
};

int main(){
	Solution sol;
	
	int n;
	cout<<"Enter the array size : ";
	cin>>n;
	
	vector<int> digits(n);
	cout<<"Enter the array elements : ";
	for(int i=0;i<n;i++){
		cin>>digits[i];
	}
	
    vector<int> result = sol.plusOne(digits);
    cout<<"Incremented array : ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<< " ";
    }
	
	return 0;
}