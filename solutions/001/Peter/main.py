def solution(list, k):
    presum_set = set()
    for cur in list:
        numToFind = k - cur
        if numToFind in presum_set:
            return True
        else:
            presum_set.add(cur)
    return False



if __name__ == "__main__":
    print("Test 1")
    list = [10,15,3,7]
    k = 17
    print(solution(list, k))
    print("Test 2")
    k = 16
    print(solution(list, k))
