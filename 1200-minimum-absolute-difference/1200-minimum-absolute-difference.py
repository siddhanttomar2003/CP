class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        ans = []
        n = len(arr)
        mini = 10**9
        for i in range(n - 1):
            mini = min(mini, arr[i + 1] - arr[i])
        for i in range(n - 1):
            diff = arr[i + 1] - arr[i]
            if diff == mini:
                ans.append([arr[i], arr[i + 1]])
        return ans