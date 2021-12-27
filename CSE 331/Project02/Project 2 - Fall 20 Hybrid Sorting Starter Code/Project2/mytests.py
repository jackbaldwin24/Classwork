from HybridSort import insertion_sort, merge_sort, hybrid_sort, inversions_count, find_match
import random

data = [random.randint(0, 100) for _ in range(50)]

inversions = inversions_count(data)



print(inversions)
