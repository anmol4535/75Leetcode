// Question : Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.
// Note: The characters in the array beyond the returned length do not matter and should be ignored.

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
         int n = (int)chars.size();
        if (n == 0) return 0;
        int write = 0;     // position to write compressed chars
        int anchor = 0;    // start index of the current run

        for (int read = 0; read <= n; ++read) {
            // when read reaches end OR character changes, we flush the run [anchor, read-1]
            if (read == n || chars[read] != chars[anchor]) {
                // write the character
                chars[write++] = chars[anchor];

                int count = read - anchor;
                if (count > 1) {
                    // write each digit of count
                    string cnt = to_string(count);
                    for (char c : cnt) {
                        chars[write++] = c;
                    }
                }
                // start a new run at read
                anchor = read;
            }
        }

        return write;
    }