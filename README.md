# Anagram Game
# Shivam

This program uses a clever application of hash tables/an unordered map in order to create a text based jumble game.

The program is called jumble and requires a single command-line argument specifying a dictionary file.  For example:

./jumble dictionary-small.txt

Overview of what the program does when compiled and ran:

The user does one of the following:
 a) enter a string of characters (presumably a jumbled version of one or more English words).
 b) types ctrl-d to terminate the interactive loop.
If the user enters a string (1a above), a list of all English words in the given dictionary that are rearrangements (anagrams) of the user input.  The list can appear in any order.  If there are no such English words, the program reports “no matches.”  The user is then prompted for another input.
When the user terminates the interactive loop (1b above), the program produces a report with information about the .txt file that was used for input.

# Note: This program assumes that upper case and lower case letters are distinguishable and that the user's dictionary file does not contain duplicates - no special processing to skip duplicates.
