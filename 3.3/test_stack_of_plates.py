import unittest
from stack_of_plates import StackNode
from stack_of_plates import Stack


class TestStackClass(unittest.TestCase):

    def testpushsingle(self):
        n = StackNode(10)
        s = Stack(n)
        self.assertTrue(s.top is not None)
        self.assertTrue(s.top.data == 10)
        self.assertTrue(s.size() == 1)

    def testpushmultiple(self):
        n = StackNode(12)
        n2 = StackNode(10)
        s = Stack(n)
        s.push(n2)
        self.assertTrue(s.top is not None)
        self.assertTrue(s.top.data == 10)
        self.assertTrue(s.size() == 2)

    def testpop(self):
        n2 = StackNode(12)
        n = StackNode(10)
        s = Stack(n)
        s.push(n2)
        n = s.pop()
        self.assertTrue(s.top is not None)
        self.assertTrue(s.top.data == 10)
        self.assertTrue(n.data == 12)

    def testisEmpty(self):
        n2 = StackNode(12)
        n = StackNode(10)
        s = Stack(n)
        s.push(n2)
        n = s.pop()
        self.assertFalse(s.isEmpty())
        n = s.pop()
        self.assertTrue(n.data == 10)
        self.assertTrue(s.isEmpty())

    def testsize(self):
        n2 = StackNode(12)
        n = StackNode(10)
        s = Stack(n)
        s.push(n2)
        self.assertTrue(s.size() == 2)
        s.pop()
        self.assertTrue(s.size() == 1)

class testSetOfStacks(unittest.TestCase):

    def testpush():
        pass

    def testpop():
        pass

if __name__ == '__main__':
    unittest.main()
