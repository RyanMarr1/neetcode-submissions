# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(next = head)
        seekEnd = head
        while n > 0:
            seekEnd = seekEnd.next
            n -= 1
        curr = dummy
        while seekEnd:
            seekEnd = seekEnd.next
            curr = curr.next
        curr.next = curr.next.next
        return dummy.next
