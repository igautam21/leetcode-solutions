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
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *first=head,*second=head->next;
        while(second){
            int x=gcd(first->val,second->val);
            ListNode *temp=new ListNode(x);
            first->next=temp;
            temp->next=second;
            first=first->next->next;
            second=second->next;
        }
        return head;
    }
};