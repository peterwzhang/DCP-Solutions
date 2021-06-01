def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    def returnfirst(a,b):
        return a
    return pair(returnfirst)

def cdr(pair):
    def returnlast(a,b):
        return b
    return pair(returnlast)

def add(a,b):
    return a+b

# print(cons(1,2).__closure__[0].cell_contents)
something = cons(1,2)
something(print)
print(something(add))
print(cdr(something))
print(car(something))