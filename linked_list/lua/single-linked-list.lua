local module = {}

---@param head table
---@param cb function
function module.foreach(head, cb)
    local currNode = head
    local index = 0
    while currNode ~= nil do
        index = index + 1
        cb(currNode, index)
        currNode = currNode.next
    end
end

---@param head table
function module.delete_first(head)
    return head.next
end

---@param head table
function module.delete_last(head)
    local currNode = head
    while currNode.next.next ~= nil do
        currNode = currNode.next
    end

    currNode.next = nil
end

---@param head table
---@param data any
function module.delete_by_value(head, data)
    local currNode = head
    while currNode.next ~= nil do
        if currNode.next.data == data then
            currNode.next = currNode.next.next
            break
        end
        currNode = currNode.next
    end
end

---@param head table
---@param index number
function module.delete_by_index(head, index)
    local currNode = head
    local count = 0
    while currNode.next ~= nil do
        count = count + 1
        if index == (count + 1) then
            currNode.next = currNode.next.next
            break
        end
        currNode = currNode.next
    end
end

---@param head table
---@param index number
---@param data any
function module.update_by_index(head, index, data)
    local currNode = head
    local count = 0
    while currNode ~= nil do
        count = count + 1
        if index == count then
            currNode.data = data
            break
        end

        currNode = currNode.next
    end
end

---@param head table
---@param data any
function module.insert_to_head(head, data)
    local newHead = {
        data = data,
        next = head
    }

    return newHead
end

---@param head table
---@param data any
function module.insert_to_last(head, data)
    local currNode = head
    while currNode.next ~= nil do
        currNode = currNode.next
    end

    local newNode = {
        data = data,
        next = nil
    }

    currNode.next = newNode
end

---@param head table
---@param index number
---@param data any
function module.insert_by_index(head, index, data)
    local newNode = {
        data = data,
        next = nil
    }

    local currNode = head
    local count = 0
    while currNode.next ~= nil do
        count = count + 1
        if index == (count + 1) then
            newNode.next = currNode.next
            currNode.next = newNode
            break
        end

        currNode = currNode.next
    end
end

---@param data any
function module.create_list(data)
    local head = {
        data = data,
        next = nil
    }

    return head
end

return module
