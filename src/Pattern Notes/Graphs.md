1. BFS and DFS Traversal

https://takeuforward.org/plus/dsa/problems/traversal-techniques?subject=dsa&approach=dfs

Read Notes and code it up again.

2. BFS on Grid

Read Notes

3. Rotten Oranges - BFS (whenever we want to access the same level guys across all the starting points at the same time, we use BFS)

https://leetcode.com/problems/rotting-oranges/description/

DESC - Use BFS for moving to all the neighbouring nodes which are at the same level from this node at one time. BrainFuck Question - do it again. Also remember `minTime = time + 1` not `minTime = time` because we want the time when the last child gets rotten not when the last parent gets rotten.

Multiple starting points pushed into the queue at once. This single-source vs multi-source distinction is a classic OA decision point. Multi-source in Rotten Oranges and single-source in number of islands.
