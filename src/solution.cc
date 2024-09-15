#include "solution.hpp"

#include <fstream>
#include <string>

#include "student.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  // Create the storage variables
  std::string first_name("");
  std::string last_name("");
  char place_holder = '\0';
  unsigned int uin = 0;
  double gpa = 0;

  // Read the line, assign values to variables
  is >> first_name >> last_name >> uin >> place_holder >> gpa;

  // Check if input file stream failed
  if (is.fail() || place_holder != ',' ||
      last_name[last_name.size() - 1] != ',')
    return Student{};

  // Combine first_name and last_name
  std::string name =
      first_name + ' ' + last_name.substr(0, last_name.size() - 1);

  // Return student
  return Student{name, uin, gpa};
}