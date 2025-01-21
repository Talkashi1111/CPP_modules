#include "RPN.hpp"

RPN::RPN(char *input)
{
	// Apply Deterministic Finite Automaton (DFA) to validate and calc the input
	DFA(input);
}

RPN::RPN(const RPN &rpn)
{
	(void)rpn;
}

RPN &RPN::operator=(const RPN &rpn)
{
	(void)rpn;
	return *this;
}

RPN::~RPN()
{
}

int RPN::DoOp(const int left, const int right, const char op)
{
	switch (op)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		if (right == 0)
			throw std::invalid_argument("Division by zero");
		return left / right;
	default:
		throw std::invalid_argument("Invalid operator");
	}
}

void RPN::DFA(char *str)
{
	std::stack<int> rpn_stack;
	int state = S0;

	while (*str)
	{
		Input input;
		if (std::isdigit(*str))
		{
			input = DIGIT;
			rpn_stack.push(*str - '0');
		}
		else if (std::isspace(*str))
			input = SPACE;
		else if (*str == '+' || *str == '-' || *str == '*' || *str == '/')
		{
			input = OPERATOR;
			if (rpn_stack.size() < 2)
				throw std::invalid_argument("Not enough numbers");
			int right_n = rpn_stack.top();
			rpn_stack.pop();
			int left_n = rpn_stack.top();
			rpn_stack.pop();
			int resault = DoOp(left_n, right_n, *str);
			rpn_stack.push(resault);
		}
		else
			input = OTHER;
		state = static_cast<int>(kStates[state][input]);
		if (state == SINK)
			throw std::invalid_argument("");
		str++;
	}
	if (rpn_stack.size() != 1)
		throw std::invalid_argument("Too many numbers");
	std::cout << rpn_stack.top() << std::endl;
}
