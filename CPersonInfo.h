#ifndef CPERSONINFO_HEADER
#define CPERSONINFO_HEADER

#include <iostream>

class CPersonInfo
{
public:

	CPersonInfo();
	CPersonInfo(const std::string& fname, const std::string& lname, int age = 0, double checking = 0, double savings = 0);

	void	SetFirstName(const std::string& fname);
	void	SetLastName(const std::string& lname);

	void	SetAge(int age);
	void	SetChecking(double checking);
	void	SetSavings(double savings);

	std::string GetFirstName()const;
	std::string GetLastName()const;

	int		GetAge()const;
	double	GetChecking()const;
	double  GetSavings()const;

	bool	operator==(const CPersonInfo& rhs)const;
	bool	operator>(const CPersonInfo& rhs)const;
	bool	operator<(const CPersonInfo& rhs)const;

	friend std::istream& operator>>(std::istream& ins, CPersonInfo& person);

	friend std::ostream& operator<<(std::ostream& outs, const CPersonInfo& person);


private:
	std::string m_fname;
	std::string m_lname;
	int			m_age;
	double		m_checking;
	double		m_savings;

};






#endif
