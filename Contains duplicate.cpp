   #include<bits/stdc++.h>
   using namespace std;
   
    bool containsDuplicate(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                return true; //true is 1
            }
        }
        return false; // false is 0
    }

int main(){
	int n;
	cout<<"Enter the size of the Array: ";
	cin>>n;
	vector<int> nums(n);
	cout<<"Enter the Array elements: ";
	for(int i=0;i<n;i++){
	cin>>nums[i];
}
	cout<<containsDuplicate(nums);
}
