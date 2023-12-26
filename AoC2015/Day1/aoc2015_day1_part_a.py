"""
Program to calculate which floor the instructions 
from the text file will take Santa to in the apartment 
building. 
"""
def calculate_santa_floor(instructions):
    """
    Function to calculate which floor Santa ends up
    on after following the instructions in the text 
    file.
    """
    # Santa starts at floor zero
    floor_number = 0
    # Iterate over instructions
    for instruction in instructions:
        if instruction == '(':
            floor_number += 1
        elif instruction == ')':
            floor_number -= 1
    return abs(floor_number)

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
    assert calculate_santa_floor("(())") == calculate_santa_floor("()()") == 0
    assert calculate_santa_floor("(((") == calculate_santa_floor("(()(()(") == 3
    assert calculate_santa_floor("))(((((") == 3
    assert calculate_santa_floor("())") == calculate_santa_floor("))(") == 1
    assert calculate_santa_floor(")))") == calculate_santa_floor(")())())") == 3
    # Print the solution to the challenge with the text file input
    print(calculate_santa_floor(instructions))
