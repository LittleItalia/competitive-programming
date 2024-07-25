# Creating set
myset = set()  # or myset = {1, 2} or myset = {['a', 'b']}

# Add element to set
myset.add(1)
myset.add(2)

# Upadte many element from (tuple, list, another set) to set
lst = [3, 4]
myset.update(lst)

# Remove element from set
myset.remove(1)
myset.discard(2)


set1 = {1, 2, 3}
set2 = {3, 4, 5}

# Hợp của 2 set
union_set = set1 | set2    # union_set = set1.union(set2)

# Giao của 2 set
intersection_set = set1 & set2     # intersection_set = set1.intersection(set2)

# Hiệu của 2 set
difference_set = set1 - set2     # difference_set = set1.difference(set2)

