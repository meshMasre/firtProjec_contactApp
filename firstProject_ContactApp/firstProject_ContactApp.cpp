#include <iostream>
#include "Array.h"
using namespace std; 


// Address Class 
class Address
{
private:
	string streetNum;
	string streetName;
	string town;
	string state;

public:
	// Constructor Default and intialized : 
	Address(string streetNum = "10", string streetName = "Arabi_street", string town = "zagazig", string state = "Sharqia")
	{
		this->streetNum = streetName;
		this->streetName = streetName;
		this->town = town;
		this->state = state;
	}

	// Set and Get For All Data Member : 

	void setStreetNum(string streetNum) { this->streetName = streetNum; }
	string getStreetNum() const { return streetNum; }

	void setStreetName(string streetName) { this->streetName = streetName; }
	string getStreetName() const { return streetName; }

	void setTown(string town) { this->town = town; }
	string getTown() const { return town; }

	void setState(string state) { this->state = state;  }
	string getState() const { return state;  }
};
// Contact Calss 
class Contact
{
private : 
	string firstName; 
	string lastName; 
	Address* address; // Composition Address in Contact 
	string* Phone; // Dynamic Array of Phone 
	string* Mail; // Dynamic Array of Mail 
	int phoneSize; // Size of Dynamic PhoneArray
	int mailSize; // Size of Dynamic mailArray 

public: 
	Contact(string firstNmae, string last_name, Address* address, string* phone, string* mail, int phoneSize, int mailSize) :
		firstName(firstName), lastName(lastName), address(address), Phone(phone) , Mail(mail) , phoneSize(phoneSize) , mailSize(mailSize)
	{
		Phone = new string [phoneSize]; 
		// to Enter contents in Phone 
		for (int i = 0; i < phoneSize; i++)
		{
			Phone[i] = phone[i]; 
		}
		Mail = new string[mailSize]; 
		for (int i = 0; i < mailSize; i++)
		{
			Mail[i] = mail[i]; 
		}
	}

	~Contact()
	{
		delete[] Phone; 
		delete[] Mail; 
	}

	// get & set FirstName : 
	void setFirstName(string firstName)
	{
		this->firstName = firstName; 
	}
	string getFirstName() const { return firstName;  }

	// get & set LastName :
	void setLastName(string lastName)
	{
		this->lastName = lastName; 
	}
	string getLastName() const { return lastName;  }

	// Set Classification ( Friend, work , family , other )
	void setClass(string Classchoice)
	{

	}
	// set Favorite 
	bool ifFav(bool favStatus)
	{
		if (favStatus == 1)
		{

		}
		else
		{

		}
	}
	// numbers of Phones 

	// numbers Of Mails 


	// Dispaly
	void Display()
	{
		// setw()
	}

};

// ContactBook Class 


// Main 