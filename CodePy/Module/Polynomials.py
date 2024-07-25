import numpy

# Tao da thuc tu cac he so
p = numpy.poly1d([2, 3, 1])


# Tạo một đa thức từ các nghiệm: x = 1, x = 2, x = 3
coefficients = numpy.poly([1, 2, 3])
print(coefficients)
# Output: [ 1. -6. 11. -6.]
# Đa thức tương ứng là x^3 - 6x^2 + 11x - 6


# Tim nghiem cua da thuc:   f(x) = x^2 - 1
print(numpy.roots([1, 0, -1]))   #Output: [-1. 1]


# Tich phan cua da thuc
print(numpy.polyint([1, 1, 1]))   #Output: [0.3333333 0.5 1. 0.]


# Dao ham cua da thuc
print(numpy.polyder([1, 1, 1, 1]))   #Output: [3. 2. 1.]


# Tinh gia tri cua da thuc tai x 
print(numpy.polyval([1, -2, 0, 2], 4))   #Output: 34


# + - * / da thuc
p1 = numpy.poly1d([2, 3, 1])
p2 = numpy.poly1d([1, 2])

print(numpy.polyadd(p1, p2))   #Output: 2 x^2 + 4 x + 3
print(numpy.polymul(p1, p2))   #Output: 2 x^3 + 7 x^2 + 7 x + 2
print(numpy.polysub(p1, p2))   
print(numpy.polydiv(p1, p2))

