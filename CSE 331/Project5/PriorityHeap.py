from typing import List, Tuple, Any


class Node:
    """
    Node definition should not be changed in any way
    """
    __slots__ = ['key', 'value']

    def __init__(self, k: Any, v: Any):
        """
        Initializes node
        :param k: key to be stored in the node
        :param v: value to be stored in the node
        """
        self.key = k
        self.value = v

    def __lt__(self, other):
        """
        Less than comparator
        :param other: second node to be compared to
        :return: True if the node is less than other, False if otherwise
        """
        return self.key < other.key or (self.key == other.key and self.value < other.value)

    def __gt__(self, other):
        """
        Greater than comparator
        :param other: second node to be compared to
        :return: True if the node is greater than other, False if otherwise
        """
        return self.key > other.key or (self.key == other.key and self.value > other.value)

    def __eq__(self, other):
        """
        Equality comparator
        :param other: second node to be compared to
        :return: True if the nodes are equal, False if otherwise
        """
        return self.key == other.key and self.value == other.value

    def __str__(self):
        """
        Converts node to a string
        :return: string representation of node
        """
        return '({0}, {1})'.format(self.key, self.value)

    __repr__ = __str__


class PriorityQueue:
    """
    Partially completed data structure. Do not modify completed portions in any way
    """
    __slots__ = ['data']

    def __init__(self):
        """
        Initializes the priority heap
        """
        self.data = []

    def __str__(self) -> str:
        """
        Converts the priority heap to a string
        :return: string representation of the heap
        """
        return ', '.join(str(item) for item in self.data)

    __repr__ = __str__

    def to_tree_format_string(self) -> str:
        """
        Prints heap in Breadth First Ordering Format
        :return: String to print
        """
        string = ""
        # level spacing - init
        nodes_on_level = 0
        level_limit = 1
        spaces = 10 * int(1 + len(self))

        for i in range(len(self)):
            space = spaces // level_limit
            # determine spacing

            # add node to str and add spacing
            string += str(self.data[i]).center(space, ' ')

            # check if moving to next level
            nodes_on_level += 1
            if nodes_on_level == level_limit:
                string += '\n'
                level_limit *= 2
                nodes_on_level = 0
            i += 1

        return string

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   Modify below this line

    def swap(self, index_1: int, index_2: int):
        """
        Swaps two Nodes in the PriorityQueue given both their indices
        :param index_1: index of the first Node to be swapped
        :param index_2: index of the second Node to be swapped
        """
        self.data[index_1], self.data[index_2] = self.data[index_2], self.data[index_1]

    def __len__(self) -> int:
        """
        Returns the length of the PriorityQueue
        :return: length of the PriorityQueue
        """
        return len(self.data)

    def empty(self) -> bool:
        """
        Checks if the PriorityQueue is empty
        :return: bool representation of the list being empty
        """
        return len(self.data) == 0

    def top(self) -> Node:
        """
        Gets the root Node
        :return: root Node
        """
        if self.empty():
            return None
        return self.data[0]

    def get_left_child_index(self, index: int) -> int:
        """
        Returns the left child of a Node at a specified index
        :param index: index of Node to find the left child of
        """
        left_index = 2 * index + 1
        if left_index < len(self):
            return left_index
        return None

    def get_right_child_index(self, index: int) -> int:
        """
        Returns the right child of a Node at a specified index
        :param index: index of Node to find the right child of
        """
        right_index = 2 * index + 2
        if right_index < len(self):
            return right_index
        return None

    def get_parent_index(self, index: int) -> int:
        """
        Returns the parent of a Node at a specified index
        :param index: index of Node to find the parent of
        """
        parent_index = (index - 1) // 2
        if parent_index >= 0:
            return parent_index
        return None

    def push(self, key: Any, val: Any) -> None:
        """
        Adds a new Node
        """
        node = Node(key, val)
        self.data.append(node)
        self.percolate_up(len(self.data) - 1)

    def pop(self) -> Node:
        """
        Removes the smallest element from the PriorityQueue
        """
        if self.empty():
            return None
        result = self.data[0]
        self.swap(0, len(self) - 1)
        self.data.pop()
        self.percolate_down(0)
        return result

    def get_min_child_index(self, index: int) -> int:
        """
        Returns the smaller child of a Node at a specified index
        :param index: index of the Node to find the smaller child of
        """
        small_child = self.get_left_child_index(index)
        if small_child is not None:
            right_index = self.get_right_child_index(index)
            if right_index is not None and self.data[right_index] < self.data[small_child]:
                small_child = right_index
        return small_child

    def percolate_up(self, index: int) -> None:
        """
        Moves the Node at a specified index up to its valid spot in the heap
        :param index: index of the Node to be percolated up
        """
        parent_index = self.get_parent_index(index)
        if parent_index is not None:
            if index > 0 and self.data[parent_index] > self.data[index]:
                self.swap(index, parent_index)
            self.percolate_up(parent_index)

    def percolate_down(self, index: int) -> None:
        """
        Moves the Node at a specified index down to its valid spot in the heap
        :param index: index of the Node to be percolated down
        """
        child = self.get_min_child_index(index)
        if child is not None:
            if self.data[child] < self.data[index]:
                self.swap(index, child)
                self.percolate_down(child)


class MaxHeap:
    """
    Partially completed data structure. Do not modify completed portions in any way
    """
    __slots__ = ['data']

    def __init__(self):
        """
        Initializes the priority heap
        """
        self.data = PriorityQueue()

    def __str__(self):
        """
        Converts the priority heap to a string
        :return: string representation of the heap
        """
        return ', '.join(str(item) for item in self.data.data)

    def __len__(self):
        """
        Length override function
        :return: Length of the data inside the heap
        """
        return len(self.data)

    def print_tree_format(self):
        """
        Prints heap in bfs format
        """
        self.data.tree_format()

    #   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #   Modify below this line

    def empty(self) -> bool:
        """
        Checks if the MaxHeap is empty
        """
        return self.data.empty()

    def top(self) -> int:
        """
        Gives the root value
        """
        top_node = self.data.top()
        if top_node is not None:
            return top_node.value

    def push(self, value: int) -> None:
        """
        Adds the value to the heap
        :param value: value to be added to the heap
        """
        self.data.push(-value, value)

    def pop(self) -> int:
        """
        Removes the largest element from the heap
        """
        return self.data.pop().value


def heap_sort(array):
    """
    Sorts an array of ints in ascending order using a MaxHeap.
    :param array: array of ints to be sorted
    """
    heap = MaxHeap()
    for num in array:
        heap.push(num)
    end_index = len(array)-1
    for i in range(len(array)):
        array[end_index] = heap.pop()
        end_index -= 1
    return array


def find_ranking(rank, results: List[Tuple[int, str]]) -> str:
    """
    Given a list of tuples -- with each tuple containing the amount of
    losses that team suffered and the team name -- find the team that
    finished in the position "rank".
    :param rank: rank of the team to find
    :param results: List of tuples containing the number of losses and the name of the team
    :return: string containing the name of the team with the specified rank
    """
    queue = PriorityQueue()
    if rank > len(results):
        return None
    for team in results:
        queue.push(team[0], team[1])
    for i in range(rank):
        result = queue.pop()
    return result.value
