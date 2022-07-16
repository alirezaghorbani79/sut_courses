#include <iostream>
#include <exception>


using namespace std;


class organization
{
public:
	organization(const string& firstName, const string& lastName, const string& socialSecurityNumber, int hWork = 1)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->socialSecurityNumber = socialSecurityNumber;
		this->hWork = hWork;
	}
	virtual ~organization() {};
	//===========================================// set functions //===========================================
	void setFirstName(const string firstName)
	{
		this->firstName = firstName;
	}
	void setLastName(const string lastName)
	{
		this->lastName = lastName;
	}
	void setSocialSecurityNumber(const string socialSecurityNumber)
	{
		this->socialSecurityNumber = socialSecurityNumber;
	}
	void setHwork(int hWork)
	{
		this->hWork = hWork;
		//this->hWork = ceil(hWork);
	}
	//===========================================// get functions //===========================================
	string getFirstName() const
	{
		return firstName;
	}
	string getLastName() const
	{
		return lastName;
	}
	string getSocialSecurityNumber() const
	{
		return socialSecurityNumber;
	}
	int getHwork() const
	{
		return hWork;
	}
	//===========================================// other functions //===========================================
	virtual double totalPayment() const = 0;
	virtual void print() const
	{
		cout << getFirstName() << ' ' << getLastName() << endl << "Social Security Number: " << getSocialSecurityNumber() << endl;
		cout << "Hour of Work: " << getHwork() << endl;
	}

private:
	string firstName, lastName, socialSecurityNumber;
	int hWork;
};

class officialEmployeeOrganization : public organization
{
public:
	officialEmployeeOrganization(const string& firstName, const string& lastName, const string& socialSecurityNumber, int hWork, const string organ) :
		organization(firstName, lastName, socialSecurityNumber, hWork)
	{
		setOrgan(organ);
	}
	~officialEmployeeOrganization() {};
	//===========================================// set functions //===========================================
	void setOrgan(string organ)
	{
		this->organ = organ;
	}
	//===========================================// get functions //===========================================
	string getOrgan() const
	{
		return organ;
	}
	//===========================================// other functions //===========================================
	double totalPayment() const
	{
		return organization::totalPayment();
	}
	void print() const
	{
		cout << "Official Employee Organ: ";
		organization::print();
		cout << "Employee Organ: " << getOrgan() << endl;
	}
private:
	string organ;
};


class HourlyEmployeeOrganization : public organization
{
public:
	HourlyEmployeeOrganization(const string& firstName, const string& lastName, const string& socialSecurityNumber, int hWork, const string organ) :
		organization(firstName, lastName, socialSecurityNumber)
	{
		setOrgan(organ);
	}
	~HourlyEmployeeOrganization() {};
	//===========================================// set functions //===========================================
	void setOrgan(string organ)
	{
		this->organ = organ;
	}
	//===========================================// get functions //===========================================
	string getOrgan() const
	{
		return organ;
	}
	//===========================================// other functions //===========================================
	double totalPayment() const
	{
		return organization::totalPayment();
	}
	void print() const
	{
		cout << "Hourly Employee Organ: ";
		organization::print();
		cout << "Employee Organ: " << getOrgan() << endl;
	}

private:
	string organ;
	int hWork;
};

class salariedEmployee : public officialEmployeeOrganization
{
public:
	salariedEmployee(const string& firstName, const string& lastName, const string& socialSecurityNumber, int hWork, const string organ, double monthlySalary = 0) :
		officialEmployeeOrganization(firstName, lastName, socialSecurityNumber, hWork, organ)
	{
		setMonthlySalary(monthlySalary);
	}
	~salariedEmployee() {};
	//===========================================// set functions //===========================================
	void setMonthlySalary(double monthlySalary)
	{
		if (monthlySalary >= 0)
		{
			this->monthlySalary = monthlySalary;
		}
		else
		{
			throw invalid_argument("Monthly salary must be grater than 0");
		}
	}
	//===========================================// get functions //===========================================
	int getHwork() const
	{
		officialEmployeeOrganization::getHwork();
	}
	double getMonthlySalary() const
	{
		if (getHwork() <= 140)
			return monthlySalary;
		else if (getHwork() > 140)
		{
			float wage = 0.5;
			return monthlySalary + (140 * wage + (getHwork() - 140) * (wage * 1.5));
		}
	}
	//===========================================// other functions //===========================================
	double totalPayment() const
	{
		return getMonthlySalary();
	}
	void print() const
	{
		cout << "Salaried Employee: ";
		organization::print();
		cout << "Monthly Salary: " << getMonthlySalary() << endl;
	}
private:
	double monthlySalary;
};

class commissionEmployee : public HourlyEmployeeOrganization
{
public:
	commissionEmployee(const string& firstName, const string& lastName, const string& socialSecurityNumber, int hWork, const string organ, double commissionRate = 0) :
		HourlyEmployeeOrganization(firstName, lastName, socialSecurityNumber, hWork, organ)
	{
		setCommissionRate(commissionRate);
	}
	~commissionEmployee() {};
	//===========================================// set functions //===========================================
	void setCommissionRate(double commissionRate)
	{
		if (commissionRate > 0)
		{
			this->commissionRate = commissionRate;
		}
		else
		{
			throw invalid_argument("Commission Rate must grater than 0");
		}
	}
	//===========================================// get functions //===========================================
	double getCommissionRate() const
	{
		return commissionRate;
	}
	//===========================================// other functions //===========================================
	double totalPayment() const
	{
		return getCommissionRate() * HourlyEmployeeOrganization::getHwork();
	}
	void print() const
	{
		cout << "Commission Employee: ";
		HourlyEmployeeOrganization::print();
		cout << "  Commission Rate: " << getCommissionRate() << endl;
	}

private:
	double commissionRate;
};


int main()
{
	cout << "hello world" << endl;
}