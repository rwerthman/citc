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

def is_bst(node):
    '''
    Check if binary tree is a binary search tree.
    Return True if the tree is a binary search tree.
    Return False if the tree is not a binary search tree.

    '''
    node_list = []
    while node is not None:
        if node.left is not None:
            if node.left.data <= node.data:
                node_list.append(node.left)
            else:
                return False
        if node.right is not None:
            if node.right.data > node.data:
                node_list.append(node.right)
            else:
                return False
        if node_list:
            node = node_list.pop(0)
        else:
            node = None
    return True

class BinarySearchTreeNode(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
