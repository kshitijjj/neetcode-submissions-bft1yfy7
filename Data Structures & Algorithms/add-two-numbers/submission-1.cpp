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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        int digit=0;

        ListNode* dummy=new ListNode(-1);
        ListNode* dtemp=dummy;

        while(temp1!=NULL && temp2!=NULL){
            int sum=temp1->val + temp2->val + carry;
            carry=sum/10;
            digit=sum%10;
            ListNode* node=new ListNode(digit);
            dtemp->next=node;
            dtemp=dtemp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        while(temp1!=NULL){
            int sum=temp1->val + carry;
            carry=sum/10;
            digit=sum%10;
            ListNode* node=new ListNode(digit);
            dtemp->next=node;
            dtemp=dtemp->next;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            int sum=temp2->val + carry;
            carry=sum/10;
            digit=sum%10;
            ListNode* node=new ListNode(digit);
            dtemp->next=node;
            dtemp=dtemp->next;
            temp2=temp2->next;
        }

        while(carry!=0){
            ListNode* node=new ListNode(carry);
            dtemp->next=node;
            dtemp=dtemp->next;
            carry=carry/10;
        }
        
        return dummy->next;
    }
};
