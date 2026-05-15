# 739. 每日温度

**<pre>给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。</pre>**

<pre>
示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
</pre>
<pre>
示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
</pre>
<pre>
示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]
</pre>
<pre>
提示：
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
</pre>
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> sta;
        // 从右往左遍历，维护单调递减的栈，如果栈顶小于等于当前值，则删除，剩下的栈顶就是下一个更高温度
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!sta.empty() && temperatures[i] >= temperatures[sta.top()]) {
                sta.pop();
            }
            if (!sta.empty()) {
                ans[i] = sta.top() - i;
            }
            sta.push(i);
        }
        return ans;
    }
};
```