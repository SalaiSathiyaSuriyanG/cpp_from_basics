#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cout << "Enter the array size: ";
    cin >> n;
    cout << "Enter the target element: ";
    cin >> target;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
