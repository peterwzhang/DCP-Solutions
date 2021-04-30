n = int(input("Enter number of elements: "))
numlist = list(map(int, input("\nEnter numbers: ").strip().split()))[ : n]
k = int(input("\nEnter k: "))

leftovers = []
#TODO: ensure duplicates aren't added to list (for efficiency)
for num in numlist :
  for l in leftovers :
    if num == l : 
      print("\nTrue: ", num, " + ", k - num, " = ", k)
      quit()
  leftovers.append(k - num)

print("\nFalse: No two numbers add up to ", k)