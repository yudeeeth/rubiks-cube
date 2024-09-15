#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> rotations = {{
                                             {0, 1, 2, 3},

                                             {16, 12, 8, 4},

                                             {24, 25, 26, 27},

                                             {28, 40, 36, 32},

                                             {41, 37, 33, 29},
                                         },
                                         {
                                             {3, 2, 1, 0},
                                             {4, 8, 12, 16},
                                             {27, 26, 25, 24},
                                             {32, 36, 40, 28},
                                             {29, 33, 37, 41},
                                         },
                                         {
                                             {0, 1, 2, 3},

                                             {16, 12, 8, 4},

                                             {24, 25, 26, 27},

                                             {28, 40, 36, 32},

                                             {41, 37, 33, 29},

                                             {0, 1, 2, 3},

                                             {16, 12, 8, 4},

                                             {24, 25, 26, 27},

                                             {28, 40, 36, 32},

                                             {41, 37, 33, 29},

                                         },
                                         {
                                             {4, 5, 6, 7},

                                             {3, 11, 23, 17},

                                             {28, 29, 30, 31},

                                             {41, 27, 35, 47},

                                             {24, 32, 44, 42},

                                         },
                                         {
                                             {7, 6, 5, 4},

                                             {17, 23, 11, 3},

                                             {31, 30, 29, 28},

                                             {47, 35, 27, 41},

                                             {42, 44, 32, 24},

                                         },
                                         {
                                             {4, 5, 6, 7},

                                             {3, 11, 23, 17},

                                             {28, 29, 30, 31},

                                             {41, 27, 35, 47},

                                             {24, 32, 44, 42},

                                             {4, 5, 6, 7},

                                             {3, 11, 23, 17},

                                             {28, 29, 30, 31},

                                             {41, 27, 35, 47},

                                             {24, 32, 44, 42},

                                         },
                                         {
                                             {8, 9, 10, 11},

                                             {2, 15, 20, 5},

                                             {32, 33, 34, 35},

                                             {29, 26, 39, 44},

                                             {27, 36, 45, 30},

                                         },
                                         {
                                             {11, 10, 9, 8},

                                             {5, 20, 15, 2},

                                             {35, 34, 33, 32},

                                             {44, 39, 26, 29},

                                             {30, 45, 36, 27},

                                         },
                                         {
                                             {8, 9, 10, 11},

                                             {2, 15, 20, 5},

                                             {32, 33, 34, 35},

                                             {29, 26, 39, 44},

                                             {27, 36, 45, 30},

                                             {8, 9, 10, 11},

                                             {2, 15, 20, 5},

                                             {32, 33, 34, 35},

                                             {29, 26, 39, 44},

                                             {27, 36, 45, 30},

                                         },
                                         {
                                             {12, 13, 14, 15},

                                             {1, 19, 21, 9},

                                             {36, 37, 38, 39},

                                             {33, 25, 43, 45},

                                             {26, 40, 46, 34},

                                         },
                                         {
                                             {15, 14, 13, 12},

                                             {9, 21, 19, 1},

                                             {39, 38, 37, 36},

                                             {45, 43, 25, 33},

                                             {34, 46, 40, 26},

                                         },
                                         {
                                             {12, 13, 14, 15},

                                             {1, 19, 21, 9},

                                             {36, 37, 38, 39},

                                             {33, 25, 43, 45},

                                             {26, 40, 46, 34},

                                             {12, 13, 14, 15},

                                             {1, 19, 21, 9},

                                             {36, 37, 38, 39},

                                             {33, 25, 43, 45},

                                             {26, 40, 46, 34},

                                         },
                                         {
                                             {16, 17, 18, 19},

                                             {0, 7, 22, 13},

                                             {40, 41, 42, 43},

                                             {37, 24, 31, 46},

                                             {25, 28, 47, 38},

                                         },
                                         {
                                             {19, 18, 17, 16},

                                             {13, 22, 7, 0},

                                             {43, 42, 41, 40},

                                             {46, 31, 24, 37},

                                             {38, 47, 28, 25},

                                         },
                                         {
                                             {16, 17, 18, 19},

                                             {0, 7, 22, 13},

                                             {40, 41, 42, 43},

                                             {37, 24, 31, 46},

                                             {25, 28, 47, 38},

                                             {16, 17, 18, 19},

                                             {0, 7, 22, 13},

                                             {40, 41, 42, 43},

                                             {37, 24, 31, 46},

                                             {25, 28, 47, 38},

                                         },
                                         {
                                             {20, 21, 22, 23},

                                             {10, 14, 18, 6},

                                             {44, 45, 46, 47},

                                             {30, 34, 38, 42},

                                             {35, 39, 43, 31},

                                         },
                                         {
                                             {23, 22, 21, 20},

                                             {6, 18, 14, 10},

                                             {47, 46, 45, 44},

                                             {42, 38, 34, 30},

                                             {31, 43, 39, 35},

                                         },
                                         {
                                             {20, 21, 22, 23},

                                             {10, 14, 18, 6},

                                             {44, 45, 46, 47},

                                             {30, 34, 38, 42},

                                             {35, 39, 43, 31},

                                             {20, 21, 22, 23},

                                             {10, 14, 18, 6},

                                             {44, 45, 46, 47},

                                             {30, 34, 38, 42},

                                             {35, 39, 43, 31},
                                         }};

