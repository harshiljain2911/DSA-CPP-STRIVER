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
    ListNode* middle(ListNode* head) {

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);

        ListNode* temp = &dummy;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // remaining nodes
        if (left != NULL) {
            temp->next = left;
        }

        if (right != NULL) {
            temp->next = right;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* cntr = middle(head);
        ListNode *mid = cntr->next;
        cntr->next = NULL;

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);



        return merge(left,right);

    }
};
