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
        OGtoCopy = {None: None}
        og_copy = head
        while og_copy:
            new_list = Node(og_copy.val)
            OGtoCopy[og_copy] = new_list
            og_copy = og_copy.next
        og_copy = head
        while og_copy:
            copyNode = OGtoCopy[og_copy]
            copyNode.random = OGtoCopy[og_copy.random]
            copyNode.next = OGtoCopy[og_copy.next]
            og_copy = og_copy.next
        return OGtoCopy[head]