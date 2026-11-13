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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        ListNode* temp = list1;
        ListNode* te = list2;

        while(temp && te) {
            if(temp->val <= te->val) {
                curr->next = temp;
                temp = temp->next;
            }
            else {
                curr->next = te;
                te = te->next;
            }
            curr = curr->next;
        }

        if(temp) {
            curr->next = temp;
        }
        if(te) {
            curr->next = te;
        }

        return ans->next;
    }
};
