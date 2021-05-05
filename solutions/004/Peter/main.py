def partition(array):
    index = 0
    for i in range(1, len(array)):
        if (array[i] <= 0):
                temp = array[index]
                array[index] = array[i]
                array[i] = temp
                index += 1
    return index


def findMissingInt(array):
    start = partition(array)
    end = len(array)
    # special case: if all negative
    if array[end - 1] < 0:
        start += 1
    max = end - start + 1
    for i in range(start, end):
        if (array[i] <= max):
            index = abs(array[i]) + start - 1
            # print(index)
            if (index < end and array[index] > 0):
                array[index] *= -1
    for i in range(start, end):
        if (array[i] > 0):
            return i - start + 1
    return max


list1 = [3,4,-1,1]
list2 = [1,2,0]
list3 = [3, 4, -1, 1, -2]
list4 = [75,90,20,12,2,-1,3,-1,4,5,17,99]
list5 = [-1,-2,-3]
print(findMissingInt(list1))
print(findMissingInt(list2))
print(findMissingInt(list3))
print(findMissingInt(list4))
print(findMissingInt(list5))