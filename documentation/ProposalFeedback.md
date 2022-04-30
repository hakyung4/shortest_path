### Grade

Not yet Competent (70%)

Must re-submit!


### Comments

The proposal is well-written, but unfortunately there is one major problem and some minor problems in your algorithms. Also, I do like the clean pdf format, but the proposal is supposed to be in .md file.


**Dataset**

The description for the dataset is pretty thorough, but here are some things you need to consider:

- We do not allow constant weights on the any of the covered algorithms (read the comments for the algorithm part).

- The way you are trying to construct the nodes and edges may not be very ideal for your implementation, since there is no linkage between nodes and correponding egdes. Try to think a better way to construct the graph. For instance, what will be an easier way to check whether two nodes are connected? We will cover some of these formats in the future lectures.


**Algorithm**
- Constant or random egde weights are not allowed for any covered algorithms, since it will essentially be an unweighted graph (all covered algorithms require edge weights). Thus, could you update on how you plan to assign meaningful edge weights on your graph for the Dijkstra's algorthm.

- I noticed that both outputs for BFS and Dijkstra's algorithms are force directed graph drawings. This means that you will need to implement your last algorithm first. I will suggest BFS and Dijkstra's algorithm have different output format instead. For instance, print out the shortest path from a start node to an end node. This will also make your lives easier when writing test cases.

- For the force directed graph drawings, could you specify which kind of software or platform you are planning to use?
