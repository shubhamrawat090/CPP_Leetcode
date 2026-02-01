class Solution:
    def findDisappearedNumbers(self, nums):
        n = len(nums)
        temp = [0] * (n + 1)

        for num in nums:
            temp[num] = 1

        ans = []
        for i in range(1, n + 1):
            if temp[i] == 0:
                ans.append(i)

        return ans
