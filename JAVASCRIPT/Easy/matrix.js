// Solution for Matrix

export class Matrix {
  constructor(str) {
    this.row = str.split("\n").map((r) => r.split(" ").map(Number));
  }

  get rows() {
    return this.row;
  }

  get columns() {
    return this.row[0].map((_, col) => this.row.map((r) => r[col]));
  }
}
