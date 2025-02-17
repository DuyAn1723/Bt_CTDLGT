def bubble_sort(arr):
    """
    Hàm sắp xếp nổi bọt

    Args:
        arr: Danh sách cần sắp xếp
    """

    n = len(arr)
    # Vòng lặp bên ngoài: Lặp qua các vòng qua
    for i in range(n - 1):
        swapped = False
        # Vòng lặp bên trong: So sánh và đổi chỗ các phần tử liền kề
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                # Đổi chỗ hai phần tử
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # Nếu không có lần đổi chỗ nào trong vòng lặp này, danh sách đã được sắp xếp
        if not swapped:
            break

# Ví dụ sử dụng
arr = [5, 2, 9, 1, 5]
bubble_sort(arr)
print("Kết quả sau Bubble Sort:", arr)