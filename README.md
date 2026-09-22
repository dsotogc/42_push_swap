*This project has been created as part of the 42 curriculum by dsoto-ga, rtapiado.*

# push_swap

## Description

push_swap sorts a stack of integers using only two stacks (`a` and `b`) and a
limited set of operations, emitting the **shortest reasonable sequence of
operations** to sort `a` in ascending order.

The program integrates **four sorting strategies** and can pick one at runtime
depending on the input configuration. Complexity is measured in **number of
push_swap operations produced**, not in the theoretical complexity of a classic
array algorithm.

Allowed operations: `sa sb ss pa pb ra rb rr rra rrb rrr`.

## Instructions

```bash
make                       # build the push_swap binary
./push_swap <numbers>      # print the operations to sort the list
```

Numbers can be passed as separate arguments or as a single quoted string:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

**Strategy selector** (optional; default is `--adaptive`):

| Flag         | Strategy | Complexity   |
|--------------|----------|--------------|
| `--simple`   | forced   | O(n²)        |
| `--medium`   | forced   | O(n√n)       |
| `--complex`  | forced   | O(n log n)   |
| `--adaptive` | default  | see below    |

**Benchmark mode** (`--bench`): after sorting, prints to **stderr** the disorder
index, the strategy used and its complexity class, the total number of
operations and the per-operation breakdown. The operation stream stays on stdout.

```bash
# 2>&1 >/dev/null : send stderr where stdout points now (the terminal),
# THEN silence stdout -> shows only the [bench] report, hides the operations.
ARG="4 67 3 87 23"; ./push_swap --bench $ARG 2>&1 >/dev/null
./push_swap $ARG | ./checker_linux $ARG        # OK / KO
```

Errors (non-integers, values out of `int` range, duplicates) print `Error` to
stderr. With no arguments the program prints nothing.

## Disorder index

A value in `[0, 1]` measuring how far `a` is from sorted: the fraction of pairs
`(i, j)` with `i < j` that are out of order (inversions / total pairs). It is
computed **before** any operation and drives the adaptive strategy.

## Strategies and justification

- **Simple — bubble sort, O(n²).** Adjacent comparisons with `sa`/`ra`. Educational
  baseline that clearly belongs to the O(n²) class.
- **Medium — chunk sort, O(n√n).** Splits the range into ~√n chunks pushed to `b`
  by blocks, then brought back.
- **Complex — radix sort (binary LSD), O(n log n).** Sorts by the bits of the
  normalized index (`0..n-1`). ⌈log₂(n)⌉ passes × O(n) operations per pass =
  O(n log n). Reuses the index computation and doubles as the adaptive engine for
  highly disordered inputs.
- **Adaptive (default).** Picks an internal method by disorder index:

  | Disorder            | Method              | Target      |
  |---------------------|---------------------|-------------|
  | `< 0.2`             | near-sort           | O(n)        |
  | `0.2 ≤ d < 0.5`     | chunk (medium)      | O(n√n)      |
  | `d ≥ 0.5`           | radix (complex)     | O(n log n)  |

**Threshold justification.** Below `0.2` the list is almost sorted, so few
elements are displaced and a near-sort pays off. Between `0.2` and `0.5` a
block-based chunk sort balances cost. Above `0.5` the input is essentially
random and radix's guaranteed O(n log n) wins.

**Near-sort (O(n)) note.** It is *output-sensitive*: a single O(n) extraction
pass moves the elements that break monotonicity into `b`, then reinserts them.
The cost is O(n + k·n) with `k` = number of displaced elements. Since this branch
only runs when `disorder < 0.2` (few displaced elements in practice), the
effective cost is O(n) for near-sorted inputs.

As a shortcut, if the disorder index is `0` (already sorted) the program emits
**zero operations**.

## Performance

Verified with the provided `checker_linux` over 100 runs (default strategy):
100 random numbers average ≈ 836 ops (max 1084), 500 random numbers average
≈ 6042 ops (max 6784). Near-sorted inputs use far fewer via the adaptive O(n)
branch. Both comfortably beat the required limits (< 2000 for 100, < 12000 for
500).

## Contributions

- **dsoto-ga:** parsing, stack structures and primitive operations, operation
  wrappers, simple (bubble) sort, complex (radix) sort, benchmark mode, adaptive
  near-sort and strategy selector.
- **rtapiado:** disorder index and medium (chunk) sort.

## Resources

- *The Art of Computer Programming, Vol. 3: Sorting and Searching* — D. Knuth.
- Radix sort and complexity/Big-O references (Wikipedia, cppreference for C).
- 42 community discussions on push_swap strategies.

**AI usage.** AI assistance was used to review the primitive operations and
edge cases, to discuss and compare candidate algorithms for each complexity
class, to explain concepts (bitwise radix, the O(n) near-sort), and to help
draft this README.
