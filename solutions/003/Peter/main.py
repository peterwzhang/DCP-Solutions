class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def preorderhelper(root, serial):
    if (root is None):
        # assuming None will not be an input val
        serial.append("None")
        return
    serial.append(root.val)
    preorderhelper(root.left, serial)
    preorderhelper(root.right, serial)


def preorder(root):
    seriallist = list()
    preorderhelper(root, seriallist)
    returnstring = ""
    # print(seriallist)
    for node in seriallist:
        returnstring += node
        returnstring += " "
    return returnstring


def serialize(root):
    return preorder(root)


def deserializehelper(seriallist):
    cur = seriallist[0]
    seriallist.pop(0)
    if (cur == "None"):
        return None
    curNode = Node(cur)
    curNode.left = deserializehelper(seriallist)
    curNode.right = deserializehelper(seriallist)
    return curNode


def deserialize(serialstring):
    seriallist = serialstring.split(" ")
    return deserializehelper(seriallist)


node = Node('root', Node('left', Node('left.left')), Node('right'))
# print(serialize(node))
assert deserialize(serialize(node)).left.left.val == 'left.left'
assert deserialize(serialize(node)).right.val == 'right'