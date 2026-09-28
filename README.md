# Sorting Analysis of Fixed-Length IDs

## Input Data

```text
324, 125, 456, 218, 102, 389, 275, 147
```

## Source Code

See `sorting_analysis.c`.

## Merge Sort

Using bottom-up Merge Sort:

Pass 1:
```text
125, 324, 218, 456, 102, 389, 147, 275
```

Pass 2:
```text
125, 218, 324, 456, 102, 147, 275, 389
```

Pass 3:
```text
102, 125, 147, 218, 275, 324, 389, 456
```

Number of merge passes: **3**

## Quick Sort

Quick Sort uses the last element as the pivot.

Number of partitions: **5**

Final sorted sequence:
```text
102, 125, 147, 218, 275, 324, 389, 456
```

## Performance

See `comparison_table.md`.

## Complexity

See `complexity_analysis.md`.

### Merge Sort
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)
- Space: O(n)

### Quick Sort
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n²)
- Space: O(log n) average

## Final Conclusion

Both algorithms successfully sort the given fixed-length IDs. Merge Sort provides predictable O(n log n) worst-case performance but requires O(n) additional space. Quick Sort has O(n log n) average performance and generally uses less additional space, but its worst-case time complexity can become O(n²) depending on pivot selection.

For large fixed-length keys where predictable worst-case performance is important, Merge Sort is an appropriate approach.
