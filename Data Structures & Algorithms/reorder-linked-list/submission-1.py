# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        seekEnd = head
        middle = head
        while seekEnd.next and seekEnd.next.next:
            seekEnd = seekEnd.next.next
            middle = middle.next
        rHalf = middle.next
        middle.next = None
        prevNode = None
        while rHalf:
            nextNode = rHalf.next
            rHalf.next = prevNode
            prevNode = rHalf
            rHalf = nextNode
        rHalfReversed = prevNode
        while rHalfReversed:
            rNode = rHalfReversed
            rHalfReversed = rHalfReversed.next
            rNode.next = head.next
            head.next = rNode
            head = rNode.next
            rNode.next = head
