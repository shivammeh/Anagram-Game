#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
*  this function rearranged the characters in a string
*    so that they are sorted (according to their ASCII
*    value).
*
*  Resource:  https://en.cppreference.com/w/cpp/algorithm/sort
*
*  Note:  this function is not actually used the the program
*    in this file.  But you might find it useful... :)
*/
void ssort(string &s) {
  /*
     strings are "iterable" objects and so have the begin()
     and end() functions.  These functions (in a pretty
     abstract way) return "iterators" which specify the
     "beginning" and "end" of the associated object).

     Thus, this call is asking the sort function to sort
     the entire string s.
  */
  sort(s.begin(), s.end());
}

/*
*   usage:   ./freq <filename>
*
*   example:  ./freq words.txt
*
*/
int main(int argc, char *argv[]){
  /*
     the variable lookingForJumble is an unordered_map
        from strings to vector of strings.
  */
  unordered_map<string, vector<string>> lookingForJumble;
  ifstream file;
  string word;
  int countOfWords = 0;

  if(argc != 2) {
    cout << "usage:  ./jumble <filename>\n";
    cout << "goodbye\n";
    return 1;
  }

  /*
  *  argv[1] is a C-string which is the filname specified
  *    by the user.  Let's try to open it.
  */

  file.open(argv[1], std::ios::in);

  if(!file.is_open()){
    cout << "Error: could not open file '" <<
                     argv[1] << "'\n";
    cout << "goodbye\n";
    return 1;
  }

  cout << "reading input file...\n";
  
  int largestClass = 0;
  string largestClassKey = "";
  
  while(file >> word) {
    string regularWord = word;
    ssort(word);
	countOfWords++;
    if(lookingForJumble.count(word) == 0) {
       lookingForJumble[word].push_back(regularWord);
	   if(lookingForJumble[word].size() > largestClass) {
		  largestClass = lookingForJumble[word].size();
		  largestClassKey = word;
	  }
    }
    else if(lookingForJumble.count(word) > 0) {
       lookingForJumble[word].push_back(regularWord);
	   if(lookingForJumble[word].size() > largestClass) {
		  largestClass = lookingForJumble[word].size();
		  largestClassKey = word;
	   }
    }
  }
  
  cout << "start entering jumbled words (ctrl-d to terminate)\n" << endl;
  cout << "> ";
  while(cin >> word) {
    ssort(word);
    if(lookingForJumble.count(word) > 0) {
      cout << "English Anagrams Found:\n";
      for(int i = 0; i < lookingForJumble[word].size(); i++) {
        cout << lookingForJumble[word].at(i) << "\n";
      }
      cout << ">";
    }
    else if(lookingForJumble.count(word) == 0) {
      cout << "no anagrams found...try again\n";
	  cout << ">";
    }
  }
  
  //user is wanting to end program we are now doing this:
  cout << "REPORT: " << endl;
  cout << "num_words: " << countOfWords << endl;
  cout << "num_classes: " << lookingForJumble.size() << endl;
  cout << "size-of-largest-class: " << largestClass << endl;
  cout << "largest-class key: " << largestClassKey << endl;
  cout << "Members of largest class: " << endl;
  for(int i = 0; i < lookingForJumble[largestClassKey].size(); i++) {
	  cout << "'" << lookingForJumble[largestClassKey].at(i) << "'" << endl;
  }
}