string initState = {
    'w', 'w', 'w', 'w', 'o', 'o', 'o', 'o',
    'g', 'g', 'g', 'g', 'r', 'r', 'r', 'r',
    'b', 'b', 'b', 'b', 'y', 'y', 'y', 'y',
    'w', 'w', 'w', 'w', 'o', 'o', 'o', 'o',
    'g', 'g', 'g', 'g', 'r', 'r', 'r', 'r',
    'b', 'b', 'b', 'b', 'y', 'y', 'y', 'y',
    'w', 'o', 'g', 'r', 'b', 'y',
};

vector<string> moves = {
    "u", "u'", "u2", "l", "l'", "l2", "f", "f'", "f2",
    "r", "r'", "r2", "b", "b'", "b2", "d", "d'", "d2"
};

map<string,int> movesToInt;

vector<vector<int>> printIndices = {{
                                       -1,
                                       -1,
                                       -1,
                                       24,
                                       0,
                                       25,
                                   },
                                   {
                                       -1,
                                       -1,
                                       -1,
                                       3,
                                       48,
                                       1,
                                   },
                                   {
                                       -1,
                                       -1,
                                       -1,
                                       27,
                                       2,
                                       26,
                                   },
                                   {
                                       28,
                                       4,
                                       29,
                                       32,
                                       8,
                                       33,
                                       36,
                                       12,
                                       37,
                                       40,
                                       16,
                                       41,
                                   },
                                   {
                                       7,
                                       49,
                                       5,
                                       11,
                                       50,
                                       9,
                                       15,
                                       51,
                                       13,
                                       19,
                                       52,
                                       17,
                                   },
                                   {
                                       31,
                                       6,
                                       30,
                                       35,
                                       10,
                                       34,
                                       39,
                                       14,
                                       38,
                                       43,
                                       18,
                                       42,
                                   },
                                   {
                                       -1,
                                       -1,
                                       -1,
                                       44,
                                       20,
                                       45,
                                   },
                                   {
                                       -1,
                                       -1,
                                       -1,
                                       23,
                                       53,
                                       21,
                                   },
                                   {
                                       -1,
                                       -1,
                                       -1,
                                       47,
                                       22,
                                       46,
                                   }};

vector<int> udSliceRedOrange = {
    5,7,13,15
};

vector<int> udSliceGreenBlue = {
    9,11,17,19
};

vector<int> nonUdWhiteYellow = {
    0,1,2,3,24,25,26,27,20,21,22,23,44,45,46,47
};

