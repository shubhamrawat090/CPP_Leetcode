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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Path1:   ------               Start Point A(Traversed by Ptr1)
        // Path2:         ------------
        // Path3: --------               Start Point B(Traversed by Ptr2)

        // Path1 + Path2 + Path3 = TOTAL_PATH(same DISTANCE for any travelling, irrespective of starting position)
        // Therefore, if a person travels TOTAL_PATH there will meet at the same point(INTERSECTION). 
        // IRRESPECTIVE OF THEM STARTING FROM POINT A or B.

        // Intiuition
        // 1. Put 1 pointer each at both of the starting points headA and headB
        // 2. Move them both by 1 step next
        // 3.1 If ptr1 reaches END and becomes NULL(Path1 + Path2), then ptr1 = headB OR IT WILL TRAVEL Path3 
        // 3.2 If ptr2 reaches END and becomes NULL(Path3 + Path2), then ptr2 = headA OR IT WILL TRAVEL path1

        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1 != ptr2) {
            ptr1 = ptr1 == NULL ? headB : ptr1->next;
            ptr2 = ptr2 == NULL ? headA : ptr2->next;
        } 
        return ptr1; // ptr2, both point to intersection
    }
};