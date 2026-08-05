# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        seekEnd = head
        length = 0
        while seekEnd:
            seekEnd = seekEnd.next
            length += 1
        if length == n:
            return head.next
        currNode = head
        for _ in range(length - n - 1):
            currNode = currNode.next
        currNode.next = currNode.next.next
        return head
