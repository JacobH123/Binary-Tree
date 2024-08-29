#include <iostream>
#include <string>
#include <iomanip>
#include "CPersonInfo.h"

using namespace std;


CPersonInfo::CPersonInfo()
{
	m_fname = "";
	m_lname = "";
	m_age = 0;
	m_checking = 0;
	m_savings = 0;
}


void CPersonInfo::SetFirstName(const string& fname)
{
	m_fname = fname;

}

void CPersonInfo::SetLastName(const string& lname)
{
	m_lname = lname;
}


void CPersonInfo::SetAge(int age)
{
	m_age = age;
}

void CPersonInfo::SetChecking(double checking)
{
	m_checking = checking;
}

void CPersonInfo::SetSavings(double savings)
{
	m_savings = savings;
}

string CPersonInfo::GetFirstName()const
{
	return m_fname;
}


string CPersonInfo::GetLastName()const
{
	return m_lname;
}

int CPersonInfo::GetAge()const
{
	return m_age;
}

double  CPersonInfo::GetChecking()const
{
	return m_checking;
}

double CPersonInfo::GetSavings()const
{
	return m_savings;
}

bool CPersonInfo::operator==(const CPersonInfo& rhs)const
{
	return (m_fname == rhs.m_fname) && (m_lname == rhs.m_lname) && (m_age == rhs.m_age) && (m_checking == rhs.m_checking)
		&& (m_savings == rhs.m_savings);
}

bool CPersonInfo::operator>(const CPersonInfo& rhs)const
{
	return (m_age > rhs.m_age);
}

bool CPersonInfo::operator<(const CPersonInfo& rhs)const
{
	return (m_age < rhs.m_age);
}

std::istream& operator>>(std::istream& ins, CPersonInfo& person)
{
	string fname, lname;
	int age;
	double checking, savings;
	ins >> fname >> lname >> age >> checking >> savings;
	person.SetFirstName(fname);
	person.SetAge(age);
	person.SetChecking(checking);
	person.SetSavings(savings);

	return ins;
}
std::ostream& operator<<(std::ostream& outs, const CPersonInfo& person)
{
	outs << std::setw(15) << std::left << person.GetFirstName() 
		<< std::setw(15) << std::left << person.GetLastName() 
		<< std::setw(5) << std::right << person.GetAge() 
		<< std::setw(15) << std::right << "$" 
		<< std::fixed<<std::setprecision(2)<< person.GetChecking()
		<< std::setw(15) << std::right << "$" 
		<< std::fixed << std::setprecision(2) << person.GetSavings();
	return outs;
}
