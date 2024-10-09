class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        raise IndexError("pop from empty stack")

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        raise IndexError("peek from empty stack")

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

# Example of using the stack to build an array
def build_array_with_stack(elements):
    stack = Stack()
    
    # Push elements onto the stack
    for element in elements:
        stack.push(element)
    
    # Pop elements from the stack to create an array
    array = []
    while not stack.is_empty():
        array.append(stack.pop())
    
    return array

# Example usage
elements = [1, 2, 3, 4, 5]
result_array = build_array_with_stack(elements)
print(result_array)  # Output: [5, 4, 3, 2, 1]