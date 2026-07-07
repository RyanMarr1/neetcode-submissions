/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* seekEnd = head;
        ListNode* nthNode = head;
        ListNode dummy;
        dummy.next = head;

        while (n > 0) {
            seekEnd = seekEnd->next;
            n--;
        }
        ListNode* prev = &dummy;
        while (seekEnd) {
            seekEnd = seekEnd->next;
            prev = nthNode;
            nthNode = nthNode->next;
        }
        prev->next = nthNode->next;
        return dummy.next;
    }
};
