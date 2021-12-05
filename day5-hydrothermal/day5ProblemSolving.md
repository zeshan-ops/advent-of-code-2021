# Hydrothermal Venture

## Part 1
- we will use a grid of integer coordinates
- we are considering only horizontal or vertical lines, i.e., x1=x2, y1=y2

### Coding stuff
- vector<vector<int>> gridCounter: counts how many times a point is touched by a line

- the input file is in the form: (x1,y1) -> (x2,y2), so we will use getline to read the input file line by line and then stringstream with ' -> ' as the delimiter.

- then its a simple matter of updating the gridCounter vector after each line is read.

### Notes
- try to write a nicer program than the previous days aka dont be an imbecile