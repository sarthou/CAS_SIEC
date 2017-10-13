# 1 Naming Conventions
## 1.1 General Naming Conventions

### 1.1.1 Names representing types must be in mixed case starting with upper case.

Line, SavingsAccount

Common practice in the C++ development community.

### 1.1.2 Variable names must be all lower-case with underscores separating words.

line, savings_account

Common practice in the C++ development community. Makes variables easy to distinguish from types, and effectively resolves potential naming collision as in the declaration Line line.

### 1.1.3 Named constants (including enumeration values) must be all uppercase using underscore to separate words. Discussion

MAX_ITERATIONS, COLOR_RED, PI

Common practice in the C++ development community. In general, the use of such constants should be minimized. In many cases implementing the value as a method is a better choice:
```C++
  int getMaxIterations() // NOT #define MAX_ITERATIONS 25
  {
    return 25;
  }
```
This form is both easier to read, and it ensures a unified interface towards class values.

In cases where the value is needed as a constant expression two possibilities are encourages:
```C++
  constexpr int getMaxIterations() // NOT #define MAX_ITERATIONS 25
  {
    return 25;
  }
```

### 1.1.4 Names representing methods or functions must be verbs and written in mixed case starting with lower case.

getName(), computeTotalWidth()

Common practice in the C++ development community. This is identical to variable names, but functions in C++ are already distinguishable from variables by their specific form.

### 1.1.5 Names representing namespaces should be all lowercase.

model::analyzer, io::iomanager, common::math::geometry

### 1.1.6 Names representing typedefs should be written like type names.
```C++
typedef std::vector<cv::Point> PointVector; //NOT: PointVector_t, NOT: PointVector_type
typedef boost::shared_ptr<aslam::Camera> CameraPtr; //NOT: Camera_ptr
```
Using the same naming convention as for types allows easier exchange in cases where a typename is replaced by an actual type later. Discussion.

### 1.1.7 Names representing a structure should be written in mixed case starting with upper case.
```C++
struct points_t
{
...
};
```
### 1.1.8 Abbreviations and acronyms must not be uppercase when used as name.
```C++
exportHtmlSource(); // NOT: exportHTMLSource();
openDvdPlayer();    // NOT: openDVDPlayer();
```
Using all uppercase for the base name will give conflicts with the naming conventions given above. A variable of this type would have to be named dVD, hTML etc. which obviously is not very readable. Another problem is illustrated in the examples above; When the name is connected to another, the readbility is seriously reduced; the word following the abbreviation does not stand out as it should.

### 1.1.9 Global variables.

Global variables are forbidden.
 
### 1.1.10 Class variables should have underscore suffix.
```C++
class SomeClass {
  private:
    int length_;
}
```
Apart from its name and its type, the scope of a variable is its most important feature. Indicating class scope by using underscore makes it easy to distinguish class variables from local scratch variables. This is important because class variables are considered to have higher significance than method variables, and should be treated with special care by the programmer. A side effect of the underscore naming convention is that it nicely resolves the problem of finding reasonable variable names for setter methods and constructors:
```C++
  void setDepth (int depth)
  {
    depth_ = depth;
  }
```
An issue is whether the underscore should be added as a prefix or as a suffix. Both practices are commonly used, but the latter is recommended because it seem to best preserve the readability of the name.

It should be noted that scope identification in variables has been a controversial issue for quite some time. It seems, though, that this practice now is gaining acceptance and that it is becoming more and more common as a convention in the professional development community. Discussion

### 1.1.11 Generic variables should have the same name as their type.
```C++
void setTopic(Topic* topic) // NOT: void setTopic(Topic* value)
                            // NOT: void setTopic(Topic* aTopic)
                            // NOT: void setTopic(Topic* t)

void connect(Database* database) // NOT: void connect(Database* db)
                                 // NOT: void connect (Database* oracleDB)
```
Reduce complexity by reducing the number of terms and names used. Also makes it easy to deduce the type given a variable name only. If for some reason this convention doesn't seem to fit it is a strong indication that the type name is badly chosen.

Non-generic variables have a role. These variables can often be named by combining role and type:
```C++
  Point  startingPoint, centerPoint;
  Name   loginName;
```
### 1.1.12 All names should be written in English.
```C++
fileName;   // NOT: filNavn
```
English is the preferred language for international development.

### 1.1.13 Variables with a large scope should have long names, variables with a small scope can have short names.

Scratch variables used for temporary storage or indices are best kept short. A programmer reading such variables should be able to assume that its value is not used outside of a few lines of code. Common scratch variables for integers are i, j, k, m, n and for characters c and d.

