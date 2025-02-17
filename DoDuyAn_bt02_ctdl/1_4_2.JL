function sum_1_to_n(n)
    """
    Hàm tính tổng các số từ 1 đến n

    Args:
        n: Số nguyên dương

    Returns:
        Tổng các số từ 1 đến n
    """

    s = 0  # Khởi tạo biến s để lưu tổng, ban đầu bằng 0
    for i in 1:n
        s += i  # Cộng dồn từng số từ 1 đến n vào biến s
    end
    return s  # Trả về kết quả tổng
end

# Nhập giá trị n từ người dùng
println("Nhập n:")
n = parse(Int, readline())

# Gọi hàm tính tổng và in kết quả
result = sum_1_to_n(n)
println("Tổng 1..n =", result)