/**
 * Program to calculate which floor the instructions 
 * from the text file will take Santa to in the apartment 
 * building. 
 */

/** Functions */
function calculateSantaFloor(instructions) {
    /**
     * Function to calculate which floor Santa ends up
     * on after following the instructions in the text 
     * file.
     */
    // Santa starts at floor zero
    var floorNumber = 0;
    // Iterate over instructions
    for (instruction of instructions) {
        if (instruction === '(') {
            floorNumber++;
        } else if (instruction === ')') {
            floorNumber--;
        }
    }
    // Return the floor number
    return Math.abs(floorNumber);
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
// Some assertions to check the function is working correctly
try {
    // Sample I/O assertions
    assert.equal(calculateSantaFloor("(())"), 0, "TEST1A");
    assert.equal(calculateSantaFloor("(())"), calculateSantaFloor("()()"), "TEST1B");
    assert.equal(calculateSantaFloor("((("), 3, "TEST2A");
    assert.equal(calculateSantaFloor("((("), calculateSantaFloor("(()(()("), "TEST2B");
    assert.equal(calculateSantaFloor("))((((("), 3, "TEST3");
    assert.equal(calculateSantaFloor("())"), 1, "TEST4A");
    assert.equal(calculateSantaFloor("())"), calculateSantaFloor("))("), "TEST4B");
    assert.equal(calculateSantaFloor(")))"), 3, "TEST5A");
    assert.equal(calculateSantaFloor(")))"), calculateSantaFloor(")())())"), "TEST5B");
    // Final assertion on challenge input
    assert.equal(calculateSantaFloor(instructions), 232, "TESTN");
} catch (err) {
    console.error(err);
}