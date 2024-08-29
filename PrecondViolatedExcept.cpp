#include<iostream>
#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string errorMsg)
{
	m_errorMsg = errorMsg;
}


std::string PrecondViolatedExcept::GetMsg()const
{
	return m_errorMsg;
}

void PrecondViolatedExcept::SetMsg(const std::string erorrMsg)
{
	m_errorMsg = erorrMsg;
}