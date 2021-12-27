from PriorityHeap import Node, PriorityQueue, heap_sort, MaxHeap, find_ranking
heap = PriorityQueue()
heap.data = [Node(1, '231'), Node(2, '232'), Node(3, '260'), Node(4, '331'), Node(5, '431')]
heap.get_parent_index(4)