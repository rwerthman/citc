import unittest
from route_between_nodes import breadth_first_search
from route_between_nodes import depth_first_search
from route_between_nodes import route_between_nodes


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

    def test_route_between_nodes(self):
        self.assertTrue(route_between_nodes(self.directed_graph, 1, 2))
        self.assertFalse(route_between_nodes(self.directed_graph, 1, 5))
        self.assertTrue(route_between_nodes(self.directed_graph, 0, 2))

if __name__ == '__main__':
    unittest.main()
