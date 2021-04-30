def solution(list, k):
    presumSet = set()
    for cur in list:
        numToFind = k - cur
        if numToFind in presumSet:
            return True
        else:
            presumSet.add(cur)
    return False



if __name__ == "__main__":
    list = [10,15,3,7]
    k = 17
    print(solution(list, k))
    k = 16
    print(solution(list, k))
