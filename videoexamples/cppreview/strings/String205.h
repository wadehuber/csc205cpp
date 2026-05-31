// String205.h
// C++ version of String205.java (header).
//
// Java review topic: working with strings and characters.
// Java's String -> C++ std::string. A quick mapping of the methods used here:
//   s.length()            -> s.length() or s.size()  (same)
//   s.charAt(i)           -> s[i]  or  s.at(i)
//   s.substring(a, b)     -> s.substr(a, b - a)   (note: C++ takes a LENGTH, not an end index!)
//   s.equals(t)           -> s == t               (compares contents in C++)
//   s.compareTo(t)        -> s.compare(t)
//   s.split(" ")          -> we write our own split() helper
//   Character.isLetter(c) -> std::isalpha((unsigned char)c)   (from <cctype>)
//   Character.toLowerCase -> std::tolower((unsigned char)c)
// The <cctype> functions take an int and misbehave on negative char values,
// so we cast char to unsigned char before calling them.

#ifndef STRING205_H
#define STRING205_H

#include <string>
#include <vector>

// Helper that mimics Java's String.split(delimiter) for a single-char delimiter.
std::vector<std::string> split(const std::string& s, char delim);

// Example of using the "is this a letter?" test.
std::string justLetters(const std::string& s);

// Returns a string with the vowels removed.
std::string noVowels(const std::string& s);

bool isVowel(char c);

// Print the words in a string one-by-one.
void individualWords(const std::string& s);

#endif
