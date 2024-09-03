let log = (anything) =>{
    process.stdout.write(anything);
};

class cube {
    colors = ["w","y","o","r","b","g"];
    cubeStructure = {
        faces: {
            u  : ['a','b','c','d'],
            l  : ['e','f','g','h'],
            f  : ['i','j','k','l'],
            r  : ['m','n','o','p'],
            b  : ['q','r','s','t'],
            d  : ['u','v','w','x'],
        },
        colors: {
            u: "w",
            l: "o",
            f: "g",
            r: "r",
            b: "b",
            d: "y",
        },
        edges: [
            ['a','q'],
            ['b','m'],
            ['c','i'],
            ['d','e'],
            ['l','f'],
            ['j','p'],
            ['h','r'],
            ['n','t'],
            ['u','k'],
            ['v','o'],
            ['w','s'],
            ['x','g'],
        ],
        vertices: [
            ['a','e','r'],
            ['b','q','n'],
            ['c','m','j'],
            ['d','i','f'],
            ['u','g','l'],
            ['v','k','p'],
            ['w','o','t'],
            ['x','s','h'],
        ],
        prep: function(){
            // create a map for edges and corners
            let edgeset = {};
            this.edges.map(ls => {
                edgeset[ls[0]] = ls[1];
                edgeset[ls[1]] = ls[0];
            })
            this.edges = edgeset;
            let vertexset = {};
            this.vertices.map(ls => {
                vertexset[ls[0]] = [ls[1],ls[2]];
                vertexset[ls[1]] = [ls[2],ls[0]];
                vertexset[ls[2]] = [ls[0],ls[1]];
            })
            this.vertices = vertexset;
        },
    };
    cube = {};
    constructor() {
        this.cubeStructure.prep();
        this.initcube();
    }
    initcube() {
        this.cube.edges = {};
        this.cube.vertices = {};
        this.cube.cores = {};
        for(let face in this.cubeStructure.faces) {
            let letterlist = this.cubeStructure.faces[face];
            letterlist.forEach(letter => {
                this.cube.edges[letter] = this.cubeStructure.colors[face];
                this.cube.vertices[letter] = this.cubeStructure.colors[face];
            });
        }
        for(let face in this.cubeStructure.colors) {
            this.cube.cores[face] = this.cubeStructure.colors[face];
        }
    }
    applyMoves(sequence) {
        sequence.split(" ").forEach(move => this.rotate(move));
    }
    analyse(sequence) {
        sequence.split(" ").forEach(move => this.rotate(move));
    }
    rotate(move) {
        if(!Object.keys(this.cubeStructure.faces).includes(move[0])) {
            console.log(move);
            throw "invalid move";
        }
        if(move.length == 2) {
            if (move[1]=="'"){
                for(let i=0;i<3;i++) {
                    this.rotateInternal(move[0]);
                }
            }
            else {
                for(let i=0;i<2;i++) {
                    this.rotateInternal(move[0]);
                }
            }
        }
        else {
            this.rotateInternal(move[0]);
        }
    }
    rotateInternal(move) {
        let faceSeq = this.cubeStructure.faces[move];
        this.rotateEdgesFromSeq(faceSeq);
        this.rotateEdgesFromSeq(faceSeq.map(e=>this.cubeStructure.edges[e]));

        this.rotateVerticesFromSeq(faceSeq);
        this.rotateVerticesFromSeq(faceSeq.map(e=>this.cubeStructure.vertices[e][0]));
        this.rotateVerticesFromSeq(faceSeq.map(e=>this.cubeStructure.vertices[e][1]));
    }
    rotateEdgesFromSeq(seq) {
        // seq has four pieces, rotate those 4 pieces
        let temp = this.cube.edges[seq[3]];
        this.cube.edges[seq[3]] = this.cube.edges[seq[2]];
        this.cube.edges[seq[2]] = this.cube.edges[seq[1]];
        this.cube.edges[seq[1]] = this.cube.edges[seq[0]];
        this.cube.edges[seq[0]] = temp;
    }
    rotateVerticesFromSeq(seq) {
        // seq has four pieces, rotate those 4 pieces
        let temp = this.cube.vertices[seq[3]];
        this.cube.vertices[seq[3]] = this.cube.vertices[seq[2]];
        this.cube.vertices[seq[2]] = this.cube.vertices[seq[1]];
        this.cube.vertices[seq[1]] = this.cube.vertices[seq[0]];
        this.cube.vertices[seq[0]] = temp;
    }
    printCube() {
        let row1 = [
            ['c',0],
            ['e',0],
            ['c',1],];
        let row2 = [
            ['e',3],
            ['f',0],
            ['e',1],];
        let row3 = [
            ['c',3],
            ['e',2],
            ['c',2],
        ];
        let rows = [row1,row2,row3];
        let faces = [
            ['','u'],
            ['l','f','r','b'],
            ['','d'],
        ];
        faces.forEach(faceRow=>{
            rows.forEach(row => {
                faceRow.forEach(face => row.forEach(rowElem => {
                    if (face.length ==0) log("  ");
                    else {
                        let arrToPrint = this.cubeStructure.faces[face];
                        // console.log(face,arrToPrint,rowElem[0]=='c');
                        if(rowElem[0] == 'c') {
                            log(this.cube.vertices[arrToPrint[rowElem[1]]]);
                        }
                        if(rowElem[0] == 'e') {
                            log(this.cube.edges[arrToPrint[rowElem[1]]]);
                        }
                        if(rowElem[0] == 'f') {
                            log(this.cube.cores[face]);
                        }
                        log(" ");
                    }
                }));
                log("\n");
            })
        })
    }
};

let c = new cube();
c.applyMoves("f2 l2 u r2 u l2 d2 f2 u' l2 u f' u r d r' f2 d' u2 l'");
c.applyMoves("u' r' l' u2 b2 l' u2 r' b' u' l b2 d2 b2 u l2 u r2 u'");
c.printCube();



