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

    ListNode* reverse(ListNode *head) {

        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr != NULL)
        {
            ListNode *forw = curr->next;

            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *head1 = reverse(head);

        ListNode *temp = head1;

        while(n > 1)
        {
            temp = temp->next;
            n--;
        }

        // deleting first node of reversed LL
        if(temp == head1)
        {
            head1 = head1->next;
        }

        else
        {
            ListNode *prev = head1;

            while(prev->next != temp)
            {
                prev = prev->next;
            }

            prev->next = temp->next;
        }

        head = reverse(head1);

        return head;
    }
};
