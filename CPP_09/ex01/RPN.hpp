#pragma once

#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <stdexcept>

enum State
{
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	SINK,
};

enum Input
{
	DIGIT,
	SPACE,
	OPERATOR,
	OTHER,
};

/*
DFA State Diagram:

States: S0 (Start), S1, S2, S3, S4, S5, SINK (Invalid)

SPACE                           SPACE                           SPACE
+--+                            +--+                            +--+
|  |                            |  |                            |  |
+==v            +==+            +==v            +--+            +--v            +==+
║S0║---DIGIT--->║S1║---SPACE--->║S2║---DIGIT--->|S3|---SPACE--->|S4|----OP----->║S5║
+==+            +==+            +==+            +--^            +--^            +==+
|               |               |               |  |            || |            |  |
|OP/OTHER       |               |OP/OTHER       |  +-- DIGIT ---+| +--- SPACE --+  |
|               |OP/OTHER/DIGIT |               |                |                 |
|               |               |               |OP/OTHER/DIGIT  |OTHER            |OP/OTHER/DIGIT
|               |               |               |                |                 |
+---------------+---------------+----> SINK <---+----------------+-----------------+

Legend:
- DIGIT: Numerical input ('0'-'9')
- SPACE: Whitespace input (' ', '\t', '\n', '\r', '\v', '\f')
- OPERATOR: '+', '-', '*', '/'
- OTHER: Invalid character
*/
const char kStates[7][4] = {{S1, S0, SINK, SINK},
							{SINK, S2, SINK, SINK},
							{S3, S2, SINK, SINK},
							{SINK, S4, SINK, SINK},
							{S3, S4, S5, SINK},
							{SINK, S4, SINK, SINK},
							{SINK, SINK, SINK, SINK}};

class RPN
{
public:
	RPN(char *input);
	RPN(const RPN &rpn);
	RPN &operator=(const RPN &rpn);
	~RPN();

private:
	void DFA(char *str);
	int DoOp(const int left, const int right, const char op);
};
