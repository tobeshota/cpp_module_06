#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <cstdlib>  // for rand()
#include <ctime>    // for time()

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define OBJECT_TYPE_IS_A_MSG "A"
#define OBJECT_TYPE_IS_B_MSG "B"
#define OBJECT_TYPE_IS_C_MSG "C"
#define UNKNOWN_OBJECT_MSG "Object type is not A or B or C"

/**
 * It randomly instanciates A, B or C and returns the instance as a Base
 * pointer. Feel free to use anything you like for the random choice
 * implementation.
 */
Base* generate(void);

/**
 * It prints the actual type of the object pointed to by p: "A", "B" or "C".
 */
void identify(Base* p);

/**
 * It prints the actual type of the object pointed to by p: "A", "B" or "C".
 * Using a pointer inside this function is forbidden.
 */
void identify(Base& p);

#endif
