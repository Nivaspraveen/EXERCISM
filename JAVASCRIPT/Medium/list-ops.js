// Solution for List Ops

export class List {
  constructor(values = []) {
    this.values = values;
  }

  append(other) {
    const result = [...this.values];
    for (let item of other.values) result[result.length] = item;
    return new List(result);
  }

  concat(...lists) {
    const result = [...this.values];
    const flatten = (list) => {
      for (let item of list.values) {
        if (item instanceof List) flatten(item);
        else result.push(item);
      }
    };
    for (let list of lists) {
      if (list instanceof List) flatten(list);
      else result.push(list);
    }
    return new List(result);
  }

  filter(predicate) {
    const result = [];
    for (let item of this.values) {
      if (predicate(item)) result[result.length] = item;
    }
    return new List(result);
  }

  map(func) {
    const result = [];
    for (let item of this.values) result[result.length] = func(item);
    return new List(result);
  }

  length() {
    let count = 0;
    for (let item of this.values) count += 1;
    return count;
  }

  foldl(func, acc) {
    for (let item of this.values) acc = func(acc, item);
    return acc;
  }

  foldr(func, acc) {
    for (let i = this.values.length - 1; i >= 0; i--)
      acc = func(acc, this.values[i]);
    return acc;
  }

  reverse() {
    const result = [];
    for (let i = this.values.length - 1; i >= 0; i--)
      result[result.length] = this.values[i];
    return new List(result);
  }
}
