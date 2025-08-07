You are given 6 dominoes. A domino has 2 halves each with a number of spots. You are building a 3-level pyramid of dominoes. The bottom level has 3 dominoes, the middle level has 2, and the top has 1.

The arrangement is such that each level is positioned over the center of the level below it. Here is a visual:

```
         [ 3 | 4 ]
    [ 2 | 3 ] [ 4 | 5 ]
[ 1 | 2 ][ 3 | 4 ][ 5 | 6 ]
```

The pyramid must be set up such that the number of spots on each domino half should be the same as the number on the half beneath it. This doesn't apply to neighboring dominoes on the same level.

Is it possible to build a pyramid from 6 dominoes in the arrangement described above? Dominoes can be freely arranged and rotated.

Write a function that takes an array of 12 ints (such that arr[0], arr[1] are the first domino, arr[2], arr[3] are the second domino, etc.) and return "YES" or "NO" if it is possible or not to create a pyramid with the given 6 dominoes.

Thank you.
