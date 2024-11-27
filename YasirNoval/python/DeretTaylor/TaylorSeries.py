from math import expm1, exp

result = exp()

print(result)

def e (x, n):
    pow = 1
    fact = 1

    if (n == 0):
        return 1
    else:
        res = e (x, n-1)
        pow = pow * x
        fact = fact * n

        return res + pow / fact


print(e(5, 10))