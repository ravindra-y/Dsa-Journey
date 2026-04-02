# LeetCode 186 - Reverse Words in a String II

## Problem Description

Given a character array `s`, reverse the order of the words in-place.

A word is defined as a sequence of non-space characters.\
The words in `s` are separated by a single space.

You must solve the problem using **O(1) extra space**.

------------------------------------------------------------------------

## Example 1

**Input:**

    s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]

**Output:**

    ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

**Explanation:**

The input array represents the string:

    "the sky is blue"

After reversing the words in-place, it becomes:

    "blue is sky the"

------------------------------------------------------------------------

## Constraints

-   `1 <= s.length <= 10^5`
-   `s[i]` is an English letter (uppercase or lowercase) or a space
    `' '`.
-   There is at least one word in `s`.
-   Words in `s` are separated by a single space.
-   There are no leading or trailing spaces.

------------------------------------------------------------------------

## Follow-up

Can you solve the problem without allocating extra space for another
array?

------------------------------------------------------------------------

## Notes

-   The input is given as a **character array**, not a string.
-   You must modify the input array in-place.
-   Using built-in string split or reverse functions that require extra
    space is not allowed.
