# 22-1-phonebook

Write a phone book program.
The program receives three types of requests:
69-70-30 Ivanov - add the phone number and last name of the subscriber to the directory
69-70-30 - find out the name of the subscriber by phone number
Ivanov - find out the subscriber's phone number by last name

It is necessary to output the response to requests 2 and 3 to the console. Please note that subscribers at different numbers may have the same last name. In this case, for query 3, you must return all numbers separated by spaces.

Query operations should run in O(logn) or O(logn × number of numbers with this last name).
