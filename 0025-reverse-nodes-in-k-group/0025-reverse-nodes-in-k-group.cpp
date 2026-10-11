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
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
    ListNode* getKthNode(ListNode *temp,int k){
        while(temp && --k>0){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;
        ListNode *temp=head;
        ListNode *prevLast=NULL;
        while(temp){
            ListNode *kthNode=getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode *nextNode=kthNode->next;
            kthNode->next=nullptr;
            reverseList(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prevLast->next=kthNode;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};