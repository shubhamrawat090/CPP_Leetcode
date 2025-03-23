/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function (numCourses, prerequisites) {
    const adjList = Array(numCourses).fill(null).map(() => []);
    for (let [a, b] of prerequisites) {
        adjList[b].push(a);
    }

    const indegree = Array(numCourses).fill(0);
    for (node = 0; node < numCourses; node++) {
        for (let nbr of adjList[node]) {
            indegree[nbr]++;
        }
    }

    const queue = [];
    const stack = [];

    for (let node = 0; node < numCourses; node++) {
        if (indegree[node] == 0) {
            queue.push(node);
        }
    }

    while (queue.length) {
        const top = queue.shift();
        stack.push(top);

        for (let nbr of adjList[top]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                queue.push(nbr);
            }
        }
    }

    return stack.length !== numCourses ? [] : stack;
};