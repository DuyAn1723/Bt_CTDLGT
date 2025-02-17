#include <iostream>
using namespace std;

int main() {
    // Nhập giá trị n từ người dùng
    cout << "Nhap n: ";
    int n;
    cin >> n;

    // Khởi tạo bộ đếm
    int counter = 0;

    // Hai vòng lặp lồng nhau để tính toán số bước
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counter++; // Tăng giá trị bộ đếm
        }
    }

    // Xuất kết quả số bước thực hiện
    cout << "So buoc thuc hien = " << counter << endl;

    return 0;
}
