# Electrical and Computer Engineers

# Final Project - Shortest Path in California Road Network

### Group members
- hakyung4
- sangwoo2
- analla6
- anahas2

### How it works
Our program uses data from [California Road Network and Points of Interest](https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm) to find the shortest path of getting to one place from another. We use both BFS and Dijkstra's algorithm to find the shortest path, compare the run time, and decide which one is more efficient.

### How to use the program

To use the program, you can copy and paste this to the terminal:

```
git clone https://github-dev.cs.illinois.edu/cs225-sp22/hakyung4-sangwoo2-analla6-anahas2.git
```

### File Structure

Our graph class is located in `Graph.h`, and all the implementation of functions are in `Graph.cpp.`. `main.cpp` is where we execute our code. We first ask you to specify start node (starting point) and end node (desitation), first time with BFS and second time with Dijkstra. `test1.cpp` includes essential test cases that verify the implementation of algorithms. 

### Running instructions

To compile: 
```
make
```

To run the executable: 
```
./final
```

To compile test cases:
```
make

clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o cs225/catch/catchmain.o

clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c test1.cpp -o .objs/test1.o

clang++ .objs/Graph.o .objs/test1.o cs225/catch/catchmain.o  -std=c++14 -stdlib=libc++ -lc++abi -o test

./test
```

When compiling and running the execultable `main` file, it will ask you to put desired start point and the end point for BFS and Dijkstra's algorithm, and it will print out the shortest path/distance. 

### Example Result
<img width="1189" alt="Screen Shot 2022-05-06 at 18 32 28" src="https://media.github-dev.cs.illinois.edu/user/11450/files/0f061807-4250-4485-b034-d15e2cbc1c8b">
