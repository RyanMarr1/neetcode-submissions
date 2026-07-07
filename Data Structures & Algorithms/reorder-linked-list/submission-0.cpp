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
    void reorderList(ListNode* head) {
        ListNode* seekEnd = head;
        ListNode* middle = head;
        while (seekEnd->next && seekEnd->next->next) {
            middle = middle->next;
            seekEnd = seekEnd->next->next;
        }
        ListNode* rHalf = middle->next;
        middle->next = NULL;

        ListNode* prev = NULL; // prev will be sorted rHalf after loop
        ListNode* curr = rHalf;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        while (prev && head) {
            ListNode* frontHalf = head->next;
            head->next = prev;
            ListNode* backHalf = prev->next;
            prev->next = frontHalf;
            prev = backHalf;
            head = frontHalf;
        }
    }
};
