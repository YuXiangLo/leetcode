class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        nums, ret = [str(item) for item in nums], []
        for num in nums:
            new_num = ''
            for char in num:
                new_num += str(mapping[int(char)])
            ret.append(int(new_num))
        _, nums = zip(*sorted(list(zip(ret, nums)), key=lambda x: x[0]))
        return [int(item) for item in nums]
