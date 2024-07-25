from functools import cmp_to_key

# Định nghĩa hàm so sánh
def compare(a, b):
    if a < b:
        return 1
    elif a > b:
        return -1
    else:
        return 0

numbers = [4, 2, 5, 1, 3]

# Sử dụng cmp_to_key để chuyển hàm so sánh thành hàm key
sorted_numbers = sorted(numbers, key=cmp_to_key(compare))

print(sorted_numbers)  # Output: [5, 4, 3, 2, 1]