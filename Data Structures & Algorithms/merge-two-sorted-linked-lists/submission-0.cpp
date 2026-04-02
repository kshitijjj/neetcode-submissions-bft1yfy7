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
        ListNode* dummy=new ListNode(-1);
        ListNode* dummyTemp=dummy;

        ListNode* temp1=list1;
        ListNode* temp2=list2;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val >= temp2->val){
                ListNode* node=new ListNode(temp2->val);
                dummyTemp->next=node;
                dummyTemp=dummyTemp->next;
                temp2=temp2->next;
            }
            else if(temp1->val < temp2->val){
                ListNode* node=new ListNode(temp1->val);
                dummyTemp->next=node;
                dummyTemp=dummyTemp->next;
                temp1=temp1->next;
            }
        }

        while(temp1!=NULL){
            ListNode* node=new ListNode(temp1->val);
            dummyTemp->next=node;
            dummyTemp=dummyTemp->next;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            ListNode* node=new ListNode(temp2->val);
            dummyTemp->next=node;
            dummyTemp=dummyTemp->next;
            temp2=temp2->next;
        }
        return dummy->next;
    }
};
