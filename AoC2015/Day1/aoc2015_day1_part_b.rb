# Now, given the same instructions, find the position 
# of the first character that causes him to enter the 
# basement (floor -1).

def find_basement_position(instructions)
    # Find position of the first character that causes 
    # santa to enter the basement floor (-1).
    # Santa starts at floor zero
    # Instruction position starts at one
    floor_number, instruction_position = 0, 1
    # Iterate over instructions
    instructions.chars.each do |instruction|
        if instruction == '('
            floor_number += 1
        elsif instruction == ')'
            floor_number -= 1
            if floor_number < 0
                return instruction_position
            end
        end
        instruction_position += 1
    end
end

# Driver program
instructions = IO.read("aoc2015_day1_input.txt") # Santa's instructions
# Some assertions to check the function is working correctly
puts "TEST1: #{find_basement_position(")") == 1}"
puts "TEST2: #{find_basement_position("()())") == 5}"
# Final assertion on challenge input
puts "TESTN: #{find_basement_position(instructions) == 1783}"