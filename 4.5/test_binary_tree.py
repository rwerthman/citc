import unittest
from binary_tree import BinarySearchTree
from binary_tree import BinarySearchTreeNode
from binary_tree import size


class TestBinaryTree(unittest.TestCase):
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


if __name__ == '__main__':
    unittest.main()
