/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    if(list1 == null) {
        return list2;
    }
    if(list2 == null) {
        return list1;
    }
    let head = new ListNode(0);
    let curr = head;
    while(list1 != null && list2 != null) {
        if(list1.val < list2.val) {
            curr.next = list1;
            list1 = list1.next;
            curr = curr.next;
        } else {
            curr.next = list2;
            list2 = list2.next;
            curr = curr.next;
        }
    }
    if(list1 != null) {
        curr.next = list1;
    } else if(list2 != null) {
        curr.next = list2;
    }
    return head.next;
};