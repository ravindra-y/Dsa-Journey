# Inversion Count (LeetCode-Style)

## Problem Statement

Given an integer array `arr` of size `N`, return the number of inversions in the array.

An inversion is a pair of indices `(i, j)` such that:

- `0 <= i < j < N`
- `arr[i] > arr[j]`

In simple terms, an inversion means two elements are in the wrong relative order for a sorted array.

## Example 1

**Input:**

- `arr = [2, 4, 1, 3, 5]`

**Output:**

- `3`

**Explanation:**
The inversions are:

- `(2, 1)`
- `(4, 1)`
- `(4, 3)`

## Example 2

**Input:**

- `arr = [5, 4, 3, 2, 1]`

**Output:**

- `10`

**Explanation:**
Every pair is inverted in a descending array of size 5, so total inversions = `5 * 4 / 2 = 10`.

## Example 3

**Input:**

- `arr = [1, 2, 3, 4, 5]`

**Output:**

- `0`

**Explanation:**
The array is already sorted, so no inversions exist.

## Constraints

- `1 <= N <= 10^5`
- `-10^9 <= arr[i] <= 10^9`

## Expected Complexity

- **Time:** `O(N log N)`
- **Auxiliary Space:** `O(N)`

## Approach (Merge Sort + Counting)

A brute-force approach checks all pairs and takes `O(N^2)`, which is too slow for large `N`.

This solution uses merge sort to count inversions efficiently:

1. Divide array into two halves.
2. Recursively count inversions in left half.
3. Recursively count inversions in right half.
4. While merging two sorted halves:
   - If `left[i] <= right[j]`, no inversion.
   - If `left[i] > right[j]`, then all remaining elements from `left[i]` to `left[end]` are greater than `right[j]`.
   - Add `(left_size - i)` to inversion count.

Total inversions = left inversions + right inversions + cross inversions found during merge.

## Why This Works

During merge, both halves are already sorted. So when `left[i] > right[j]`, every element after `left[i]` in left half is also greater than `right[j]`. This allows counting multiple inversions at once instead of checking pair by pair.
