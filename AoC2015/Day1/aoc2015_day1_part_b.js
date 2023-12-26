/**
 * Now, given the same instructions, find the position 
 * of the first character that causes him to enter the 
 * basement (floor -1).
 */

/** Functions */
function findBasementPosition(instructions) {
    /**
     * Find position of the first character that causes 
     * santa to enter the basement floor (-1).
     */
    // Santa starts at floor zero
    var floorNumber = 0, instructionPosition = 1;
    // Iterate over instructions
    for (instruction of instructions) {
        if (instruction === '(') {
            floorNumber++;
        } else if (instruction === ')') {
            floorNumber--;
            if (floorNumber < 0) return instructionPosition;
        }
        instructionPosition++;
    }
}

/** Driver Program */
// Santa's instructions
instructions = null;
// Require the filesystem module
const fs = require('fs');
// Require the assertions module
const assert = require("assert");
// Read contents of file as a string synchronously
try {
    instructions = fs.readFileSync('aoc2015_day1_input.txt', 'utf8');
} catch (err) {
    if (err) console.error(err);
}

/** Assertions */
// Some assertions to check the function is working correctly
try {
    // Sample I/O assertions
    assert.equal(findBasementPosition(")"), 1, "TEST1");
    assert.equal(findBasementPosition("()())"), 5, "TEST2");
    // Final assertion on challenge input
    assert.equal(findBasementPosition(instructions), 1783, "TESTN");
} catch (err) {
    console.error(err);
}