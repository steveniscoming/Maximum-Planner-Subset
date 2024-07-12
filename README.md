# Maximum-Planner-Subset
## Problem Description
Given is a set C of n chords of a circle (see Figure 1(a)). We assume that no two chords of C share an endpoint. Number the endpoints of these chords from 0 to 2n − 1, clockwise around the circle (see Figure 1(c)). Let 𝑀(𝑖,𝑗), 𝑖≤𝑗, denote the number of chords in the maximum planar subset (i.e., no two chords overlap each other in the subset) in the region formed by the chord 𝑖𝑗 and the arc between the endpoints i and j (see Figure 1(d)). As the example shown in Figure 1(a), 𝑀(2,7)=1, 𝑀(3,3)=0, and 𝑀(0,11)=3. You are asked to write a program that computes the number of chords in the maximum planar subset in a circle of n chords, i.e., compute 𝑀(0,2𝑛−1), and reports the details of each chords, as shown in Figure 1(b).
![image](https://github.com/user-attachments/assets/6af4171b-1cf7-4206-900c-f0bc4b015cca)
## Input
The input consists of an integer 2n, 1≤𝑛≤10000, denoting the number of vertices on a circle, followed by n lines, each containing two integers a and b (0≤𝑎,𝑏≤2𝑛−1), denoting two endpoints of a chord. A single “0” (zero) in the input line signifies the end of input.
## Output
The output file reports the number of chords in the maximum planar subset in the input circle of n chords, followed by a list of the two endpoints for each resulting chord in the maximum planar subset (sorted by the first endpoint in the increasing order).
![image](https://github.com/user-attachments/assets/c7b03302-2401-41a0-94d8-c85b6ae74db3)
## Language/Platform
(a) Language: C or C++.
(b) Platform: Unix/Linux.
## Command-line Parameter
In order to test your program, you are asked to add the following command-line parameters to your program 
(e.g., MPS 12.in 12.out):
[executable file name] [input file name] [output file name]
