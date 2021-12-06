# Day 6 Lanternfish

## Part 1
- I think we can just read the input into a vector, push_back cuz the vector will keep getting bigger each time new lanternfish is spawned
- update the vector according to a set of rules as given by the problem description
- after 80 updates, vector.size() is the answer. bish bash bosh

-- Part 1 Solved

## Part 2
- vector method way too slow so ive come up with another method that should work
- only 9 possible lifetimes [0-8]
- just update number of fish with each lifetime
- each update, shift the numbers down by one
- zeros go to sixes and eights.

