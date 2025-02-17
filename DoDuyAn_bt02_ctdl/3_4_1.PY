def insertion_sort(arr, low, high):
    """Hàm sắp xếp chèn (Insertion Sort)"""
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def partition(arr, low, high):
    """Hàm phân hoạch cho Quick Sort"""
    pivot = arr[high]  # Chọn phần tử cuối làm pivot
    i = low - 1  # i là chỉ số của phần tử nhỏ hơn pivot
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1  # Trả về vị trí pivot

def quick_sort_hybrid(arr, low, high):
    """Hàm Quick Sort kết hợp với Insertion Sort"""
    while low < high:
        # Nếu mảng nhỏ hơn ngưỡng 10 phần tử, dùng Insertion Sort
        if high - low + 1 < 10:
            insertion_sort(arr, low, high)
            break
        else:
            # Thực hiện phân hoạch và sắp xếp đệ quy
            p = partition(arr, low, high)
            # Sắp xếp phần nhỏ hơn trước để tối ưu hóa
            if p - low < high - p:
                quick_sort_hybrid(arr, low, p - 1)
                low = p + 1
            else:
                quick_sort_hybrid(arr, p + 1, high)
                high = p - 1

# Kiểm tra chương trình
if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5, 3, 2, 6, 4]
    print("Mảng ban đầu:", arr)
    quick_sort_hybrid(arr, 0, len(arr) - 1)
    print("Mảng sau khi sắp xếp:", arr)
