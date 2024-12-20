// Solution for Grade School

export class GradeSchool {
  constructor() {
    this.schoolRoster = {};
  }

  roster() {
    return JSON.parse(JSON.stringify(this.schoolRoster));
  }

  add(name, grade) {
    for (const gradeStud of Object.values(this.schoolRoster)) {
      const index = gradeStud.indexOf(name);
      if (index !== -1) {
        gradeStud.splice(index, 1);
        break;
      }
    }
    if (!this.schoolRoster[grade]) this.schoolRoster[grade] = [];
    this.schoolRoster[grade].push(name);
    this.schoolRoster[grade].sort();
  }

  grade(g) {
    return this.schoolRoster[g] ? [...this.schoolRoster[g]] : [];
  }
}
