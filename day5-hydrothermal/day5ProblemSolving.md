# Hydrothermal Venture

## Part 1
- we will use a grid of integer coordinates
- we are considering only horizontal or vertical lines, i.e., x1=x2, y1=y2
- calculate which points lie on the horizontal/vertical lines formed between the pairs of coords, update grid of coords if a point found

### General Method
- read a line of the input file
- get (x1,y1), (x2,y2)
- if horizontal or vertical, calculate points and update grids
- repeat for all lines.
- count number of points that have score > 1 and output
- end

-- Part 1 Solved.

## Part 2
- same exact problem, just consider the diagonal lines, i.e gradient = 1 lines too

### General Method
- exact same as the first part, just need to modify the overlapsUpdater fn and the lineChecker fn to cater for diagonal lines
