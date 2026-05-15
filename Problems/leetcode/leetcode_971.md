# 971. 翻转二叉树以匹配先序遍历


二叉树遍历


```python
class Solution:
    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: list[int]) -> list[int]:
        res = []
        temp: deque[TreeNode] = deque([])
        def dfs(node: Optional[TreeNode], arr: list[int]) -> bool:
            if len(arr) == 0:
                return True
            if node is None:
                if temp[-1].val != arr[0]:
                    return False
                else:
                    t = temp.pop()
                    r = dfs(t, arr)
                    temp.append(t)
                    return r
            else:
                if node.val != arr[0]:
                    return False
                else:
                    if node.right is not None:
                        temp.append(node.right)
                    r = dfs(node.left, arr[1:])
                    if node.right is not None:
                        temp.pop()
                    if r:
                        return True
                    else:
                        if node.left is not None:
                            temp.append(node.left)
                        r = dfs(node.right, arr[1:])
                        if node.left is not None:
                            temp.pop()
                        if r:
                            if node.left is not None:
                                res.append(node.val)
                            return True
                        else:
                            return False
        
        if dfs(root, voyage):
            return res
        else:
            return [-1]
```