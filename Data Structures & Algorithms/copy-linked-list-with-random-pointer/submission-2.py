"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr = head
        while curr:
            temp = curr.next
            curr.next = Node(curr.val, temp)
            curr = temp
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
        curr = head
        dummy = Node(0)
        result = dummy
        while curr:
            result.next = curr.next
            result = result.next
            curr.next = curr.next.next
            curr = curr.next
        return dummy.next
        