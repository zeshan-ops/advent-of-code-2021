# Day 8 Problem Solving

## Part 1

- just need to count, for each line after the "|" delimiter, how many instances there are of 7, 2, 3 and 4 length inputs.
- getline into a stringstream, separate the stringstream using the "|" delimeter. another stringstream, separate using space delimeter
- count the number of characters in each string, if its 7,2,3 or 4, update counter by 1.
- repeat for all lines
- output counter

-- part 1 solved

## Part 2

- gotta add all of the output values
- figure out the segment organisation, lets you figure out which string on the first part of the input corresponds to which number
- then, match the strings on the second part of the input, regardless of characater order, to the numbers deduced on the left side
- the problem becomes how to tell the computer how it should deduce the segment organisation