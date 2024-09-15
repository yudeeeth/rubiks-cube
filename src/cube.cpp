#include <chrono>
#include "rotations.hpp"

using namespace std;

int main () {
    cubeImpl cube(initState);
    ifstream f(R"(C:\Users\udithkumarv\projects\cube\src\inp.txt)");
    int n;
    f>>n;
    vector<vector<int>> movesInt(n);
    for(int i=0;i<n;i++){
        string move;
        getline(f,move);
        movesInt[i] = cube.convertToMoves(move);
    }
    for(int i=0;i<n;i++){
        cube.apply(movesInt[i]);
    }
    std::cout<<"printing scrabled cube:\n";
    cube.printCube();
    timer t;
    cube.solve();
    std::cout<<"Time taken to solve: "<<t.GetTimeElapsed()<<"\n";

}
