# Day 6 README.md

lanternfish.cpp and lanterfish2.cpp both use the std::vector data structure

the key difference is that lanternfish.cpp tracked each fish as a separate entry in the vector
while lanternfish2.cpp has only 9 members, each counting the number of fish that exist with a certain internal timer value

lanternfish.cpp is thus slow af, lanternfish2.cpp is fast
