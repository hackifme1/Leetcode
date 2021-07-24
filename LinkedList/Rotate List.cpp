// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

*/


Cpp code :

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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL)
            return head;
        
        ListNode* temp = head;
        int posnh = 0, cnt = 0;
        
        while(temp->next)
        {
            cnt++;
            temp = temp->next;
        }
       
        cnt++;
        
        int r = k % cnt;
        
        if(r == 0)
            return head;
        
        temp->next = head;
        
        for(int i=0;i<(cnt-r);i++)
        {
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = NULL;

        return head;        
    }
};
