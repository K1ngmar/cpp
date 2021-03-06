
#include "PrintInput.hpp"
#include <stdlib.h>
#include <iostream>
#include <iomanip>


static bool	isCharLitteral(char *str)
{
	if (str[1] == '\0' && (str[0] <= '0' || str[0] >= '9'))
		return (true);
	return (false);
}

static int getDecimalLength(char *str)
 {
	int i = 0;

	while (str[i] && str[i] != '.')
		i++;
	int dp = i + 1;
	while (str[dp] && str[dp] >= '0' && str[dp] <= '9')
		dp++;
	if (dp == i + 1)
		return (1);
	return dp - i - 1;
 }

PrintInput::PrintInput(char *str)
{
	this->p_input = str;

	if (isCharLitteral(str)) {
		p_nb = static_cast<int>(str[0]);
		p_dnb = static_cast<double>(str[0]);
	} else {
	this->p_nb = atoi(str);
	this->p_dnb = atof(str);
	}
}

PrintInput::~PrintInput()
{
}

PrintInput::PrintInput(const PrintInput &copy)
{
	this->p_input = copy.p_input;
	this->p_nb = copy.p_nb;
	this->p_dnb = copy.p_dnb;
}

PrintInput & PrintInput::operator = (const PrintInput &s)
{
	this->p_input = s.p_input;
	this->p_nb = s.p_nb;
	this->p_dnb = s.p_dnb;
	return *this;
}

bool	PrintInput::isLiteral() const
{
	if (!std::strcmp("nan", this->p_input) || !std::strcmp("nanf", this->p_input) ||
			!std::strcmp("-inff", this->p_input) || !std::strcmp("+inff", this->p_input) ||
			!std::strcmp("-inf", this->p_input) || !std::strcmp("+inf", this->p_input) || 
			!std::strcmp("inf", this->p_input) || !std::strcmp("inff", this->p_input))
		return true;
	else
		return false;
}

bool	PrintInput::isValidInput() const
{
	int start = 0;

	if (isCharLitteral(this->p_input))
		return true;
	while ((this->p_input[start] >= 9 && this->p_input[start] <= 13) || this->p_input[start] == ' ')
		start++;
	if (this->p_input[start] == '+' || this->p_input[start] == '-')
		start++;
	if (this->p_input[start] >= '0' && this->p_input[start] <= '9')
		return true;
	return false;
}

void	PrintInput::PrintNumbers() const
{
	std::cout << std::setprecision(getDecimalLength(this->p_input)) << std::fixed;
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}


void	PrintInput::printChar() const
{
	std::cout << "char: ";
	if (isLiteral())
		std::cout << "impossible" << std::endl;
	else if (std::isprint(p_nb) == true)
		std::cout << static_cast<char>(p_nb) << std::endl;
	else
		std::cout << "Non displayble" << std::endl;
}

void	PrintInput::printInt() const
{
	std::cout << "Int: ";
	if (isLiteral() || isValidInput() == false || this->p_dnb > static_cast<double>(INT_MAX) || this->p_dnb < static_cast<double>(INT_MIN))
		std::cout << "impossible" << std::endl;
	else
		std::cout << p_nb << std::endl;
}



void	PrintInput::printFloat() const
{
	std::cout << "Float: ";
	if ((isLiteral() == false && isCharLitteral(this->p_input) == false && isValidInput() == false) || this->p_dnb > (std::numeric_limits<float>::max()) || this->p_dnb < -(std::numeric_limits<float>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(p_dnb) << "f" << std::endl;
}

void	PrintInput::printDouble() const
{
	std::cout << "Double: ";
	if (isValidInput() == false && !isLiteral())
		std::cout << "impossible" << std::endl;
	else	
		std::cout << p_dnb << std::endl;
}
