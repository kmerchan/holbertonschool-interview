# 0x1E-wild_cmp
This interview algorithm project compares two strings without using any loops and the second string can contain wildcard characters that can each replace any string (including empty strings).

[Wild Compare](/0x1E-wild_cmp/0-wildcmp.c)
* Write a function in C `int wildcmp(char *s1, char *s2)` that compares two strings recursively, where one string can contain wildcard characters the can replace any string.
  * returns 1 if the strings can be considered identical, 0 otherwise
  * `s2` can contain the special character `*`
  * the `*` character can replace any string (including an empty string)

### test_files
The [test_files](/0x1E-wild_cmp/test_files/) directory contains files used to test the output of the algorithm locally.
