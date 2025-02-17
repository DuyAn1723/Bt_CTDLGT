def merge_sort_hybrid(arr, left, right):
    """
    Hàm sắp xếp trộn kết hợp

    Args:
        arr: Danh sách cần sắp xếp
        left: Chỉ số bắt đầu của đoạn con
        right: Chỉ số kết thúc của đoạn con
    """

    if right - left + 1 <= 10:
        # Nếu kích thước đoạn con nhỏ hơn hoặc bằng 10, sử dụng Insertion Sort
        insertion_sort(arr, left, right)
    elif left < right:
        mid = (left + right) // 2
        merge_sort_hybrid(arr, left, mid)
        merge_sort_hybrid(arr, mid + 1, right)
        merge(arr, left, mid, right)