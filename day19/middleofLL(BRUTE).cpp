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

    int getLength(ListNode* head) {

        int ctr = 0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            ctr++;
            temp = temp->next;
        }

        return ctr;
    }

    ListNode* middleNode(ListNode* head) {

        int count = getLength(head);

        int mid = count / 2;

        ListNode* temp = head;

        while(mid > 0)
        {
            temp = temp->next;
            mid--;
        }

        return temp;
    }
};
