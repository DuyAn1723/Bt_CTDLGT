function bubble_sort!(arr)
    """
    Hàm sắp xếp nổi bọt (sửa đổi mảng gốc)

    Args:
        arr: Mảng cần sắp xếp

    Returns:
        Mảng đã được sắp xếp
    """

    n = length(arr)
    for i in 1:(n-1)
        swapped = false
        for j in 1:(n-i-1)
            if arr[j] > arr[j+1]
                # Hoán đổi hai phần tử
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = true
            end
        end
        # Nếu không có lần đổi chỗ nào, mảng đã được sắp xếp
        if !swapped
            break
        end
    end
    return arr
end

# Ví dụ sử dụng
arr = [5, 2, 9, 1, 5]
bubble_sort!(arr)
println("Kết quả sau Bubble Sort: ", arr)