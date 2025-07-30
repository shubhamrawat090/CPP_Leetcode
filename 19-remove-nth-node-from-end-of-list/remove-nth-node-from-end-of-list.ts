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

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    if(head == null) return head;
    if(head.next == null) return null;
    let first = head, second = head;
    console.log("n: ", n)
    console.log("MOVING SECOND ONLY")
    for(let i=0; i<n; i++) {
        console.log("Second: ", second.val);
        if(second == null) {
            // n nodes aren't present
            return head;
        }
        second = second.next;
    }

    // If `second` is null, we need to remove the head
    if (!second) return head.next;

    console.log("\n\nMOVING BOTH")
    while(second.next != null) {
        console.log("First: ", first.val);
        console.log("Second: ", second.val);
        first = first!.next;
        second = second.next;
    }

    if(first) {
        let skippedNode = first.next; // Can delete this ISOLATED node after in languages like C++

        if(skippedNode) {
            first.next = skippedNode.next;
        }
    }


    return head;
};