# 0x13-count_it
This interview algorithm project utilizes the Reddit API: [https://www.reddit.com/dev/api/](https://www.reddit.com/dev/api/)

[Count it!](/0x13-count_it/0-count.py)
* Write a recursive function `def count_words(subreddit, word_list)` that:
  * queries the Reddit API,
  * parses the title of all hot articles,
  * and prints a sorted count of given keywords (case-insensitive, deliminated by spaces)
  * without using loops, only recursion
