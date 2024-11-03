local SingleLinkedList = require("single-linked-list")
local SingleLinkedListOOP = require("single-linked-list-oop")

local function main()
    -- Normal method
    if false then
        local list_1 = SingleLinkedList.create_list(10)

        list_1 = SingleLinkedList.insert_to_head(list_1, 0)
        SingleLinkedList.insert_to_last(list_1, 30)
        SingleLinkedList.insert_to_last(list_1, 40)
        SingleLinkedList.insert_by_index(list_1, 3, 50)
        SingleLinkedList.update_by_index(list_1, 3, 20)
        SingleLinkedList.insert_by_index(list_1, 4, 99)
        SingleLinkedList.delete_by_index(list_1, 4)
        SingleLinkedList.delete_by_data(list_1, 40)
        SingleLinkedList.delete_last(list_1)
        list_1 = SingleLinkedList.delete_first(list_1)

        SingleLinkedList.foreach(list_1, function(node, index)
            print(index, node.data)
        end)
    end

    -- OOP method
    if true then
        local list_2 = SingleLinkedListOOP.new(10)
        list_2:insert_to_head(0)
        list_2:insert_to_last(50)
        list_2:insert_by_index(3, 20)
        list_2:insert_by_index(4, 30)
        list_2:update_by_index(5, 40)
        list_2:delete_first()
        list_2:delete_last()
        list_2:delete_by_index(2)
        list_2:delete_by_data(30)

        list_2:foreach(function(node, index)
            print(index, node.data)
        end)
    end
end
main()
