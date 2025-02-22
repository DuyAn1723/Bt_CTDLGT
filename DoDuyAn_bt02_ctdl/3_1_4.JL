function merge!(arr, left::Int, mid::Int, right::Int)
    n1 = mid - left + 1  # Kích thước mảng con trái
    n2 = right - mid     # Kích thước mảng con phải

    # Tạo các mảng con với đúng kiểu dữ liệu
    L = Array{eltype(arr)}(undef, n1)
    R = Array{eltype(arr)}(undef, n2)

    # Sao chép dữ liệu vào mảng con
    for i in 1:n1
        L[i] = arr[left + i - 1]
    end

    for j in 1:n2
        R[j] = arr[mid + j]
    end

    i, j, k = 1, 1, left  # Chỉ số cho L, R và mảng chính

    # Trộn hai mảng con vào mảng chính
    while i <= n1 && j <= n2
        if L[i] <= R[j]
            arr[k] = L[i]
            i += 1
        else
            arr[k] = R[j]
            j += 1
        end
        k += 1
    end

    # Sao chép phần còn lại của L, nếu có
    while i <= n1
        arr[k] = L[i]
        i += 1
        k += 1
    end

    # Sao chép phần còn lại của R, nếu có
    while j <= n2
        arr[k] = R[j]
        j += 1
        k += 1
    end
end

function merge_sort!(arr, left::Int, right::Int)
    if left < right
        mid = div(left + right, 2)  # Tìm điểm giữa mảng
        merge_sort!(arr, left, mid)  # Sắp xếp phần bên trái
        merge_sort!(arr, mid + 1, right)  # Sắp xếp phần bên phải
        merge!(arr, left, mid, right)  # Trộn hai phần đã sắp xếp
    end
end

# Kiểm tra với dữ liệu ngẫu nhiên
using Random
Random.seed!(1234)  # Đặt seed ngẫu nhiên
arr = [5, 2, 9, 1, 5, 6]  # Mảng đầu vào
merge_sort!(arr, 1, length(arr))  # Gọi hàm sắp xếp
println("Kết quả Merge Sort: ", arr)
