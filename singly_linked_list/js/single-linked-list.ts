interface CustomNode {
  data: any;
  next: CustomNode | null;
}

export class LinkedListNode {
  head!: CustomNode;

  constructor(data: any) {
    this.head = { data, next: null };
  }

  insertToHead(data: any) {
    this.head = {
      data,
      next: this.head,
    };
  }

  insertToLast(data: any) {
    const newNode = { data, next: null } as CustomNode;
    let currNode = this.head;
    while (currNode.next) currNode = currNode.next;
    currNode.next = newNode;
  }

  insertByIndex(index: number, data: any) {
    const newNode = { data, next: null } as CustomNode;
    let currNode = this.head;
    let count = 0;
    while (currNode.next) {
      if (count + 1 === index) {
        newNode.next = currNode.next;
        currNode.next = newNode;
        break;
      }

      currNode = currNode.next;
    }
  }

  updateByIndex(index: number, data: any) {
    let currNode = this.head;
    let count = 0;
    while (currNode.next) {
      if (count === index) {
        currNode.data = data;
        break;
      }

      currNode = currNode.next;
    }
  }

  deleteFirst() {
    this.head.next && (this.head = this.head.next);
  }

  deleteLast() {
    let currNode = this.head;
    while (currNode.next?.next) currNode = currNode.next;
    currNode.next = null;
  }

  deleteByValue(data: any) {
    let currNode = this.head;
    while (currNode.next) {
      if (currNode.next.data === data) {
        currNode.next = currNode.next.next;
        break;
      }

      currNode = currNode.next;
    }
  }

  deleteByIndex(index: number) {
    let currNode = this.head;
    let count = 0;
    while (currNode.next) {
      if (count + 1 === index) {
        currNode.next = currNode.next.next;
        break;
      }

      currNode = currNode.next;
    }
  }

  foreach(cb: (node: CustomNode, index: number) => void) {
    let currNode = this.head;
    let index = 0;
    while (currNode.next) {
      cb(currNode, index);
      index += 1;
      currNode = currNode.next;
    }
  }
}
