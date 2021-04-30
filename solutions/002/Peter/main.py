def solution(array):
    left_product = [0] * len(array)
    right_product = [0] * len(array)
    for i in range(0, len(array)):
        if i == 0:
            left_product[0] = 1
        else:
            left_product[i] = left_product[i - 1] * array[i - 1]
    for i in range(len(array) - 1, -1, -1):
        if i == len(array) - 1:
            right_product[len(array) - 1] = 1
        else:
            right_product[i] = right_product[i + 1] * array[i + 1]
    answer = [0] * len(array)
    for i in range(0, len(array)):
        answer[i] = left_product[i] * right_product[i]
    return answer


if __name__ == "__main__":
    print("Test 1")
    array = [1,2,3,4,5]
    print(*solution(array))
    print("Test 2")
    array = [0,2,3,4,5]
    print(*solution(array))
    print("Test 3")
    array = [7, 10, 15, 9, 2, 3, 21]
    print(*solution(array))

