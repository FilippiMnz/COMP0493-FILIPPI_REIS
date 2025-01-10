#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(vector<int>& arr, int left, int right) {
    int index = partition(arr, left, right);
    if (left < index - 1) {
        quickSort(arr, left, index - 1);
    }
    if (index < right) {
        quickSort(arr, index, right);
    }
}

int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < key) {
            low = mid + 1;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            if (mid > 0 && arr[mid - 1] == key) {
                high = mid - 1; 
            } else {
                return mid + 1; 
            }
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (true) {
        int n, q;
        cin >> n >> q;
        if (n == 0 && q == 0) {
            break;
        }

        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        quickSort(numbers, 0, n - 1);

        cout << "CASE# " << t << ":\n";
        for (int i = 0; i < q; ++i) {
            int find;
            cin >> find;
            int position = binarySearch(numbers, find);
            if (position == -1) {
                cout << find << " not found\n";
            } else {
                cout << find << " found at " << position << "\n";
            }
        }

        t++;
    }

    return 0;
}

