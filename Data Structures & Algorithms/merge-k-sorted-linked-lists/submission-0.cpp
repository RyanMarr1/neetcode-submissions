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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        while (lists.size() > 1) {
            int insert_index = 0;
            int i = 0;
            while (i < lists.size() - 1) {
                ListNode dummy;
                ListNode* curr = &dummy;
                while (lists[i] && lists[i + 1]) {
                    if (lists[i]->val < lists[i + 1]->val) {
                        curr->next = lists[i];
                        lists[i] = lists[i]->next;
                    }
                    else {
                        curr->next = lists[i + 1];
                       lists[i + 1] = lists[i + 1]->next; 
                    }
                    curr = curr->next;
                }
                if (!lists[i]) {
                    curr->next = lists[i + 1];
                }
                else if (!lists[i + 1]) {
                    curr->next = lists[i];
                }
                lists[insert_index] = dummy.next;
                insert_index++;
                i += 2;
            }
            if (i == lists.size() - 1) {
                lists[insert_index] = lists[i];
                insert_index++;
            }
            lists.resize(insert_index);
        }
        return lists[0];
    }
};
