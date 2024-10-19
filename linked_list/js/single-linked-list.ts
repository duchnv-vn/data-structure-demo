interface CustomNode {
  data: any;
  next: CustomNode | null;
}

const create_list = (data: any): CustomNode => {
  const head = { data, next: null } as CustomNode;
  return head;
};

const insert_node_to_head = () => {};

const insert_node_to_last = () => {};

const insert_node_to_specified_index = () => {};

const delete_first_node = () => {};

const delete_last_node = () => {};

const delete_specified_node_by_value = () => {};

const delete_specified_node_by_index = () => {};

const update_node_at_specified_index = () => {};

const main = () => {
  const list1 = create_list(1);
};
main();
