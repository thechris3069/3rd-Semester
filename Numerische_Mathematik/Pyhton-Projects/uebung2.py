import math
# print(math.exp(2))
# print("------------")
# n=10000000000000
# while(n<10000000000010):
#     print((1+2/n)**n)
#     n=n+1

# print("------------")
# n=10000000000000000000000
# while(n<10000000000000000000010):
#     print((1+2/n)**n)
#     n=n+1


h = 0.00000000001
n = 1
print(math.cos(1))
print("------------")
while(n<10):
    print((math.sin(1+h)-math.sin(1))/h)
    h = h * 0.9
    n = n+1