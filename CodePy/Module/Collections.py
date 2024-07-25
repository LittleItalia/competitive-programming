from collections import namedtuple
from collections import deque
from collections import defaultdict
from collections import OrderedDict


"""  'namedtuple' tạo ra các tuple có tên trường, giúp việc truy cập và đọc dữ liệu trở nên rõ ràng hơn """
# Tạo một namedtuple cho một điểm 2D
Point = namedtuple('Point', ['x', 'y'])
p = Point(10, 20)

print(p)       # Output: Point(x=10, y=20)
print(p.x)     # Output: 10
print(p.y)     # Output: 20



""" 'deque' là một hàng đợi hai đầu, cho phép chèn và xóa phần tử tử 2 đầu trong O(1) """
# Tạo một deque
d = deque([1, 2, 3])
d.append(4)       # Thêm vào cuối
d.appendleft(0)   # Thêm vào đầu
print(d)          # Output: deque([0, 1, 2, 3, 4])

d.pop()           # Xóa phần tử cuối cùng
d.popleft()       # Xóa phần tử đầu tiên
print(d)          # Output: deque([1, 2, 3])



""" 'defaultdict' là một từ điển mà các khóa chưa tổn tại sẽ có giá trị mặc định """
# Tạo một defaultdict với giá trị mặc định là 0
d = defaultdict(int)
d['a'] += 1
d['b'] += 2
print(d)       # Output: defaultdict(<class 'int'>, {'a': 1, 'b': 2})

# Tạo một defaultdict với giá trị mặc định là một danh sách rỗng
d = defaultdict(list)
d['a'].append(1)
d['b'].append(2)
print(d)       # Output: defaultdict(<class 'list'>, {'a': [1], 'b': [2]})



""" 'OrderedDict' là một từ điển duy trì thứ tự các phần tử được thêm vào """
# Tạo một OrderedDict
od = OrderedDict()
od['a'] = 1
od['b'] = 2
od['c'] = 3
print(od)      # Output: OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# Duyệt qua các phần tử
for key, value in od.items():
    print(key, value)
# Output:
# a 1
# b 2
# c 3

