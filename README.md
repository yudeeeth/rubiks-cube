# Rubiks Cube respresentation

This project is aimed at using code to solve a rubiks cube using kociemba's algorithm.

## The first Stage includes modelling the cube. 

### Not 3d modelling
Note: Here modelling is NOT 3d modelling, as resperenting the 3d graphically generated could be very simple. One only needs to have 6 sets of objects each having the 21 individual facelets (can also be done if you model the pieces instead of facelets) associated with the corresponding face. And then one only has the rotate all the facelets (or pieces) about a vector coming out of that face. Some smart geometry can also be used to do this much more elegantly without needing to write boilerplate code. I will implement this after finishing kociemba's method.

### Javascript
Which was done without much research as I was really curious to see if I could model the cube in code without external help. I was able to map the state of the cube into a json object containing edges, vertices and cores. On rotating a face, I had to shift the edges and corners corresponding to that particular face, and layer (which I get by using a pre-existing map). 

And there is a very confusing print function, which simply prints the faces in an unfolded cube pattern.

I started in JS as if i started doing this in c++, i would have plucked out all my hair and stressed to the point of no return if i had to write a class for every single thing here.

This implementation is very human friendly, theres a few reasonable mappings, and then we just rotate the edges and corners in the face and their corresponding edges in the layer. 

### C++
C++ implementation is needed if i am to implement kociema for performance purposes. I havent really completely understood kociemba algorithm's implmentation details, but have a general idea of how it works and need to proceed to see how to implement it.

To implement the cube model in c++ i didnt go with the same approach, rather, usign my existing js, made a way to encode the cube state into a string of 48 chars, and after that recorded the change in this array for each of the 18 possible moves, an exported that into an array in c++. in C++ i would only have a make an array of chars, and then apply the transformtions mentioned in the array, which is very very simple.

After supplying the -Ofast compiler flag i was surprised to see the c++ coe run in almost a microsecond. Blazingly fast, truly. Javascript is not far behind either but yea.

## Blockers to Kociemba

Once I implemented this and was happy with the implementation and everything worked. Then came the trouble, the facelet represent is too innefficient to use with kociemba, though urrently I m not focused on efficiency, I dont want my program to run for hours. So i m stuck at this stage, i have outlined what i need to do, but need to get around to doing it.

I will probably first implement this in js and then do it in c++ for the ease of development. I will try my best to not use a new representation but then the implmentation seems ugly, but will have to see.

The best way to keep a calm mind and overcome this blockers is to, first, use existing code to make the base code for the required respresentation system.

You need absolute understanding of this algorithm and these steps
 -[x]  Introduction
 -[x]  The Facelet Level
 -[x]  The Cubie Level
 -[x]  The Coordinate Level
 -[x]  Equivalent Cubes and Symmetry
 -[-]  Cosets
 -[-]  Coordinates and Symmetry
 -[-]  The Two-Phase Algorithm Coordinates
 -[ ]  Move Tables
 -[ ]  Pruning Tables
 -[ ]  Details of the Two-Phase Algorithm
 -[ ]  Optimal Solvers
 -[ ]  Symmetric Patterns

## First Implementation

A naive implementation of the kociemba algorithm can be applied with the basic understanding of kociemba algorithm and a few tricks.
The basic undestanding is that:

Step 1: Reduce the cube to g1
Step 2: Reduce the cube from g1 to solved state using <u,u',r2,f2,l2,b2,d,d'>

The reason is that all cubes in g1 are reduced to dominoes (3x3x2) and dominoes can be solved in with only those movesets.
There are a few tiny optimisations you can do to speed this up.

For the second half, you can store states from the solved state back to about n moves. This is quick. And these saved states can be used to reach the solution quickly, as now you are not looking for solved state but just any of these states.

For the first stage, instead of looking directly in a depth first manner (bfs is insane as will be holding a lotttt of states). you can do iterative deeping which ensures that there is no shorter way to reach g1, and it doesnt cost you much just doublt the time it normally takes.

Without using any special respresentation, and only using the facelet level rep that is implemented so far, it is possible to solve the cube. note that this does not look for symmetries as well.

With -Ofast flag to ensure the the most optimised code, with the above naive implementation of kociemba in c++, we can solve most cubes within a day (untested lol). I ran a single test using this scramble:

f2 l2 u r2 u l2 d2 f2 u' l2 u f' u r d r' f2 d' u2 l'

Which the algorithm solved as

d' r d l' r' b r r d b u l2 d f2 l2 u l2 u b2 u l2 b2 d b2 d' f2

which took a depth of 10 to solve for g1, taking a total of 2711482801 microseconds (45 mins approx) for this.

The second phase is really quick as we have a reverse mapping from the solved state, I wasnt paying attention to wether the code stopped running, and hence can only approcimate that this took about 200 seconds.

Considering that I used -Ofast and got this kind of time. The naive version is really pathetic, but it makes me happy that i was able to implement this so far. I will be able to implment the ideal kociemba soon (fingers crossed).
  
Initially i assued checking for g1 would be very time consuming, but it turned out to be simple and hence I took the time to implement this and it was simple enough to implement in c++, so went ahead with it.

### Disadvantages of naive approach.
Its very obvious the disadvantages of this approach. But just to name a few

- Storing the states as strings Is not veryyy efficient, altho I think it is space efficient as it only uses 48 bytes (1 per char)
- This also take a longggg time to change state?? not sure about this just guessing
- The lack of exploiting symmetries is also a huggge reason for the increased amount of time.
- symmetries can also be applied to covert the mapping of solved to 6 depth all states to given scrambled state to 6 depth all possible states. If this is possible this reduces the time drastically.