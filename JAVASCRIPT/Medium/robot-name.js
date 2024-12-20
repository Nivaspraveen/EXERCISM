// Solution for Robot Name

export class Robot {
  static usedNames = new Set();
  static namePool = Robot.generateNamePool();
  static generateNamePool() {
    const letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
      names = [];
    for (let i = 0; i < letters.length; i++) {
      for (let j = 0; j < letters.length; j++) {
        for (let k = 0; k < 1000; k++) {
          const name = `${letters[i]}${letters[j]}${String(k).padStart(
            3,
            "0"
          )}`;
          names.push(name);
        }
      }
    }
    return names.sort(() => Math.random() - 0.5);
  }

  constructor() {
    this.assignName();
  }

  assignName() {
    if (Robot.namePool.length === 0)
      throw new Error("All possible names have been used");
    const newName = Robot.namePool.pop();
    Robot.usedNames.add(newName);
    Object.defineProperty(this, "name", {
      value: newName,
      writable: false,
      configurable: true,
    });
  }

  reset() {
    Robot.usedNames.delete(this.name);
    this.assignName();
  }

  static releaseNames() {
    Robot.usedNames.clear();
    Robot.namePool = Robot.generateNamePool();
  }
}

Robot.releaseNames = () => {};
