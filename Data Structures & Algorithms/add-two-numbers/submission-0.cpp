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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        int carry_over = 0;
        while (l1 || l2 || carry_over) {
            int l1_num = l1 ? l1->val : 0;
            int l2_num = l2 ? l2->val : 0;

            int sum = carry_over + l1_num + l2_num;
            carry_over = sum / 10;
            sum = sum % 10;

            curr->next = new ListNode(sum);
            curr = curr->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return dummy.next;
    }
};
