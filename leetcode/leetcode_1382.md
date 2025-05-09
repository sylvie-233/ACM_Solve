# 1382. 将二叉搜索树变平衡

普通二叉树转平衡二叉树：中序遍历获取有序数组值，二分构造平衡树

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder_traversal(self, node: Optional[TreeNode], arr: list[int]):
        if node:
            self.inorder_traversal(node.left, arr)
            arr.append(node.val)
            self.inorder_traversal(node.right, arr)
    
    def build_bst(self, arr: list[int]) -> Optional[TreeNode]:
        if not arr:
            return None
        mid = len(arr) // 2
        node = TreeNode(arr[mid])
        node.left = self.build_bst(arr[:mid])
        node.right = self.build_bst(arr[mid+1:])
        return node

    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        arr = []
        self.inorder_traversal(root, arr)
        print(arr)
        return self.build_bst(arr)
```