vector<int> inverseMoves = {
    1,0,2,4,3,5,7,6,8,10,9,11,13,12,14,16,15,17
};


class timer {
    chrono::_V2::system_clock::time_point start;
    public:
    timer(){
        start = chrono::high_resolution_clock::now();
    }
    uint64_t GetTimeElapsed() {
        auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now()-start);
        return static_cast<uint64_t>(duration.count());
    }
};

class cubeImpl {
    private:
        string cube_;
        map<int,string> lettermap;
        map<string,vector<int>> possibleSolutions;
    public:
        cubeImpl(string initState) {
            std::cout<<"cubeinit";
            cube_ = initState;
            for(int i=0;i<moves.size();i++){
                movesToInt[moves[i]]=i;
                lettermap[i] = moves[i];
            }
            populatePossibleSol();
            std::cout<<"cube init: ";
            printCube();
        }

        void populatePossibleSol() {
            std::cout<<"popSol";
            vector<int> sols;
            int depth = 6;
            vector<int> moves = {0,1,5,8,11,14,15,16};
            possibleSolutions[cube_] = {};
            for(auto i:moves){
                sols.push_back(inverseMoves[i]);
                popSol(i,depth,sols,moves);
                sols.pop_back();
            }
        }

        void popSol(int move,int depth,vector<int>& sols,vector<int>& moves) {
            if(depth<0) return;
            rotate(move);
            possibleSolutions[cube_]=vector<int>(sols);
            for(int i:moves){
                if(i!=inverseMoves[move]) {
                    if(i==move && sols.size()>=2 && sols[sols.size()-2]==i) continue;
                    sols.push_back(inverseMoves[i]);
                    popSol(i,depth-1,sols,moves);
                    sols.pop_back();
                }
            }
            rotate(inverseMoves[move]);
        }

        void rotateInternal(vector<int>& items){
            auto temp = cube_[items[3]];
            cube_[items[3]] = cube_[items[2]];
            cube_[items[2]] = cube_[items[1]];
            cube_[items[1]] = cube_[items[0]];
            cube_[items[0]] = temp;
        }

        void rotate(int move) {
            for(auto &seq : rotations[move]){
                rotateInternal(seq);
            }
        }
        void rotate(string &move) {
            rotate(movesToInt[move]);
        }

        vector<int> convertToMoves(string &seq) {
            vector<int> moves;
            for(int i=0;i<seq.size();i++) {
                if(seq[i]==' ') continue;
                else if (movesToInt.count(seq.substr(i,1))) {
                    if(i+1<seq.size() && seq[i+1]!=' ') {
                        moves.push_back(movesToInt[seq.substr(i,2)]);
                        i++;
                        continue;
                    }
                    else {
                        moves.push_back(movesToInt[seq.substr(i,1)]);
                    }
                }
            }
            return moves;
        }

        void apply(vector<int>& moves){
            for(auto move:moves){
                rotate(move);
            }
        }

        void apply(string &seq){
            auto vec = convertToMoves(seq);
            apply(vec);
        }

        void apply(vector<string> &moves){
            for(auto move:moves){
                rotate(move);
            }
        }
        void printCube(string cube = "") {
            if(cube.size()==0) cube = cube_;
            for(auto &row : printIndices) {
                for(auto index : row) {
                    if(index!=-1)
                        cout<<cube[index]<<" ";
                    else
                        cout<<"  ";
                }
                cout<<"\n";
            }
        }

        bool isSolved() {
            return cube_==initState;
        }

        bool isSolved(string cube) {
            return cube==initState;
        }

        bool isPossibleSol() {
            return possibleSolutions.count(cube_);
        }

        bool isG1() {
            for(int i:udSliceGreenBlue) {
                if(cube_[i]!='b' && cube_[i]!='g') return false;
            }
            for(int i:udSliceRedOrange) {
                if(cube_[i]!='o' && cube_[i]!='r') return false;
            }
            for(int i:nonUdWhiteYellow) {
                if(cube_[i]!='w' && cube_[i]!='y') return false;
            }
            return true;
        }