### 1.1.14 The name of the object is implicit, and should be avoided in a method name.
```C++
line.getLength();   // NOT: line.getLineLength();
```
The latter seems natural in the class declaration, but proves superfluous in use, as shown in the example.

## 1.2 Specific Naming Conventions
### 1.2.1 The terms get/set must be used where an attribute is accessed directly. Use getVariableRef() if a reference is returned:
```C++
employee.getName();
employee.setName(name);

matrix.getElement(2, 4);
matrix.setElement(2, 4, value);

person.getAgeRef();
```
Common practice in the C++ development community. In Java this convention has become more or less standard. Discussion about how to handle references

### 1.2.2 The term compute can be used in methods where something is computed.
```C++
valueSet->computeAverage();
matrix->computeInverse()
```
Give the reader the immediate clue that this is a potentially time-consuming operation, and if used repeatedly, he might consider caching the result. Consistent use of the term enhances readability. 

### 1.2.3 Plural form should be used on names representing a collection of objects.
```C++
vector<Point>  points;
int            values[];
```
Enhances readability since the name gives the user an immediate clue of the type of the variable and the operations that can be performed on its elements. 

### 1.2.4 The prefix n should be used for variables representing a number of objects.

nPoints, nLines

### 1.2.5 Iterator variables should be called i, j, k if the loop is rather small (less than 10 lines):
```C++
for (int i = 0; i < nTables); ++i) {
  :
}
```
The notation is taken from mathematics where it is an established convention for indicating iterators. Variables named j, k etc. should be used for nested loops only.

Iterators should be called it
```C++
for (vector<MyClass>::iterator it = list.begin(); it != list.end(); ++it) {
  Element element = *it;
  ...
}
```
### 1.2.6 The prefix is should be used for boolean variables and methods.

isSet, isVisible, isFinished, isFound, isOpen

Common practice in the C++ development community and partially enforced in Java. Using the is prefix solves a common problem of choosing bad boolean names like status or flag. isStatus or isFlag simply doesn't fit, and the programmer is forced to choose more meaningful names.

There are a few alternatives to the is prefix that fit better in some situations. These are the has, can and should prefixes:
```C++
  bool hasLicense();
  bool canEvaluate();
  bool shouldSort();
```
### 1.2.7 Complement names must be used for complement operations.

get/set, add/remove, create/destroy, start/stop, insert/delete,
increment/decrement, old/new, begin/end, first/last, up/down, min/max,
next/previous, open/close, show/hide, suspend/resume, etc.

Reduce complexity by symmetry. 

### 1.2.8 Naming pointers specifically should be avoided.
```C++
Line* line; // NOT: Line* pLine;
            // NOT: LIne* linePtr;
```
Many variables in a C/C++ environment are pointers, so a convention like this is almost impossible to follow. 
Also objects in C++ are often oblique types where the specific implementation should be ignored by the programmer. 
Only when the actual type of an object is of special significance, the name should emphasize the type. 

### 1.2.9 Negated boolean variable names must be avoided.
```C++
bool isError; // NOT: isNoError
bool isFound; // NOT: isNotFound
```
The problem arises when such a name is used in conjunction with the logical negation operator as this results in a double negative. It is not immediately apparent what !isNotFound means. 

### 1.2.10 Enumeration constants can be prefixed by a common type name.
```C++
enum Color {
  COLOR_RED,
  COLOR_GREEN,
  COLOR_BLUE
};
```
This gives additional information of where the declaration can be found, which constants belongs together, and what concept the constants represent. 

An alternative approach is to always refer to the constants through their common type: Color::RED, Airline::AIR_FRANCE etc.

The C++11 enum class specifier can be used. The values cannot be implicitly converted to int anymore enforcing additional type-safety.
```C++
enum class Enumeration {
    Val1,
    Val2,
    Val3 = 100,
    Val4 // = 101
};
```
### 1.2.11 Exception classes should be suffixed with Exception.
```C++
class AccessException
{
  :
}
```
Exception classes are really not part of the main design of the program, and naming them like this makes them stand out relative to the other classes. 

## 1.3 Source Files

### 1.3.1 C++ header files should have the extension .hpp (preferred) or .h. Source files should have the extension .cpp.

MyClass.cpp, MyClass.hpp

These are all accepted C++ standards for file extension. 

### 1.3.2 A class should be declared in a header file and defined in a source file where the name of the files match the name of the class.

include/MyClass.hpp, src/MyClass.cpp

This makes it easy to find the associated files of a given class.

### 1.3.3 All definitions should reside in source files. 

Except the definition needs to stay in an included file (inline functions or any templated definition). 
Then it should be in a separate implementation header which is included at the end of the declaring header. 
Only definitions that are also very short and trivial as simple getters, setters or constructors with short initialization lists only or empty function implementations may be written directly in the declaring header file.

