let log = (anything) => {
  process.stdout.write("" + anything);
  // console.log(anything);
};

class timer {
  timer_;
  constructor() {
    this.timer = process.hrtime.bigint();
  }
  getElapsedTime() {
    return (process.hrtime.bigint() - this.timer).toString();
  }
}

class cube {
  colors = ["w", "y", "o", "r", "b", "g"];
  cubeStructure = {
    faces: {
      u: ["a", "b", "c", "d"],
      l: ["e", "f", "g", "h"],
      f: ["i", "j", "k", "l"],
      r: ["m", "n", "o", "p"],
      b: ["q", "r", "s", "t"],
      d: ["u", "v", "w", "x"],
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
      ["a", "q"],
      ["b", "m"],
      ["c", "i"],
      ["d", "e"],
      ["l", "f"],
      ["j", "p"],
      ["h", "r"],
      ["n", "t"],
      ["u", "k"],
      ["v", "o"],
      ["w", "s"],
      ["x", "g"],
    ],
    vertices: [
      ["a", "e", "r"],
      ["b", "q", "n"],
      ["c", "m", "j"],
      ["d", "i", "f"],
      ["u", "g", "l"],
      ["v", "k", "p"],
      ["w", "o", "t"],
      ["x", "s", "h"],
    ],
    prep: function () {
      // create a map for edges and corners
      let edgeset = {};
      this.edges.map((ls) => {
        edgeset[ls[0]] = ls[1];
        edgeset[ls[1]] = ls[0];
      });
      this.edges = edgeset;
      let vertexset = {};
      this.vertices.map((ls) => {
        vertexset[ls[0]] = [ls[1], ls[2]];
        vertexset[ls[1]] = [ls[2], ls[0]];
        vertexset[ls[2]] = [ls[0], ls[1]];
      });
      this.vertices = vertexset;
    },
  };
  cube = {};
  bufferCube = [];
  encodeMap = {};
  constructor() {
    this.cubeStructure.prep();
    this.initcube();
    this.encodeMapping();
  }
  initcube() {
    this.cube.edges = {};
    this.cube.vertices = {};
    this.cube.cores = {};
    for (let face in this.cubeStructure.faces) {
      let letterlist = this.cubeStructure.faces[face];
      letterlist.forEach((letter) => {
        this.cube.edges[letter] = this.cubeStructure.colors[face];
        this.cube.vertices[letter] = this.cubeStructure.colors[face];
      });
    }
    for (let face in this.cubeStructure.colors) {
      this.cube.cores[face] = this.cubeStructure.colors[face];
    }
  }
  encodeMapping() {
    let cubeArray = [];
    this.encodeMap.edges = {};
    this.encodeMap.vertices = {};
    this.encodeMap.cores = {};
    for(let i=0;i<24;i++){
        cubeArray.push(this.cube.edges[String.fromCharCode(97+i)]);
        this.encodeMap.edges[String.fromCharCode(97+i)] = i;
    }
    for(let i=0;i<24;i++){
        cubeArray.push(this.cube.vertices[String.fromCharCode(97+i)]);
        this.encodeMap.vertices[String.fromCharCode(97+i)] = 24+i;
    }
    let i=48;
    for(let key in this.cubeStructure.faces) {
        cubeArray.push(this.cube.cores[key]);
        this.encodeMap.cores[key]=i;
        i++;
    }
    // * enable this comment to print c++ related info
    // console.log(cubeArray);
  }
  applyMoves(sequence) {
    sequence.split(" ").forEach((move) => this.rotate(move));
  }
  analyse(sequence) {
    sequence.split(" ").forEach((move) => this.rotate(move));
  }
  rotate(move) {
    // * enable this comment to print c++ related info
    // console.log("},\n{");
    if (!Object.keys(this.cubeStructure.faces).includes(move[0])) {
      console.log(move);
      throw "invalid move";
    }
    if (move.length == 2) {
      if (move[1] == "'") {
        this.rotateInternal(move[0], true);
      } else {
        for (let i = 0; i < 2; i++) {
          this.rotateInternal(move[0]);
        }
      }
    } else {
      this.rotateInternal(move[0]);
    }
  }
  rotateInternal(move, rev) {
    let faceSeq = this.cubeStructure.faces[move].map((e) => e);
    if (rev) faceSeq = faceSeq.reverse(); 
    this.rotateEdgesFromSeq(faceSeq);
    this.rotateEdgesFromSeq(faceSeq.map((e) => this.cubeStructure.edges[e]));

    this.rotateVerticesFromSeq(faceSeq);
    this.rotateVerticesFromSeq(
      faceSeq.map((e) => this.cubeStructure.vertices[e][0])
    );
    this.rotateVerticesFromSeq(
      faceSeq.map((e) => this.cubeStructure.vertices[e][1])
    );
  }
  rotateEdgesFromSeq(seq) {
    // * enable this comment to print c++ related info
    // console.log("{",seq.map(e=>this.encodeMap.edges[e]).join(","), "},\n");
    let temp = this.cube.edges[seq[3]];
    this.cube.edges[seq[3]] = this.cube.edges[seq[2]];
    this.cube.edges[seq[2]] = this.cube.edges[seq[1]];
    this.cube.edges[seq[1]] = this.cube.edges[seq[0]];
    this.cube.edges[seq[0]] = temp;
  }
  rotateVerticesFromSeq(seq) {
    // * enable this comment to print c++ related info
    // console.log("{",seq.map(e=>this.encodeMap.vertices[e]).join(","), "},\n");
    let temp = this.cube.vertices[seq[3]];
    this.cube.vertices[seq[3]] = this.cube.vertices[seq[2]];
    this.cube.vertices[seq[2]] = this.cube.vertices[seq[1]];
    this.cube.vertices[seq[1]] = this.cube.vertices[seq[0]];
    this.cube.vertices[seq[0]] = temp;
  }
  printCube() {
    let rows = [
      [
        ["c", 0],
        ["e", 0],
        ["c", 1],
      ],
      [
        ["e", 3],
        ["f", 0],
        ["e", 1],
      ],
      [
        ["c", 3],
        ["e", 2],
        ["c", 2],
      ],
    ];
    let faces = [
      ["", "u"],
      ["l", "f", "r", "b"],
      ["", "d"],
    ];
    faces.forEach((faceRow) => {
      rows.forEach((row) => {
        faceRow.forEach((face) =>
          row.forEach((rowElem) => {
            if (face.length == 0) {
              log("  ");
              // * enable this comment to print c++ related info
              // log("-1,");
            }
            else {
              let arrToPrint = this.cubeStructure.faces[face];
              // console.log(arrToPrint,this.encodeMap);
              if (rowElem[0] == "c") {
                log(this.cube.vertices[arrToPrint[rowElem[1]]]);
                // * enable this comment to print c++ related info
                // log(this.encodeMap.vertices[arrToPrint[rowElem[1]]]);
              }
              if (rowElem[0] == "e") {
                log(this.cube.edges[arrToPrint[rowElem[1]]]);
                // * enable this comment to print c++ related info
                // log(this.encodeMap.edges[arrToPrint[rowElem[1]]]);
              }
              if (rowElem[0] == "f") {
                log(this.cube.cores[face]);
                // * enable this comment to print c++ related info
                // log(this.encodeMap.cores[face]);
              }
              log(" ");
              // * enable this comment to print c++ related info
              // log(",");
            }
          })
        );
        log("\n");
        // * enable this comment to print c++ related info
        // log("},{\n");
      });
    });
  }
}

let c = new cube();
let t = new timer();
c.applyMoves("f2 l2 u r2 u l2 d2 f2 u' l2 u f' u r d r' f2 d' u2 l'");
c.applyMoves("u' r' l' u2 b2 l' u2 r' b' u' l b2 d2 b2 u l2 u r2 u'");
console.log(t.getElapsedTime());
// * enable this comment to print c++ related info
// c.applyMoves("u u' u2 l l' l2 f f' f2 r r' r2 b b' b2 d d' d2");
c.printCube();