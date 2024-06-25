#include <iostream>
#include <vector>
#include <cstdlib> // Para usar rand()

using namespace std;

void print_array(const vector<int>& arr) {
    for(size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        print_array(arr); // Print array at the beginning of each outer loop iteration
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Array before sorting: ";
    print_array(arr);

    insertion_sort(arr);

    cout << "Array after sorting: ";
    print_array(arr);

    return 0;
}
