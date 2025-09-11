### Solution 1:
``` cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        // Size Calculation
        while(temp != nullptr) {
            size++;
            temp = temp->next;
        }
        temp = head;
        int target = size - n;
        // Edge Case
        if(n == size)
            return head->next;
        
        // Computing and Deleting
        for(int i=1;i<target;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
            
        return head;
    }
};
```