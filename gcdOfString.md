Question is:
    For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

    Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

approach:
    this is question very good i take nearly 50 min to solve the problem and the main intuition to solve the problem is you have to think which prefix gone be the correct answer and how to neglect the wrong  testcase.

the idea to neglect he wrong testcase is  to see the string produce after adding the string in both manner and if they differ than you have to neglect the string.

You have to find which prefix is gone be your answer and i think by greater no. of s=length of preficx it gone easy to find the answer.