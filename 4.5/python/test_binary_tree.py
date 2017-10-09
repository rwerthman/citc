import unittest
from binary_tree import BinarySearchTree
from binary_tree import BinarySearchTreeNode
from binary_tree import size
from binary_tree import is_bst


class TestBinarySearchTree(unittest.TestCase):
    def test_insert(self):
        bstn = BinarySearchTreeNode(10)
        bst = BinarySearchTree(bstn)

        bst.insert(12)
        bst.insert(8)

        self.assertFalse(bst.is_in_tree(9))
        self.assertTrue(bst.is_in_tree(12))
        self.assertTrue(bst.is_in_tree(8))

    def test_size(self):
        bstn = BinarySearchTreeNode(10)
        bst = BinarySearchTree(bstn)

        bst.insert(12)
        bst.insert(8)
        bst.insert(7)

        self.assertEqual(size(bst.root), 4)

    def test_is_bst(self):
        bstn = BinarySearchTreeNode(10)
        bst = BinarySearchTree(bstn)

        bst.insert(12)
        bst.insert(8)
        bst.insert(7)

        self.assertEqual(is_bst(bst.root, None, None), True)

        bstn = BinarySearchTreeNode(10)
        bstn.left = BinarySearchTreeNode(10)
        bstn.left.left = BinarySearchTreeNode(11)
        bstn.right = BinarySearchTreeNode(12)

        self.assertEqual(is_bst(bstn, None, None), False)

        bstn = BinarySearchTreeNode(20)
        bstn.left = BinarySearchTreeNode(10)
        bstn.left.right = BinarySearchTreeNode(25)
        bstn.right = BinarySearchTreeNode(30)

        self.assertEqual(is_bst(bstn, None, None), False)




if __name__ == '__main__':
    unittest.main()
