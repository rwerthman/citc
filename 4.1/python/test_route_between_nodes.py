import unittest
from route_between_nodes import breadth_first_search
from route_between_nodes import depth_first_search


class TestGraphSearching(unittest.TestCase):
    def setUp(self):
        self.directed_graph = {
            0: [1, 4, 5],
            1: [3, 4],
            2: [1],
            3: [2, 4],
            4: [],
            5: []
        }

    def test_breadth_first_search(self):
        self.assertEqual(
            breadth_first_search(self.directed_graph), [0, 1, 4, 5, 3, 2])

    def test_depth_first_search(self):
        self.assertEqual(
            depth_first_search(self.directed_graph), [0, 1, 3, 2, 4, 5])

if __name__ == '__main__':
    unittest.main()
