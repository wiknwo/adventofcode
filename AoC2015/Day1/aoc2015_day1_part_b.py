"""
Now, given the same instructions, find the position 
of the first character that causes him to enter the 
basement (floor -1).
"""
def find_basement_position(instructions):
    """
    Find position of the first character that causes 
    santa to enter the basement floor (-1).
    """
    # Santa starts at floor zero
    # Instruction position starts at one
    floor_number, instruction_position = 0, 1
    # Iterate over instructions
    for instruction in instructions:
        if instruction == '(':
            floor_number += 1
        elif instruction == ')':
            floor_number -= 1
            if floor_number < 0:
                return instruction_position
        instruction_position += 1

if __name__ == '__main__':
    # This variable holds the instructions for Santa
    instructions = None
    # Open the file for processing
    with open("aoc2015_day1_input.txt", 'r') as f:
        # Reads contents of file as a single string
        instructions = f.read()
        # Close the file after processing
        f.close()
    # Some assertions to check the function is working correctly
    assert find_basement_position(")") == 1
    assert find_basement_position("()())") == 5
    # Print the solution to the challenge with the text file input
    print(find_basement_position(instructions))