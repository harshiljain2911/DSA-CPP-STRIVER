/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:


    ListNode *collisionpoint(ListNode *small,ListNode *greater,int difference) {

        ListNode *temp1 = small;
        ListNode *temp2 = greater;
        


        while(difference>0)
        {
            temp2 = temp2->next;
            difference--;
        }

        while(temp1 != NULL)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        return NULL;



    }


    int getLength(ListNode* head) {
        int ctr = 0;
        ListNode *temp = head;
        while(temp != NULL)
        {
            ctr++;
            temp = temp->next;
        }

        return ctr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lA = getLength(headA);
        int lB = getLength(headB);

        if(lA<=lB)
        {

            return collisionpoint(headA,headB,lB-lA);

        }
        else
        {

            return collisionpoint(headB,headA,lA-lB);

        }



    }
};
