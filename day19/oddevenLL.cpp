class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = head->next;

        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
