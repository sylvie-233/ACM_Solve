# 206. 反转链表

链表
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        """
        left、right属于1~n
        """
        if left > right: return head
        
        # 哨兵前置节点
        myhead = ListNode(next=head)
        # 反转前置节点
        p0 = myhead
        for _ in range(left - 1):
            p0 = p0.next
        
        # 反转 right - left _ 1次
        pre = None
        cur = p0.next
        for _ in range(right - left + 1):
            # 反转next
            nxt = cur.next
            cur.next = pre
            # 指针后移
            pre = cur
            cur = nxt
        
        # 连接反转链表
        p0.next.next = cur
        p0.next = pre
        return myhead.next
    
    def get_count(self, head: Optional[ListNode]) -> int:
        res = 0
        while head:
            res += 1
            head = head.next
        return res

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = self.get_count(head)
        return self.reverseBetween(head, 1, cnt)
            
```