A non-templated class in MyClass.hpp:

```C++
class MyClass
{
public:
  int getValue () const {return value_;}  // NO, unless inlining required.
  ...

private:
  int value_;
};
```

A templated class in MyTemplatedClass.hpp:

```C++
template<typename T>
class MyTemplatedClass
{
public:
  virtual ~MyTemplatedClass(){} // Okay because trivial and templated.
  int getValue () const {return value_;} // Okay because trivial and templated.

  int calcComplicated(); // Only declaration in this header file because its definition is nontrivial.
  ...

private:
  int value_;
};
```

## 1.4 Include Files and Include Statements

### 1.4.1 Header files must contain an include guard.

```C++
#ifndef CLASSNAME_H
#define CLASSNAME_H
  :
#endif // CLASSNAME_H
```

The construction is to avoid compilation errors. The name convention resembles the location of the file inside the source tree and prevents naming conflicts. 

### 1.4.2 Include statements should be sorted and grouped. 

Sorted by their hierarchical position in the system with low level files included first. Leave an empty line between groups of include statements. 
The order of includes should be: C libs / C++ stl / ... / local includes. Local includes should be included using " ", others using <>. 
The include statements should be grouped by libraries.

```C++
#include <fstream>
#include <iomanip>

#include <qt/qbutton.h>
#include <qt/qtextfield.h>

#include "com/company/ui/PropertiesDialog.h"
#include "com/company/ui/MainWindow.h"
```

In addition to show the reader the individual include files, it also give an immediate clue about the modules that are involved. Include file paths must never be absolute. Compiler directives should instead be used to indicate root directories for includes.

### 1.4.3 Avoid nested includes.

All what the class needs should be included, for clarity Include all files which are required in the current translation unit. 
Do not rely on the include being done earlier up the include hierarchy.

### 1.4.4 Include statements must be located at the top of a file only. 

Common practice. Avoid unwanted compilation side effects by "hidden" include statements deep into a source file. 

# 2 Statements

## 2.1 Types

### 2.1.1 Types that are local to one file only can be declared inside that file. 

Enforces information hiding. 

### 2.1.2 The parts of a class must be sorted public, protected and private. 

All sections must be identified explicitly. Not applicable sections should be left out. 
The ordering is "most public first" so people who only wish to use the class can stop reading when they reach the protected/private sections. 

### 2.1.3 Type conversions should always be done explicitly. 

You should not rely on implicit type conversion.
```C++
floatValue = static_cast<float>(intValue); // NOT: floatValue = intValue;
```
By this, the programmer indicates that he is aware of the different types involved and that the mix is intentional. 

## 2.2 Variables

### 2.2.1 Variables should be initialized where they are declared. 

This ensures that variables are valid at any time. Sometimes it is impossible to initialize a variable to a valid value where it is declared:
```C++
  int x, y, z;
  getCenter(&x, &y, &z);
```
In these cases it should be left uninitialized rather than initialized to some phony value.

### 2.2.2 Variables must never have dual meaning. 

Enhance readability by ensuring all concepts are represented uniquely. Reduce chance of error by side effects. 

### 2.2.3 Use of global variables should be avoided. 

In C++ there is no reason global variables need to be used at all. The same is true for global functions. 

### 2.2.4 Use of static variables should be minimized. 

In C++ there only a few situations where static variables need to be used at all. One example is the Singleton pattern. 
In most other cases static variables should be replaced by enums. 

### 2.2.5 Class variables should never be declared public. 

The concept of C++ information hiding and encapsulation is violated by public variables. Use private variables and access functions instead. 
One exception to this rule is when the class is essentially a data structure, with no behavior (equivalent to a C struct). In this case it is appropriate to make the class instance variables public.

### 2.2.6 C++ pointers and references should have their reference symbol next to the type rather than to the name.
```C++
float* x; // NOT: float *x; 
int& y;   // NOT: int &y;
```
The pointer-ness or reference-ness of a variable is a property of the type rather than the name. 
C-programmers often use the alternative approach, while in C++ it has become more common to follow this recommendation.

### 2.2.7 Implicit test for 0 should not be used other than for boolean variables and pointers.
```C++
if (nLines != 0)  // NOT: if (nLines)
if (value != 0.0) // NOT: if (value)
```
It is not necessarily defined by the C++ standard that ints and floats 0 are implemented as binary 0. 
Also, by using an explicit test the statement gives an immediate clue of the type being tested. 
It is common also to suggest that pointers shouldn't test implicitly for 0 either, i.e. if (line == 0) instead of if (line). 
The latter is regarded so common in C/C++ however that it can be used.

