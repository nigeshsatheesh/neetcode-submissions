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
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }

        ListNode* i = list1;
        ListNode* j = list2;
        ListNode* head = nullptr;
        ListNode* k = head;
        while(i != nullptr && j != nullptr){
            if(i->val <= j->val && k == nullptr){
                k = i;
                head = i;
                i = i->next;
            }
            else if(i->val >= j->val && k == nullptr){
                k = j;
                head = j;
                j = j->next;
            }
            else if(i->val < j->val){
                k->next = i;
                k = k->next;
                i = i->next;
            }
            else{
                k->next = j;
                k = k->next;
                j = j->next;
            }
        }
        if(i != nullptr){
            k->next = i;
        }
        if(j != nullptr){
            k->next = j;
        }
        return head;
    }
};
