# Day 7 Problem Solving

## Part 1

- essence of problem is to minimise (sum_{i=1}^N abs(x_i - Y)) w.r.t Y and where {x_i} is an unordered set of positive integers
- there might be a maths trick but I can't see it
- Instead, I'll just brute force it, checking every possible integer value of Y that is less than max(x_i). It should compute quickly and the code is simple so meh.

- part 1 solved, but i dont like the soln, its a bit ugly, might be a better way to do it but im not gonna be the one to find it

## Part 2

- just have to change how fuelConsumption is calculated to sum_{n=1}^N (n) and that solves it i think

- part 2 solved, dont like this soln either, its slow but it is what it is.