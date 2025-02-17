# Định nghĩa hàm Merge Sort
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        # Trộn hai mảng con
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        # Sao chép phần còn lại của L
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        # Sao chép phần còn lại của R
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

# Tạo mảng ngẫu nhiên
arr = [5, 2, 9, 1, 5, 6]

# Đo thời gian thực thi với %timeit trong Jupyter hoặc IPython
%timeit merge_sort(arr.copy())
