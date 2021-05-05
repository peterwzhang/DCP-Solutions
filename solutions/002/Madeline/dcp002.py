def productArray(numlist, n):
  if n == 1:
    print(0)
    return

  #Allocate memory for product array
  products = [1 for i in range(0, n)]
  temp = 1

  #create product array
  for i in range(0, n):
    products[i] = temp
    temp *= numlist[i]

  temp = 1
  for i in range(n - 1, -1, -1):
    products[i] *= temp
    temp *= numlist[i]

  print(products)


#read in list
n = int(input("Enter number of elements: "))
numlist = list(map(int, input("\nEnter numbers: ").strip().split()))[ : n]
productArray(numlist, n)