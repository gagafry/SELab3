1. Purpose 

1.1 Definitions: 

SRS: Software Requirement Specification. 

Function Calculator: The specific console application developed to solve the individual mathematical task. 

Robust Validation: A mechanism ensuring user input consists only of valid numeric characters to prevent program crashes. 

1.2 System Overview: This is a C++ console application designed to calculate function values. Unlike simple calculators, this system supports two distinct modes of operation: calculating a range of values (tabulated output) and calculating a single point value. The system features advanced input validation using string streams to prevent crashes from non-numeric input. 

1.3 References: Methodical recommendation to laboratory practice made by Melnyk Karina Volodymyrivna in KhPI Kharkiv in 2025. 

2. Overall Description 

2.1 Product Perspective 

System Interfaces: The application runs as a standard executable within the Windows Command Prompt. 

User Interfaces: 

The interface is text-based (Console). 

Navigation is controlled by entering a number and pressing the [Enter] key (using getline). 

The system includes a "Welcome Screen" and a cyclic "Main Menu". 

Output is formatted using fixed width columns to ensure table alignment. 

Hardware Interfaces: Standard PC Input/Output (Keyboard/Monitor). 

Software Interfaces: Requires Windows OS (due to system("cls") commands). 

2.2 Product Functions 

Robust Input: Parsing strings to ensure inputs are integers or doubles, strictly rejecting text characters. 

Mode Selection: Allowing the user to choose between "Range Calculation" and "Single Value Calculation". 

Math Processing: Computing Y based on complex conditional formulas (involving powers and nested loops). 

Tabulation: Dynamic generation of a results table. 

2.3 User Characteristics The user is expected to be a student or engineer capable of following on-screen text instructions and understanding mathematical ranges. 

2.4 Constraints 

Language: C++. 

Input Method: getline and stringstream must be used for stability instead of simple cin. 

3. Specific Requirements 

3.1 External Interface Requirements 

Startup: The system must display a welcome banner identifying the program as "Function Calculator (Lab 2)" and wait for the user to press Enter. 

Menu: The main menu must display three clear options: 

Enter Parameters & Calculate Range 

Calculate Single 'x' Value 

Exit 

Error Feedback: If the user enters invalid data (e.g., text instead of a number), the system must print: "Error: Wrong data type... Please enter a number" and repeat the prompt immediately. 

3.2 Functional Requirements 

3.2.1 Input Logic: 

The system must validate that n is a positive integer (n > 0). 

The system must validate that step > 0. 

For range calculations, the system must ensure start (a) <= end (b). If a > b, it must display an error and request the range again. 

3.2.2 Calculation Logic: The system calculates Y based on the following rules: 

Check 1: If x = -1, return Error (Division by zero protection). 

Condition A (x < 0): y = Sum(from i=2 to n) of [(i - 3 + x)^2] minus 5x. 

Condition B (x >= 0): First, calculate Denominator = 2 * (1 + x)^2. If Denominator is 0, return Error. Otherwise: y = Sum(from i=0 to n) of [ Product(from j=1 to n-1) of ((i + j) / Denominator) ]. 

3.2.3 Output Logic: 

Mode 1 (Range): The system must print a table header with columns # | x | y |. Values must be aligned and rounded to 4 decimal places. 

Mode 2 (Single): The system must print a simple text result: "For n=... and x=... the result y = ...". 

3.2.4 Exit: 

When "Exit" is chosen, the system must ask "Are you sure you want to exit? (Y/N)". 

The system must accept 'y' or 'Y' to quit, and 'n' or 'N' to return to the menu. 

3.3 Performance Requirements 

Input parsing should happen instantly. 

Calculation for typical values of n (up to 1000) should appear without noticeable delay. 

3.4 Software System Attributes 

Reliability: The application must not crash on invalid input types (letters/symbols). 

Usability: The interface must clear the screen (cls) between transitions to keep the view clean. 
