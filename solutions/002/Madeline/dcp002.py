#calculate product of list
def product(numlist, n):
  result = 1
  for l in numlist:
    result *= l
  return result

#read in list
n = int(input("Enter number of elements: "))
numlist = list(map(int, input("\nEnter numbers: ").strip().split()))[ : n]
#create new list
bigProduct = product(numlist, n)
for i in range(0, n):
  numlist[i] = int(bigProduct / numlist[i])
print(numlist)

#FIXME: find solution without division