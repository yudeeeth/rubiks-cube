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

