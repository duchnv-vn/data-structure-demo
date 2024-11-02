local SingleLinkedList = require("single-linked-list")

local function main()
    local list_1 = SingleLinkedList.create_list(10)

    list_1 = SingleLinkedList.insert_to_head(list_1, 0)
    SingleLinkedList.insert_to_last(list_1, 30)
    SingleLinkedList.insert_to_last(list_1, 40)
    SingleLinkedList.insert_to_specified_index(list_1, 3, 50)
    SingleLinkedList.update_at_specified_index(list_1, 3, 20)
    SingleLinkedList.insert_to_specified_index(list_1, 4, 99)
    SingleLinkedList.delete_by_index(list_1, 4)
    SingleLinkedList.delete_by_data(list_1, 40)
    SingleLinkedList.delete_last(list_1)
    list_1 = SingleLinkedList.delete_first(list_1)

    local currNode = list_1
    --[[
    Print:
        Value: 10
        Value: 20
    ]]
    while currNode ~= nil do
        print("Value: " .. currNode.data)
        currNode = currNode.next
    end
end
main()