### 2.2.8 Test of a pointer should use the C++11 nullptr type or implicit conversion to it instead of comparing against NULL / 0.
```C++
if (data != nullptr)  // NOT: if (data == NULL)
if(data) //NOT: if (data == 0)
```
### 2.2.9 Variables should be declared in the smallest scope possible. 

Keeping the operations on a variable within a small scope, it is easier to control the effects and side effects of the variable. 

## 2.3 Loops

### 2.3.1 Only loop control statements must be included in the for() construction.
```C++
sum = 0;                       // NOT: for (i = 0, sum = 0; i < 100; i++)
for (i = 0; i < 100; i++)                sum += value[i];
  sum += value[i];
```
Increase maintainability and readability. Make a clear distinction of what controls and what is contained in the loop. 

### 2.3.2 do-while loops can be avoided. 

do-while loops are less readable than ordinary while loops and for loops since the conditional is at the bottom of the loop. 
The reader must scan the entire loop in order to understand the scope of the loop. In addition, do-while loops are not needed. 
Any do-while loop can easily be rewritten into a while loop or a for loop. Reducing the number of constructs used enhance readbility.

### 2.3.3 The form while(true) should be used for infinite loops.
```C++
while (true) 
{
  :
}

for (;;) // AVOID!
{  
  :
}

while (1) // NO! 
{ 
  :
}
```
## 2.4 Conditionals

### 2.4.1 Complex conditional expressions must be avoided. Introduce temporary boolean variables instead.
```C++
bool isFinished = (elementNo < 0) || (elementNo > maxElement);
bool isRepeatedEntry = elementNo == lastElement;
if (isFinished || isRepeatedEntry) 
{
  :
}

// NOT:
if ((elementNo < 0) || (elementNo > maxElement)||
     elementNo == lastElement) 
{
  :
}
```
By assigning boolean variables to expressions, the program gets automatic documentation. The construction will be easier to read, debug and maintain. 

### 2.4.2 The nominal case should be put in the if-part and the exception in the else-part of an if statement.
```C++
bool isOk = readFile (fileName);
if (isOk) 
{
  :
}
else 
{
  :
}
```
Makes sure that the exceptions don't obscure the normal path of execution. This is important for both the readability and performance. 

### 2.4.3 The conditional should be put on a separate line. While not being necessary, the use of curly brackets around the statement is encouraged.
```C++
if (isDone)       // NOT: if (isDone) doCleanup();
  doCleanup();

if (isDone)		  // NOT: if (isDone) doCleanup();
{       
  doCleanup();
}
```
This is for debugging purposes. When writing on a single line, it is not apparent whether the test is really true or not.

### 2.4.4 Executable statements in conditionals must be avoided.
```C++
File* fileHandle = open(fileName, "w");
if (!fileHandle) 
{
  :
}

// NOT:
if (!(fileHandle = open(fileName, "w"))) {
  :
}
```
Conditionals with executable statements are just very difficult to read. This is especially true for programmers new to C/C++. 

## 2.5 Miscellaneous

- Never have lengthy files or functions, this usually indicates a problem in the project structure Optimally functions should be shorter than 300 lines and contain a single functionality which can also be tested externally. Separation in several translation units speeds up compilation time and improves clarity.

- Whenever possible, avoid too many dependencies on external libraries Before adding a dependency to an external library for just a few function calls, think about whether the functionality can't also be provided by an existing dependency or implemented inside your project.

- Add a namespace around your project, this helps integration with other projects. Using namespaces keeps the global namespace clean and avoids ambiguity of names for types, methods etc.

- The use of magic numbers in the code should be avoided. Numbers other than 0 and 1 should be considered declared as named constants instead. If the number does not have an obvious meaning by itself, the readability is enhanced by introducing a named constant instead. A different approach is to introduce a method from which the constant can be accessed. 

- Floating point constants should always be written with decimal point and at least one decimal.
```C++
double total = 0.0;    // NOT:  double total = 0;
double speed = 3.0e8;  // NOT:  double speed = 3e8;

double sum;
:
sum = (a + b) * 10.0;
```
- Floating point constants should always be written with a digit before the decimal point.

double total = 0.5;  // NOT:  double total = .5;

- Functions must always have the return value explicitly listed.
```C++
int getValue()   // NOT: getValue()
{
  :
}
```
If not explicitly listed, C++ implies int return value for functions. A programmer must never rely on this feature, since this might be confusing for programmers not aware of this artifact. 

- goto should not be used. Goto statements violate the idea of structured code. Only in some very few cases (for instance breaking out of deeply nested structures) should goto be considered, and only if the alternative structured counterpart is proven to be less readable.