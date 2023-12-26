# Program to calculate which floor the instructions 
# from the text file will take Santa to in the apartment 
# building.

def calculate_santa_floor(instructions)
    # Function to calculate which floor Santa ends up
    # on after following the instructions in the text 
    # file.
    # Santa starts at floor zero
    floor_number = 0
    # Iterate over instructions
    instructions.chars.each do |instruction|
        if instruction == '('
            floor_number += 1
        elsif instruction == ')'
            floor_number -= 1
        end
    end
    floor_number.abs
end

# Driver program
instructions = IO.read("aoc2015_day1_input.txt") # Santa's instructions
# Some assertions to check the function is working correctly
puts "TEST1: #{calculate_santa_floor("(())") == calculate_santa_floor("()()") && calculate_santa_floor("(())") == 0}"
puts "TEST2: #{calculate_santa_floor("(((") == calculate_santa_floor("(()(()(") && calculate_santa_floor("(((") == 3}"
puts "TEST3: #{calculate_santa_floor("))(((((") == 3}"
puts "TEST4: #{calculate_santa_floor("())") == calculate_santa_floor("))(") && calculate_santa_floor("())") == 1}"
puts "TEST5: #{calculate_santa_floor(")))") == calculate_santa_floor(")())())") && calculate_santa_floor(")))") == 3}"
# Final assertion on challenge input
puts "TESTN: #{calculate_santa_floor(instructions) == 232}"
# Note: Ruby does not have mutli-way comparison like Python
# Note: Ruby does not have string iteration, must convert to array of characters first with chars function