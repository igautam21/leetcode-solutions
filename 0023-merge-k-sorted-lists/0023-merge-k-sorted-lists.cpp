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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minh;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                minh.push({lists[i]->val,lists[i]});
            }
        }
        ListNode *ans=new ListNode(-1);
        ListNode *temp=ans;
        while(!minh.empty()){
            ListNode *node=minh.top().second;
            minh.pop();
            temp->next=node;
            temp=temp->next;
            if(node->next!=NULL){
                minh.push({node->next->val,node->next});
            }
        }
        return ans->next;
    }
};