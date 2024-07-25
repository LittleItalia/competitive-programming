from email.utils import formataddr
from email.utils import parseaddr


""" 'formataddr(pair)' kết hợp tên hiển thị và tên địa chỉ email thành một chuỗi định dạng email chuẩn """
name = "John Doe"
email = "john.doe@example.com"

formatted_address = formataddr((name, email))
print(formatted_address)  # Output: John Doe <john.doe@example.com>



""" 'parseaddr' tách một chuỗi định dạng email thành một tuple chứa tên hiển thị và địa chỉ email """
address = "John Doe <john.doe@example.com>"

name, email = parseaddr(address)
print(name)  # Output: John Doe
print(email) # Output: john.doe@example.com


