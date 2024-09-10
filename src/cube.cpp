#include <chrono>
#include "rotations.hpp"

using namespace std;

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
    public:
        cubeImpl(string initState) {
            cube_ = initState;
            for(int i=0;i<moves.size();i++){
                movesToInt[moves[i]]=i;
            }
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
        void printCube() {
            for(auto &row : printIndices) {
                for(auto index : row) {
                    if(index!=-1)
                        cout<<cube_[index]<<" ";
                    else
                        cout<<"  ";
                }
                cout<<"\n";
            }
        }

        bool isSolved() {
            return cube_==initState;
        }
};

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
    timer t;
    for(int i=0;i<n;i++){
        cube.apply(movesInt[i]);
    }
    std::cout<<t.GetTimeElapsed()<<"\n";
    cube.printCube();
}
