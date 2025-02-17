#include <iostream>

using namespace std;

// Hàm tính tổng các số từ 1 đến n
int sum_1_to_n(int n) {
    int s = 0; // Khởi tạo biến s để lưu tổng, ban đầu bằng 0
    for (int i = 1; i <= n; i++) {
        s += i; // Cộng dồn từng số từ 1 đến n vào biến s
    }
    return s; // Trả về kết quả tổng
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n; // Nhập giá trị n từ người dùng

    int result = sum_1_to_n(n); // Gọi hàm tính tổng và lưu kết quả vào biến result

    cout << "Tong 1..n = " << result << endl; // In ra kết quả tổng

    return 0;
}