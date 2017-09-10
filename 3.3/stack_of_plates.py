
class SetOfStacks(object):

    def __init__(self, top, threshold):
        """ Initialize with a top stack """
        self.top = top
        self.threshold = threshold

    def push(self, n):
        if self.top.size() >= self.threshold:
            # Create a new stack
            new_stack = Stack(n)
            new_stack.next = self.top
            self.top = new_stack
        else:
            self.top.push(n)

    def pop(self):
        if self.top.size() == 1:
            s = self.top
            self.top = self.top.next
            return s.pop()
        else:
            self.top.pop()

    def size(self):
        size = 0
        s = self.top
        while s is not None:
            size += 1
            s = s.next
        return size

class Stack(object):

    def __init__(self, top):
        """ Initialize with top stack node """
        self.top = top
        self.next = None # Point to the next stack of plates

    def pop(self):
        """ Remove the top element from the stack """
        top = self.top
        self.top = self.top.next
        return top

    def push(self, n):
        """ Add an element to the top of the stack """
        n.next = self.top
        self.top = n

    def isEmpty(self):
        """ Checks to see if the stack is empty """
        if self.top is None:
            return True
        else:
            return False

    def size(self):
        size = 0
        n = self.top
        while n is not None:
            size = size + 1
            n = n.next
        return size


class StackNode(object):

    def __init__(self, data):
        self.data = data
        self.next = None
