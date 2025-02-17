#include <iostream>
#include <vector>
#include <algorithm> // Để sử dụng hàm swap
using namespace std;

// Hàm tìm Median-of-Three và đặt pivot vào cuối mảng
int median_of_three(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    // Đảm bảo arr[low] <= arr[mid] <= arr[high]
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    return mid; // Trả về chỉ số median
}

// Hàm phân hoạch mảng sử dụng Median-of-Three
int partitionFunc(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pivot là phần tử cuối
    int i = low - 1;       // i là chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1; // Trả về vị trí pivot
}

// Hàm phân hoạch với Median-of-Three
int partition_median(vector<int>& arr, int low, int high) {
    int median = median_of_three(arr, low, high); // Tìm median
    swap(arr[median], arr[high]); // Đưa median về cuối
    return partitionFunc(arr, low, high); // Phân hoạch mảng
}

// Hàm QuickSort với Median-of-Three
void quickSort_median(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition_median(arr, low, high); // Phân hoạch mảng
        quickSort_median(arr, low, p - 1); // Sắp xếp phần trái
        quickSort_median(arr, p + 1, high); // Sắp xếp phần phải
    }
}

// Kiểm tra chương trình
int main() {
    vector<int> arr = {24, 3, 45, 29, 15, 47, 12};

    cout << "Mảng ban đầu: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort_median(arr, 0, arr.size() - 1);

    cout << "Mảng sau khi sắp xếp: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
