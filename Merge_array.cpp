#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    // Iterate through all elements of arr2
    for (int i = 0; i < arr2.size(); ++i) {
        // Last element of arr1
        int last = arr1[arr1.size() - 1];
        int j = arr1.size() - 2;
        // Move all elements of arr1 that are greater than arr2[i] one position ahead
        while (j >= 0 && arr1[j] > arr2[i]) {
            arr1[j + 1] = arr1[j];
            j--;
        }
        // If there was a greater element, put it into the last position of arr1
        if (j != arr1.size() - 2 || last > arr2[i]) {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

int main() {
    vector<int> arr1, arr2;
    int n, m, val;

    // Input for first array
    cout << "Enter number of elements for the first array: ";
    cin >> n;
    cout << "Enter elements for the first array (in sorted order): ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        arr1.push_back(val);
    }

    // Input for second array
    cout << "Enter number of elements for the second array: ";
    cin >> m;
    cout << "Enter elements for the second array (in sorted order): ";
    for (int i = 0; i < m; ++i) {
        cin >> val;
        arr2.push_back(val);
    }

    // Merge the arrays
    mergeArrays(arr1, arr2);

    // Output the merged array
    cout << "Merged array: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
