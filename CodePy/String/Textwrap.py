import textwrap

string = "This is a very very very very very long string."
max_width = 8


# Chia một chuỗi dài thành một danh sách các dòng có độ dài cố định không quá max_width
print(textwrap.wrap(string, max_width))
# Output: ['This is', 'a very', 'very', 'very', 'very', 'very', 'long', 'string.'] 


# Chia một chuỗi dài thành các dòng có độ dài cố định không quá max_width
print(textwrap.fill(string, max_width))
# Output:
# This is
# a very
# very
# very
# very
# very
# long
# string.