        void solve() {
            std::cout<<"solving\n";
            vector<int> stage1moves = {0,1,3,4,6,7,9,10,12,13,15,16};
            vector<int> stage2moves = {0,1,5,8,11,14,15,16};
            vector<int> currentSolution  = {};
            currentSolution.reserve(20);
            vector<int> solution = {};
            vector<string> g1cubes;
            timer t;
            int stage = 1;
            int depth = 0;
            int maxDepth = 10;
            // Iterative Deepening
            while(depth<=maxDepth){
                std::cout<<"Depth: "<<depth<<"\n";
                for(auto i: stage1moves) {
                    currentSolution.push_back(i);
                    solveInternal(i,stage1moves,depth,stage,g1cubes,solution,currentSolution);
                    currentSolution.pop_back();
                }
                if(g1cubes.size()>0) break;
                depth++;
            }
            std::cout<<"Printing g1 cubes:\n";
            std::cout<<"Time Elapsed for generating "<<g1cubes.size()<<" G1 cubes: "<<t.GetTimeElapsed()<<"\n";
            std::cout<<"printing g1:\n";
            for(auto cube:g1cubes) {
                printCube(cube);
                std::cout<<"\n";
            }
            // change cube state
            if(g1cubes.size()<=0) {
                std::cout<<"No solution bro :(\n";
                return;
            }
            cout<<"\n";
            for(auto i: solution){
                std::cout<<lettermap[i];
            }
            std::cout<<"\nstarting phase 2\n";
            stage = 2;
            cube_ = g1cubes[0];
            depth = 8;
            currentSolution.clear();
            for(auto i:stage2moves) {
                currentSolution.push_back(i);
                solveInternal(i,stage2moves,depth,stage,g1cubes,solution,currentSolution);
                currentSolution.pop_back();
            }
            std::cout<<"printing cube state:\n";
            printCube();
            std::cout<<"printing solution:\n";
            for(auto i:solution) {
                std::cout<<lettermap[i]<<" ";
            }
            char d;
            std::cout<<"\n Did this work??? type y or n\n";
            std::cin>>d;
            if(d=='y')
                std::cout<<"\nLets goooooooooo you did it, you are the goattttt. Take a pat you divine genius.\n";
            else
                std::cout<<"\nIts fine, you can fix this, lets do thisssss!!!!!!!!\n";
        }

        // failure on actual solves coz using dfs
        void solveInternal(int move, vector<int>& moves,int depth, int stage, vector<string> &g1cubes, vector<int> &solution, vector<int>&currentSolution) {
            if(depth<0) return;
            if(stage==1 && g1cubes.size()>0) return;
            if(stage==2 && g1cubes.size()==0) return;
            rotate(move);
            if(stage == 1 && isG1()){
                std::cout<<"found 1 g\n";
                g1cubes.push_back(string(cube_));
                for(auto i:currentSolution){
                    solution.push_back(i);
                }
                currentSolution.pop_back();
                rotate(inverseMoves[move]);
                return;
            }
            if(stage==2 && isPossibleSol()){
                std::cout<<"Solved baby!!!!!!\n";
                for(auto i:currentSolution){
                    solution.push_back(i);
                }
                auto additional = possibleSolutions[cube_];
                printCube();
                for(auto i: additional){
                    std::cout<<lettermap[i];
                }
                cout<<"\n";
                for(int i=additional.size()-1;i>=0;i--){
                    solution.push_back(additional[i]);
                }
                g1cubes.clear();
                return;
            }
            for(auto i: moves) {
                if(i!=inverseMoves[move])
                {
                    if(i==move && currentSolution.size()>=2 && currentSolution[currentSolution.size()-2]==i) continue;
                    currentSolution.push_back(i);
                    solveInternal(i,moves,depth-1,stage,g1cubes,solution,currentSolution);
                    currentSolution.pop_back();
                }
            }
            rotate(inverseMoves[move]);
        }
};