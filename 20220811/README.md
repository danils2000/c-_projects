Create a function that takes a 2D array of pyramid numbers and returns the maximum sum of consecutive numbers from the top to the bottom of the pyramid.

                        /3/
                        \7\ 4
                       2 \4\ 6
                      8 5 \9\ 3

// Longest slide down sum is 3 + 7 + 4 + 9 = 23
Examples
longestSlide([[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]) ➞ 23

longestSlide([[1], [2, 3], [4, 5, 6], [7, 8, 9, 10]]) ➞ 20

longestSlide([[2], [9, 4], [1, 8, 7], [6, 4, 7, 2]]) ➞ 26
