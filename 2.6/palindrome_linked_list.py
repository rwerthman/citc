import unittest

class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

def addNode(head, data):
    if head.next is None:
        head.next = Node(data)
    else:
        return addNode(head.next, data)

def getSize(head):
    size = 0
    while head != None:
        head = head.next
        size = size + 1
    return size

def listAsString(head):
    list_as_string = ''
    while head != None:
        list_as_string = list_as_string + str(head.data) + '=>'
        head = head.next
    return list_as_string + 'None'

def removeNode(head, data):
    # The head node is the one to be removed
    if head.data == data:
        head = head.next
    else:
        curr = head
        while curr != None:
            prev = curr
            curr = curr.next
            if curr != None:
                if curr.data == data:
                    prev.next = curr.next
    return head

def isPalindrome(head):
    is_palindrome = False
    list_as_string = ''
    while head != None:
        list_as_string = list_as_string + head.data
        head = head.next
    if list_as_string == list_as_string[::-1]:
        is_palindrome = True
    return is_palindrome

def assertionTest(test, msg):
    if test:
        print 'PASSED: ', msg
    else:
        print 'FAILED: ', msg


def main():
    head = Node('r')
    addNode(head, 'a')
    addNode(head, 'r')

    assertionTest(isPalindrome(head) is True, 'List is palindrome.')
    assertionTest(getSize(head) == 3, 'List is correct size.')

    head = Node('c')
    addNode(head, 'r')
    addNode(head, 'a')
    addNode(head, 'z')
    addNode(head, 'y')

    assertionTest(isPalindrome(head) is False, 'List is not a palindrome.')
    assertionTest(getSize(head) == 5, 'List is correct size.')

    head = removeNode(head, 'y')
    assertionTest(getSize(head) == 4, 'List is correct size.')
    print listAsString(head)

class TestLinkedListMethods(unittest.TestCase):

    def testGetSize(self):
        head = Node('r')
        addNode(head, 'a')
        addNode(head, 'r')
        self.assertTrue(isPalindrome(head))

if __name__ == '__main__':
    main()
    unittest.main()
