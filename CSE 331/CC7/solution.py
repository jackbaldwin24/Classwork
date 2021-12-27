"""
Name:
Coding Challenge 7 - Lonely Rolling Star - Solution Code
CSE 331 Fall 2020
Professor Sebnem Onsay
"""
from typing import List, Tuple


class Item:
    """
    A class that will store an item's name and category
    """

    def __init__(self, item_name: str, item_category: str):
        self.name = item_name
        self.category = item_category

    def __repr__(self):
        return "Item('" + self.name + "','" + self.category + "')"

    def get_name(self) -> str:
        """
        returns the strng representing the item's name
        :return: Item name string
        """
        return self.name

    def get_category(self) -> str:
        """
        Returns the string representation of the item's category
        :return: Item category string
        """
        return self.category


class RoboKingOfAllCosmos:

    def __init__(self):
        self.items = {}
        self.cat = {}

        # put your scoring container here

    def construct_score_book(self, items_and_size: List[Tuple[str, float]]) -> None:
        for item in items_and_size:
            self.items[item[0]] = item[1]

    def get_score_book(self) -> List[Tuple[str, float]]:
        result = []
        for name in self.items:
            result.append((name, self.items[name]))
        return result

    def judge_katamari(self, katamari_contents: List[Item]) -> Tuple[float, List[Tuple[str, int]], List[str]]:
        size = 0
        sorted_ = {}
        top_three = []
        cousins = []

        for kat in katamari_contents:
            size += self.items[kat.name]
            try:
                self.cat[kat.category] += 1
            except:
                self.cat[kat.category] = 1
            if kat.category == "cousins":
                cousins.append((kat.name, kat.category))

        dict(sorted(self.cat.items(), key=lambda item: item[1]))

        i = 0
        for cat in self.cat:
            if i == 3:
                break
            top_three.append((cat, self.cat[cat]))

        return size, top_three, cousins
