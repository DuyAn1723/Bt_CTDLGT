def partition(arr, low, high):
    """
    Hàm phân hoạch mảng

    Args:
        arr: Mảng cần phân hoạch
        low: Chỉ số bắt đầu của khoảng cần phân hoạch
        high: Chỉ số kết thúc của khoảng cần phân hoạch

    Returns:
        Chỉ số của phần tử pivot sau khi phân hoạch
    """

    pivot = arr[high]  # Chọn phần tử cuối làm pivot
    i = low - 1

    for j in range(low, high):
        # Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if arr[j] <= pivot:
            # Đưa phần tử nhỏ hơn pivot về bên trái pivot
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    # Đưa pivot về vị trí cuối cùng của phần tử nhỏ hơn pivot
    i = i + 1
    arr[i], arr[high] = arr[high], arr[i]

    return i

def quick_sort(arr, low, high):
    """
    Hàm thực hiện sắp xếp nhanh

    Args:
        arr: Mảng cần sắp xếp
        low: Chỉ số bắt đầu của khoảng cần sắp xếp
        high: Chỉ số kết thúc của khoảng cần sắp xếp
    """

    if low < high:
        # Tìm vị trí của pivot sau khi phân hoạch
        pi = partition(arr, low, high)

        # Sắp xếp đệ quy hai nửa con
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Ví dụ sử dụng
arr = [5, 2, 9, 1, 5, 6]
quick_sort(arr, 0, len(arr) - 1)
print("Kết quả Quick Sort:", arr)