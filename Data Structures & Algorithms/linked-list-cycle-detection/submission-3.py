# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        onestep = head
        twostep = head
        while twostep and twostep.next:
            onestep = onestep.next
            twostep = twostep.next.next
            if twostep == onestep:
                return True
        return False