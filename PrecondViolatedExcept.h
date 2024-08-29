#pragma once

#ifndef PRECONDVIOLATEDEXCEPT_HEADER
#define PRECONDVIOLATEDEXCEPT_HEADER
#include <string>

class PrecondViolatedExcept
{
public:


	PrecondViolatedExcept(const std::string errorMSg);

	std::string GetMsg()const;

	void SetMsg(const std::string errorMsg);

private:

	std::string m_errorMsg;

};


#endif 
