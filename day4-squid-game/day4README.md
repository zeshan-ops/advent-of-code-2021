# Day 4 Squid Game Documentation

## Blah blah blah
This one took a while. The program accepts input without blank lines. And the input data must have only single spaces
between integers. I did this because it was faster to clean the data and get it into that form than it was to write code
that would deal with the input file as given by AoC. Data was cleaned by importing to libreoffice calc, selecting spaces and commas as delimeteres and then selecting the merge delimeters option. This left some rows of the input data shifted to the right by one unit, so they had to be manually shifted back in line. Then first line (bingo numbers) were deleted, file exported as a .txt with commas as the delimters, first line pasted back in. (did it this weird way bcoz leaving the first line gave loads of unnecesary commas in the .txt file).

The delimiter doesn't matter, you just change it on lines 131 and 112 as needed.

The code in its current form only solves part two of the problem. Again, it was quicker for me to change the code that solved part 1 than to write extra code so it would solve both parts. Bad coding practice but it is what it is.

## Notes
- could have used a single 3d vector of tuples instead of two separate vectors to store the boards and the board scores.
- did not investigate if there was any mathematics that would have enabled a simpler soln
- should get into habit of implementing fuller code rather than code that needs to be changed depending on nature of run
- a lot of "for" loops. should look up if theres a way to join them together or do smth different.

