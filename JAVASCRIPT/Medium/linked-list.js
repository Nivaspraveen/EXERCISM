// Solution for Linked List

export class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  push(value) {
    const newNode = { value, next: null, prev: null };
    if (this.tail) {
      newNode.prev = this.tail;
      this.tail.next = newNode;
      this.tail = newNode;
    } else this.head = this.tail = newNode;
    this.size++;
  }

  pop() {
    if (!this.tail) throw new Error("List is empty");
    const value = this.tail.value;
    if (this.tail.prev) {
      this.tail = this.tail.prev;
      this.tail.next = null;
    } else this.head = this.tail = null;
    this.size--;
    return value;
  }

  shift() {
    if (!this.head) throw new Error("List is empty");
    const value = this.head.value;
    if (this.head.next) {
      this.head = this.head.next;
      this.head.prev = null;
    } else this.head = this.tail = null;
    this.size--;
    return value;
  }

  unshift(value) {
    const newNode = { value, next: null, prev: null };
    if (this.head) {
      newNode.next = this.head;
      this.head.prev = newNode;
      this.head = newNode;
    } else this.head = this.tail = newNode;
    this.size++;
  }

  delete(value) {
    let current = this.head;
    while (current) {
      if (current.value === value) {
        if (current.prev) current.prev.next = current.next;
        else this.head = current.next;
        if (current.next) current.next.prev = current.prev;
        else this.tail = current.prev;
        this.size--;
        return;
      }
      current = current.next;
    }
  }

  count() {
    return this.size;
  }
}
