def sum_1_to_n(n):
    """
    Hàm tính tổng các số từ 1 đến n

    Args:
        n: Số nguyên dương

    Returns:
        Tổng các số từ 1 đến n
    """

    s = 0  # Khởi tạo biến s để lưu tổng, ban đầu bằng 0
    for i in range(1, n+1):
        s += i  # Cộng dồn từng số từ 1 đến n vào biến s
    return s  # Trả về kết quả tổng

if __name__ == "__main__":
    n = int(input("Nhập n: "))  # Nhập giá trị n từ người dùng
    result = sum_1_to_n(n)  # Gọi hàm tính tổng và lưu kết quả vào biến result
    print("Tổng 1..n =", result)  # In ra kết quả tổng