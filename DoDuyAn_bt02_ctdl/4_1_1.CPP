#include <iostream>
#include <vector>
#include <chrono> // Thư viện <chrono>
using namespace std;
using namespace std::chrono;

// Hàm merge để hợp nhất 2 mảng con đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    // Sao chép dữ liệu vào các mảng con
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Hợp nhất mảng con
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con trái
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con phải
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Hàm mergeSort đệ quy
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sắp xếp nửa trái và nửa phải
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Hợp nhất các nửa đã sắp xếp
        merge(arr, left, mid, right);
    }
}

int main() {
    // Tạo mảng ngẫu nhiên
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    // Bắt đầu đo thời gian
    auto start = high_resolution_clock::now();

    // Gọi thuật toán Merge Sort
    mergeSort(arr, 0, arr.size() - 1);

    // Kết thúc đo thời gian
    auto end = high_resolution_clock::now();

    // Tính toán thời gian đã trôi qua (tính bằng mili giây)
    auto duration = duration_cast<milliseconds>(end - start).count();

    // In kết quả
    cout << "Kết quả Merge Sort: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << "Thời gian thực hiện (ms) = " << duration << " ms" << endl;

    return 0; // Thêm câu lệnh return để kết thúc hàm main
}
