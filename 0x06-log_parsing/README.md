# 0x06-log_parsing
For this interview practice algorithm, the code reads from `stdin` and computes metrics.

[Log Parsing](/0x06-log_parsing/0-stats.py)
* Write a Python script that reads `stdin` line by line and computes metrics:
  * Input format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
  * After every 10 lines and/or a keyboard interruption (`CTRL + C`), print statistics from the beginning:
    * Total file size: `File size: <total size>`, where `<total size>` is the sum of all previous `<file size>`
    * Number of lines by status code:
      * possible status code: 200, 301, 400, 401, 403, 405, and 500
      * if a status code doesn't appear, don't print anything for status code
      * format: `<status code>: <number>`
      * status codes should be printed in ascending order

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally.
