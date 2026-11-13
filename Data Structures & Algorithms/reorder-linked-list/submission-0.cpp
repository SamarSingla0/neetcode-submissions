
class Solution {
public:
    ListNode* reverse(ListNode* temp) {
        ListNode* prev = NULL;

        while(temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* move = reverse(slow->next);
        slow->next = NULL;

        ListNode* temp = head;

        while(move) {
            ListNode* front1 = temp->next;
            ListNode* front2 = move->next;

            temp->next = move;
            move->next = front1;

            temp = front1;
            move = front2;
        }
    }
};
