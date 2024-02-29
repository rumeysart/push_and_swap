# push and swap

In this project, I am tasked with sorting random numbers using a limited set of commands. The goal is to achieve this sorting with the fewest possible operations.

# How to Use
Clone the repository: 
> git clone https://github.com/rumeysart/push_and_swap.git

Navigate to the repository directory: cd push_and_swap

Compile the project using the make command.

Run the program: ./push_swap <numbers>

Here, <numbers> can be positive or negative integers without repetition.
Example: ./push_swap 9 0 -217 2147483647 -2147483648

If the arguments are valid, the program will output the most efficient list of operations to sort the list.

You can also use the checker program to verify the correctness of the sorting:
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG

Additionally, you can run quick tests using make test3, make test5, make test100, or make test500.

