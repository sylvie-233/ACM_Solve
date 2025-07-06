# 3606. 优惠券校验器

简单排序


```python
import re

class Solution:
    @staticmethod
    def is_valid_code(s: str) -> bool:
        return re.fullmatch(r'\w+', s) is not None
    
    @staticmethod
    def is_valid_businessLine(s: str) -> bool:
        return s == "electronics" or s == "grocery" or s == "pharmacy" or s == "restaurant"

    def validateCoupons(self, code: list[str], businessLine: list[str], isActive: list[bool]) -> list[str]:
        index_arr= []
        for i in range(len(code)):
            if Solution.is_valid_code(code[i]) and Solution.is_valid_businessLine(businessLine[i]) and isActive[i]:
                index_arr.append(i)
        
        # print(index_arr)
        sort_index_arr = sorted(index_arr, key=lambda i: (businessLine[i], code[i]))
        # print(sort_index_arr)
        res = [code[i] for i in sort_index_arr]
        return res
```