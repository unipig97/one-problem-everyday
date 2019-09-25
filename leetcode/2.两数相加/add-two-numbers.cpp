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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res =l1,*lastnode=NULL;
        bool adding = false;
        while(l1 != NULL || l2 !=NULL){
            if(l1 != NULL && l2 !=NULL){
                if(adding == true){
                    l1->val +=1;
                    adding = false;
                }
                l1->val+=l2->val;
                if(l1->val >= 10){
                    l1->val -=10;
                    adding = true;
                }
            }else if(l1 == NULL && l2 !=NULL){
                lastnode->next = new ListNode(l2->val);
                l1 = lastnode->next;
                if(adding ==true){
                    l1->val +=1;
                    adding = false;
                }
                if(l1->val >= 10){
                    l1->val -=10;
                    adding = true;
                }
            }else if(l1 != NULL && l2 == NULL){
                if(adding == true){
                    l1->val +=1;
                    adding = false;
                }
                if(l1->val >= 10){
                    l1->val -=10;
                    adding = true;
                }
            }
            if(l1!=NULL) {lastnode = l1;l1 = l1->next; }
            if(l2!=NULL) l2 = l2->next;
        }
        if(adding == true){
            lastnode->next = new ListNode(1);
            adding = false;
        }
        return res;
    }
};