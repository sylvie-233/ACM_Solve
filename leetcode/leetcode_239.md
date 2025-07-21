# 239 滑动窗口最大值

**<pre>
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。</pre>**

<pre>
示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
</pre>
<pre>
示例 2：

输入：nums = [1], k = 1
输出：[1]
</pre>
<pre>
提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
</pre>
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        int rpos = 0;
        deque<int> deq;
        vector<int> ans;
        // 初始化单调队列(k-1个、从左到右单调递减)
        while (rpos <= k - 2) {
            while (!deq.empty() && nums[deq.back()] <= nums[rpos]) deq.pop_back();
            deq.push_back(rpos++);
        }

        for (int i = 0; i <= len - k; i++) {
            // 新增右边界元素
            if (i + k - 1 < len) {
                while (!deq.empty() && nums[deq.back()] <= nums[i + k - 1]) {
                    deq.pop_back();
                }
                deq.push_back(i + k - 1);
            }

            // 最大值为 队列左侧第一个
            ans.push_back(nums[deq.front()]);
            
            // 左边界弹出判断
            if (i >= deq.front()) deq.pop_front();
        }
        return ans;
    }
};
```

```python
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from collections import deque
        # 单调队列，存放索引
        q = deque()
        res = []

        for i, x in enumerate(nums):
            while q and nums[q[-1]] <= x:
                q.pop() 
            q.append(i)
            if i >= k - 1:
                while q and q[0] < i - k + 1:
                    q.popleft()
                if q: 
                    res.append(nums[q[0]])
                else: 
                    res.append(None)
        return res
```