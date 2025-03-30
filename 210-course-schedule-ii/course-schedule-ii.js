/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function(numCourses, prerequisites) {
    // RETURN THE TOPOLOGICAL SORT

    // 1. Create Adj list
    // 2. Get indegrees
    // 3. Push all 0 indeg => to queue
    // 4. Traverse BFS in queue. Keep another stack
        // 4.1 When removing from queue, add it to stack
        // 4.2 Traverse all nbrs and subtract indeg by 1 for each nbr
        // 4.3 If any nbr's indeg = 0, push that to queue
    // 5. If the stack(topological sort's) LENGTH !== numCourses => [] : stack;
     
     const adjList = new Array(numCourses).fill(null).map(() => []);
     for(let i=0; i<prerequisites.length; i++) {
        const [u, v] = prerequisites[i];
        adjList[v].push(u);
     }

     const indegrees = new Array(numCourses).fill(0);
     for(let i=0; i<numCourses; i++) {
        for(let nbr of adjList[i]) {
            indegrees[nbr]++;
        }
     }

    const queue = [], stack = [];
     for(let i=0; i<numCourses; i++) {
        if(indegrees[i] == 0) {
            queue.push(i);
        }
     }

     while(queue.length) {
        const top = queue.shift();
        stack.push(top);

        for(let nbr of adjList[top]) {
            indegrees[nbr]--;
            if(indegrees[nbr] == 0) {
                queue.push(nbr);
            }
        }
     }

     return stack.length !== numCourses ? [] : stack;
};