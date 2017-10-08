def depth_first_search(directed_graph):
    visited_list = []
    marked_list = []
    stack = []
    stack.insert(0, 0)
    while stack:
        node = stack.pop(0)
        visited_list.append(node)
        for adjacent_node in directed_graph[node][::-1]:
            if adjacent_node not in marked_list:
                marked_list.append(adjacent_node)
                stack.insert(0, adjacent_node)
    return visited_list

def breadth_first_search(directed_graph):
    visited_list = []
    marked_list = []
    queue = []
    queue.append(0) # Add the starting node to the queue
    while queue:
        node = queue.pop(0)
        visited_list.append(node)
        node_adjacency_list = directed_graph[node]
        for adjacent_node in node_adjacency_list:
            if adjacent_node not in marked_list:
                marked_list.append(adjacent_node)
                queue.append(adjacent_node)
    return visited_list


def route_between_nodes(directed_graph):
    pass
