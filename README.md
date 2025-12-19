*This project has been created as part of the 42 curriculum by hpehliva.*

## Description

**Push_swap** is a sorting algorithm project that sorts a stack of integers using a limited set of operations. The goal is to sort the numbers with the minimum possible number of moves using two stacks (a and b).

### Performance Benchmarks
- **100 random numbers:** sorted in fewer than 700 operations
- **500 random numbers:** sorted in fewer than 5500 operations

### Algorithm Approach

This implementation is based on the **Turkish Algorithm**, enhanced with **Longest Increasing Subsequence (LIS)** for improved efficiency:

1. **LIS Optimization:** Before any movement, the algorithm identifies the longest increasing subsequence in stack A. These elements are kept in place as they are already in relative sorted order.

2. **Selective Push:** Only elements that are NOT part of the LIS are pushed to stack B, reducing the total number of operations.

3. **Cost Calculation:** For each element in stack B, the algorithm calculates the optimal cost to move it back to its correct position in stack A.

4. **Cheapest Move:** The element with the lowest total movement cost is selected and moved first, ensuring minimal operations.

This combination of LIS pre-processing and cost-based movement optimization results in significantly fewer operations compared to the standard Turkish algorithm alone.

### Available Operations
- `sa`, `sb`, `ss` - Swap first two elements
- `pa`, `pb` - Push element between stacks
- `ra`, `rb`, `rr` - Rotate (shift up)
- `rra`, `rrb`, `rrr` - Reverse rotate (shift down)

## Instructions

### Compilation
```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage
```bash
ARG="100 or 500 random number"; ./push_swap $ARG | ./checker_linux $ARG
ARG="100 or 500 random number"; ./push_swap $ARG | wc -l // to see how many oparations
ARG="100 or 500 random number";valgrind --leak-check=yes ./push_swap $ARG // leak check
./push_swap "3 1 6 2 5 4"
./push_swap 3 1 6 2 5 4
```

## Resources

- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Longest Increasing Subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)

### AI Usage
AI tools were used for:
- Understanding algorithm complexity concepts
- Debugging and optimization suggestions

