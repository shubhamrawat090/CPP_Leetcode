/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function (numCourses, prerequisites) {
    const adj = new Array(numCourses).fill(null).map(() => new Array(0));
    for (let [a, b] of prerequisites) {
        adj[b].push(a);
    }

    const topoSort = getTopoSort(adj, numCourses);
    return topoSort.length !== numCourses ? [] : topoSort
};

var getTopoSort = function (adj, numCourses) {
    const indegrees = new Array(numCourses).fill(0);
    for (let edges of adj) {
        for (let node of edges) {
            indegrees[node]++;
        }
    }

    const queue = [];
    const stack = [];

    for (let i = 0; i < numCourses; i++) {
        if (indegrees[i] == 0) {
            queue.push(i);
        }
    }


    while (queue.length) {
        const node = queue.shift();
        stack.push(node);

        for (let nbr of adj[node]) {
            indegrees[nbr]--;
            if (indegrees[nbr] == 0) {
                queue.push(nbr);
            }
        }
    }

    return stack;
}