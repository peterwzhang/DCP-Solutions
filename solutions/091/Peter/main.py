# functions = []
# for i in range(10):
#     functions.append(lambda : i)

# for f in functions:
#     print(f())
# This will print 9, 10 times.
# Its accessing the same i which is 9 at the end.

# We need to use "closure" in order to make it print 0-9.
functions = []
for i in range(10):
    def num(num, i=i):
        return num * i
    functions.append(num)

for f in functions:
    print(f(1))