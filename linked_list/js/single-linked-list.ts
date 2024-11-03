interface CustomNode {
  data: any;
  next: CustomNode | null;
}

class LinkedListNode {
  head!: CustomNode;

  constructor(data: any) {
    this.head = { data, next: null };
  }

  insertToHead(data: any) {}

  insertToLast(data: any) {}

  insertByIndex() {}

  updateByIndex() {}

  deleteFirst() {}

  deleteLast() {}

  deleteByValue() {}

  deleteByIndex() {}
}

const main = () => {
  const list1 = new LinkedListNode(10);
};
main();
