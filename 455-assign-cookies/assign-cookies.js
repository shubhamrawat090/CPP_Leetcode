/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
    /* 
        APPROACH
        1. Sort both the g (greed factor) and s (cookie sizes) arrays in ascending order.

        2. Use two pointers, one for children (g) and one for cookies (s).

        3. Try to satisfy each child with the smallest available cookie that is large enough.

        4. If a cookie can satisfy a child (s[j] >= g[i]), move both pointers forward.

        5. Otherwise, just move the cookie pointer forward to find a bigger cookie.

        6.Count how many children are satisfied.    
    */
var findContentChildren = function (g, s) {
    // return findContentChildren_RECURSIVE(g, s);

    // Sort greed factors and cookie sizes in ascending order
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);

    let i = 0, j = 0; // Pointers for children and cookies
    let count = 0;

    while (i < g.length && j < s.length) {
        if (s[j] >= g[i]) {
            count++; // Child is satisfied
            i++; // Move to next child
        }
        j++; // Move to next cookie (used or too small)
    }

    return count;
};

var findContentChildren_RECURSIVE = function(g, s) {
    g.sort((a, b) => a - b); // Sort greed values
    s.sort((a, b) => a - b); // Sort cookie sizes

    function maxChildren(i, j) {
        if (i >= g.length || j >= s.length) {
            return 0;
        }
        
        if (g[i] <= s[j]) {
            return Math.max(1 + maxChildren(i + 1, j + 1), maxChildren(i, j + 1));
        } else {
            return maxChildren(i, j + 1);
        }
    }

    return maxChildren(0, 0);
};