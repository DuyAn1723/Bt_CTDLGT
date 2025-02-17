function insertion_sort(arr)
    """
    Hàm sắp xếp chèn

    Args:
        arr: Mảng cần sắp xếp

    Returns:
        Mảng đã được sắp xếp
    """

    n = length(arr)
    for i in 2:n
        key = arr[i]
        j = i - 1

        # Di chuyển các phần tử lớn hơn key sang phải
        while j >= 1 && arr[j] > key
            arr[j+1] = arr[j]
            j -= 1
        end

        # Chèn key vào vị trí đúng
        arr[j+1] = key
    end

    return arr
end

# Ví dụ sử dụng
arr = [5, 2, 9, 1, 5]
insertion_sort(arr)
println("Kết quả sau Insertion Sort: ", arr)