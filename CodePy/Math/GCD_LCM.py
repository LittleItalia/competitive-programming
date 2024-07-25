import math

# ---------------[CODING]---------------
arr = list(map(int, input().split()))
n = arr[0]
m = arr[1]

def GCD(n, m):
    if(m == 0):
        return n
    return GCD(m, n % m)

def LCM(n, m):
    return (n * m) // GCD(n, m)

print(LCM(n, m))
# ######################################
