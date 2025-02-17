function binary_search(arr, target)
    # Khởi tạo chỉ số trái và phải của khoảng tìm kiếm
    left = 1
    right = length(arr)

    # Tiếp tục tìm kiếm trong khi khoảng tìm kiếm chưa rỗng
    while left <= right
        # Tính chỉ số phần tử ở giữa khoảng tìm kiếm
        mid = div(left + right, 2)

        # Kiểm tra xem phần tử ở giữa có phải là phần tử cần tìm không
        if arr[mid] == target
            # Nếu tìm thấy, trả về chỉ số
            return mid
        # Nếu phần tử cần tìm lớn hơn phần tử ở giữa
        elseif arr[mid] < target
            # Thu hẹp khoảng tìm kiếm sang nửa phải
            left = mid + 1
        # Nếu phần tử cần tìm nhỏ hơn phần tử ở giữa
        else
            # Thu hẹp khoảng tìm kiếm sang nửa trái
            right = mid - 1
        end
    end

    # Nếu không tìm thấy, trả về -1
    return -1
end
