n=int(input())

start=0
end=min(15,n)
mid=(start+end)/2
while start<=end:
    mid=(start+end)/2
    if abs(mid**mid-n)<1e-7 :
        print(mid)
        break
    elif (mid**mid)<n:
        start=mid
    else :
        end=mid


# from rubik.cube import Cube
# from itertools import permutations


# def genSeq(faces, permutation):
#     map = "OWGYBR"
#     for i in range(len(faces)):
#         face = list(faces[i])
#         face[4] = map[permutation[i]] 
#         faces[i] = "".join(face)
#     return faces



# p = permutations(range(0,6))

# Lines = [
#     "O"*9,"R"*9,"W"*9,"G"*9,"Y"*9,"R"*9
# ]
# c = Cube("".join(Lines))


# cor = []

# for permutation in p:
#     d = "".join(genSeq(Lines, permutation))
#     d = Cube
#     print(c == d)
#     if c==d : cor.append(permutation)

# print(cor)









# import sympy 
# import numpy as np
# import math
# import matplotlib.pyplot as plt

# x = sympy.symbols('x')

# def f(a): return np.cos(a)

# g = sympy.cos(x)

# print(sympy.Derivative(g, x, evaluate=True))

# x = np.linspace(-5,5,100)
# y = np.cos(x)

# plt.plot(x, y)
# plt.show()


