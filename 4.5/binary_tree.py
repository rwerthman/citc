class BinarySearchTree(object):
    def __init__(self, root):
        self.root = root

    def insert(self, data):
        bstn = self.root
        while bstn != None:
            # If the data is less than the current nodes data go to the left
            # down the tree because of the BST invariant.
            if data <= bstn.data:
                # If we find a node with an empty left child then put the data
                # into a new bstn and insert it into that spot in the tree.
                if bstn.left is None:
                    bstn.left = BinarySearchTreeNode(data)
                    break
                else:
                    bstn = bstn.left
            else:
                # If we find a node with an empty right child then put the data
                # into a new bstn and insert it into that spot in the tree.
                if bstn.right is None:
                    bstn.right = BinarySearchTreeNode(data)
                    break
                else:
                    bstn = bstn.right

    def remove(self, data):
        pass

    def is_in_tree(self, data):
        bstn = self.root
        while bstn != None:
            # If we find a node with same value as data
            if bstn.data == data:
                return True
            # If what we are searching for is less than or equal to what is
            # in the current node then we should go left.
            if data <= bstn.data:
                bstn = bstn.left
            # Otherwise go the right because it is greater than what is in the
            # current node
            else:
                bstn = bstn.right
        return False

def size(node):
    if node is not None:
        return size(node.left) + 1 + size(node.right)
    return 0



class BinarySearchTreeNode(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
