from math import factorial

def solve():
    return sum(map(int, str(factorial(100))))

print(solve())
