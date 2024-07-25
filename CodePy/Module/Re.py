from re import match, search, findall, finditer, sub, split


""" 're.match(pattern, string)' """
# So khớp mẫu pattern với phần đầu của chuỗi string.
# Trả về một đối tượng match nếu tìm thấy, ngược lại trả về None.
result = match(r'hello', 'hello world')
if result:
    print("Matched:", result.group())



""" 're.search(pattern, string)' """
# Tìm kiếm mẫu 'pattern' trong toàn bộ chuỗi 'string'.
# Trả về một đối tượng match nếu tìm thấy, ngược lại trả về 'None'.
result = search(r'world', 'hello world world')
if result:
    print("Found:", result.group())



""" 're.findall(pattern, string)' """
# Tìm tất cả các đoạn con trong chuỗi string khớp với mẫu pattern.
# Trả về một danh sách các chuỗi được tìm thấy.
result = findall(r'\d+', 'There are 123 apples and 456 orange')
print("Numbers found:", result)   # ['123', '456']



""" 're.finditer(pattern , string)' """
# Tìm tất cả các đoạn con trong chuỗi string khớp với mẫu pattern.
# Trả về một iterator của các đối tượng match.
result = finditer(r'\d+', 'There are 123 apples and 456 orange')
for val in result:
    print("Match found:", val.group())



""" 're.sub(pattern, repl, string)' """
# Thay thế tất cả các đoạn con khớp với mẫu pattern trong chuỗi string bằng repl.
# Trả về chuỗi mới sau khi thay thế.
result = sub(r'apples', 'bananas', 'I likes apples')
print(result)



""" 're.split(pattern, string)' """
# Chia chuỗi string thành danh sách bằng cách sử dụng mẫu pattern làm ranh giới.
# Trả về một danh sách các chuỗi.
result = split(r'\s+', 'Split this sentence into words.')
print(result)



