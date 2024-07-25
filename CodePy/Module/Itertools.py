import itertools


""" 'itertools.product(*iterables, repeat=1)' ->  Tạo ra tích Descartes của các iterable."""
result = itertools.product([1, 2], ['a', 'b'])
print(list(result))  # [(1, 'a'), (1, 'b'), (2, 'a'), (2, 'b')]



""" 'itertools.permutations(iterable, r=None)' ->  Tạo ra các hoán vị của iterable với độ dài r.."""
result = itertools.permutations([1, 2, 3], 2)
print(list(result))  # [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]



""" 'itertools.combinations(iterable, r)' ->  Tạo ra các kết hợp của iterable với độ dài r.  TỔ HỢP"""
result = itertools.combinations([1, 2, 3], 2)
print(list(result))  # [(1, 2), (1, 3), (2, 3)]



""" 'itertools.combinations_with_replacement(iterable, r)' ->  Tạo ra các kết hợp với thay thế của iterable với độ dài r.  CHỈNH HỢP"""
result = itertools.combinations_with_replacement([1, 2], 2)
print(list(result))  # [(1, 1), (1, 2), (2, 2)]



""" 'itertools.groupby(iterable, key=None)' ->  Nhóm các phần tử liên tiếp có cùng giá trị của một khóa. """
result = itertools.groupby('AAABBBCCDAABBB')
for key, group in result:
    print(key, list(group))
# A ['A', 'A', 'A']
# B ['B', 'B', 'B']
# C ['C', 'C']
# D ['D']
# A ['A', 'A']
# B ['B', 'B', 'B']