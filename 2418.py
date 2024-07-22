class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        sort_list = sorted(list(zip(heights, names)))
        return [item[1] for item in sort_list[::-1]]
