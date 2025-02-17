#include <iostream>
#include <vector>
#include <algorithm> // Để sử dụng hàm std::min
using namespace std;

// Hàm merge hai mảng con đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Kích thước của mảng con trái
    int n2 = right - mid;    // Kích thước của mảng con phải

    // Tạo các mảng tạm để lưu mảng con trái và phải
    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu vào các mảng con
    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng con lại với nhau
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L nếu còn
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R nếu còn
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm Bottom-Up Merge Sort
void bottomUpMergeSort(vector<int>& arr) {
    int n = arr.size();

    // Kích thước mảng con được xử lý từng bước (1, 2, 4, ...)
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        // Duyệt qua từng mảng con cần trộn
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Mảng trước khi sắp xếp: ";
    for (int num : arr) 
        cout << num << " ";
    cout << endl;

    bottomUpMergeSort(arr);

    cout << "Mảng sau khi sắp xếp: ";
    for (int num : arr) 
        cout << num << " ";
    cout << endl;

    return 0;
}
