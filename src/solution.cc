#include "solution.hpp"

#include <fstream>
#include <string>

#include "student.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  // Create the storage variables
  std::string first_name("");
  std::string last_name("");
  char place_holder = '\0';
  char place_holder_2 = '\0';
  unsigned int uin = 0;
  double gpa = 0;

  // Read the line, assign values to variables
  is >> first_name >> last_name >> place_holder >> uin >> place_holder_2 >> gpa;

  // Check if input file stream failed
  if (is.fail() || place_holder != ',' || place_holder_2 != ',')
    return Student{};

  // Combine first_name and last_name
  std::string name = first_name + ' ' + last_name;

  // Return student
  return Student{name, uin, gpa};
}