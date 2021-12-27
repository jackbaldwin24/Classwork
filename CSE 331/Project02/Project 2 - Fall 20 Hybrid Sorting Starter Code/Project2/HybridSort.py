"""
Name: Jackson Baldwin
Project 2 - Hybrid Sorting - Starter Code
CSE 331 Fall 2020
Professor Sebnem Onsay
"""
from typing import List, Any, Dict


def hybrid_sort(data: List[Any], threshold: int) -> None:
    """
    Calls merge_sort to sort a list of ints or strings with a certain threshold
    :param data: List[Any] list of strings or ints to be sorted
    :param threshold: [int] int representing the size of the sublist
        at which insertion sort should be used
    """
    merge_sort(data, threshold)


def inversions_count(data: List[Any]) -> int:
    """
    Calls merge_sort to retrieve the inversion count of a list of ints or
    strings
    :param data: List[Any] list of strings or ints to have its inversion count calculated
    :return [int] an int representing the inversion count of the list
    """
    return merge_sort(data)


# citations 2 and 3
def merge(data_1: List[Any], data_2: List[Any], data: List[Any]) -> int:
    """
    Merges two lists of ints or strings into ascending/alphabetical
    order while keeping track of the inversion count
    :param data_1: List[Any] sublist of the first half of data
        which needs to be merged needs to be merged
    :param data_2: List[Any] sublist of the the second half
        data which needs to be merged
    :param data: List[Any] list in which contains values
        of both data_1 and data_2 in ascending/alphabetical order
    :return [int] int representing the inversion count of data_1 and data_2
    """
    inversion_count = 0
    i = j = 0
    while i + j < len(data):
        if j == len(data_2) or (i < len(data_1) and data_1[i] <= data_2[j]):
            data[i + j] = data_1[i]
            i += 1
        else:
            inversion_count += len(data_1) - i
            data[i + j] = data_2[j]
            j += 1

    return inversion_count


# citation 2
def merge_sort(data: List[Any], threshold: int = 0) -> int:
    """
    Sorts a list of ints or strings in ascending/alphabetical order
    :param data: List[Any] list of strings or ints to be sorted
    :param threshold: [int] int representing the size of the sublist
        at which insertion sort should be used
        (only called with inversions_count())
    :return [int] int representing the inversion count of the list
    """

    inversion_count = 0
    length = len(data)

    if length < 2:
        return 0

    mid = length // 2
    data_1 = data[0:mid]
    data_2 = data[mid:length]

    if threshold != 0:
        if len(data_1) <= threshold:
            insertion_sort(data_1)
        else:
            inversion_count += merge_sort(data_1)
        if len(data_2) <= threshold:
            insertion_sort(data_2)
        else:
            inversion_count += merge_sort(data_2)
    else:
        inversion_count += merge_sort(data_1)
        inversion_count += merge_sort(data_2)

    inversion_count += merge(data_1, data_2, data)
    return inversion_count


# citation 1
def insertion_sort(data: List[Any]) -> None:
    """
    Sorts a list of ints or strings in ascending/alphabetical order
    :param data: List[Any] list of ints or strings which needs to be sorted
    """
    length = len(data)
    for i in range(1, length):
        j = i
        while (j > 0) and (data[j] < data[j - 1]):
            data[j], data[j - 1] = data[j - 1], data[j]
            j -= 1


def find_match(user_interests: List[str], candidate_interests: Dict[str, List]) -> str:
    """
    Determines which candidate's interests are closest to the user's interests by
    comparing inversion counts between candidates
    :param user_interests: List[str] list of strings representing the user's interests
    :param candidate_interests: Dict[str, List] dictionary with the keys representing
        the names of the candidates,
        and the values representing lists of interests for each candidate
    :return [str] string representing the name of the candidate whose interests align closest with the user's
    """

    # maps each user interest to numbers in ascending order starting from 0
    order = {key: i for i, key in enumerate(user_interests)}  # citation 4

    least_inv = ""
    least_num_inv = 0

    for key in candidate_interests:
        interests = []
        for interest in candidate_interests[key]:
            # initializes interests of each candidate to their corresponding number
            interests.append(order[interest])

        # if the key is the first one in the dictionary, initialize its list inversion count to least_num_inv
        if key == list(candidate_interests.keys())[0]:  # citation 5
            least_num_inv = inversions_count(interests)
            least_inv = key

        # tests to see if the current number of inversions is less than the least number of inversions
        else:
            inv_count = inversions_count(interests)
            if inv_count < least_num_inv:
                least_num_inv = inv_count
                least_inv = key
    return least_inv
