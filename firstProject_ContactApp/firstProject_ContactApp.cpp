#include <iostream>
#include "Array.h"
#include <iomanip>
#include <string>
using namespace std; 


//<<<<<<< HEAD
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
		this->streetNum = streetNum;
		this->streetName = streetName;
		this->town = town;
		this->state = state;
	}

	// Set and Get For All Data Member : 

	void setStreetNum(string streetNum) { this->streetNum = streetNum; }
	string getStreetNum() const { return streetNum; }

	void setStreetName(string streetName) { this->streetName = streetName; }
	string getStreetName() const { return streetName; }

	void setTown(string town) { this->town = town; }
	string getTown() const { return town; }

	void setState(string state) { this->state = state;  }
	string getState() const { return state;  }

	void setAddress(string streetNum, string streetName, string town, string state)
	{
		setStreetNum(streetNum);
		setStreetName(streetName);
		setState(state);
		setTown(town);
	}
	void printAddress()
	{
		cout
		 << getStreetNum() << ", " << getStreetName() << ", " << getTown()
		 << ", " << getState(); 
	}
};

// Contact Calss 
class Contact
{
private : 
	string firstName; 
	string lastName; 
	string classification; 
	int favourite; 
	Address* address; // Composition Address in Contact 
	string* Phone; // Dynamic Array of Phone 
	string* Mail; // Dynamic Array of Mail 
	static int id;
	int phoneSize; // Size of Dynamic PhoneArray
	int phoneCounter; 
	int mailSize; // Size of Dynamic mailArray 
	int mailCounter; 

public: 
	 //Default Constructor 
	Contact() : address(new Address())
	{
		firstName = "Team"; 
		lastName = "Project"; 
		classification = "family"; 
		phoneSize = 0; 
		mailSize = 0; 
		phoneCounter = -1;
		mailCounter = -1; 
		favourite = 0; 
		Phone = new string[phoneSize]; 
		Mail = new string[mailSize]; 
		id++;
	}
	Contact(string firstName, string last_name, Address* address, string* phone, string* mail, int phoneSize, int mailSize, int phoneCounter, int mailCoutner, int favourite) :
		firstName(firstName), lastName(lastName), address(address), Phone(phone), Mail(mail), phoneSize(phoneSize), mailSize(mailSize), 
		phoneCounter(phoneCounter) , mailCounter(mailCounter) , favourite(favourite)
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
		id++; 
	}

	~Contact()
	{
		delete address; 
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
		classification = Classchoice; 
	}
	string getClass()const { return classification; }
	// set & get Favorite 
	void setFav(int favStatus)
	{
		if (favStatus == 1)
		{
			favourite = 1; 
		}
		else 
		{
			favourite = 0; 
		}
	}
	int getFav()
	{
		return favourite; 
	}
  
	
	
	Address getAddress()
	{
	}

	// Set  and Get Phone numbers : 

	void setPhoneNumbers(int phoneSize)
	{
		Phone = new string[phoneSize]; 
		for (int i = 0; i < phoneSize; i++)
		{
			cout << "Phone #" << i + 1 << " : "; 
			cin >> Phone[i]; 
		}
	}
	string getPhoneNumbers()
	{
		phoneCounter++; 
		return Phone[phoneCounter];
	}
	
	// Set and Get Mails 
	void setMails(int mailSize)
	{
		Mail = new string[mailSize]; 
		for (int i = 0; i < mailSize; i++)
		{
			cout << "Mail #" << i + 1 << " : "; 
			cin >> Mail[i]; 
		}
	}

	string getMails()
	{
		mailCounter++;
		return Mail[mailCounter]; 

	}

	void readContactDetails()
	{
		cout << "\t\t\t -------------- Add New Contact ------------- \n "; 

		cout << "First Name : "; 
		cin >> firstName; 
		setFirstName(firstName); 

		cout << "Last Name : "; 
		cin >> lastName; 
		setLastName(lastName); 
		

		cout << "Class (friend , work , family , other ) : "; 
		cin >> classification; 
		setClass(classification); 

		cout << "Set as Favourite (Press 1 (fav) or  0 (Not fav)) : "; 
		cin >> favourite; 
		setFav(favourite); 
		

		cout << "How Many Numbers ?: "; 
		cin >> phoneSize;
		setPhoneNumbers(phoneSize);

		cout << "How Many Mails ?: "; 
		cin >> mailSize; 
		setMails(mailSize); 

		cout << "\t\t :: Enter Address Details :: \n"; 
		cout << "Street Number : "; 
		string streetNum; 
		cin >> streetNum; 

		cout << "Street Name : "; 
		string streetName;
		cin >> streetName; 

		cout << "Town : "; 
		string town; 
		cin >> town;

		cout << "State : "; 
		string state; 
		cin >> state;  

		address->setAddress(streetNum, streetName, town, state); 


	}
	// Dispaly
	
	void displayContacDetails()
	{
	// setw()
		cout << setw(20) << setfill(' ') << left << "ID" << setw(20) << "FirstName " << setw(20) << "LastName " << setw(20) << "Classification " << setw(20) << "Favourite ";
		cout << setw(20) << setfill(' ') << "Address "<< setw(40) << left << "Phone Number/s " << setw(20) << left<< "Mails";
		cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; 
		cout << setw(20) << setfill(' ') << left << id;
		cout << setw(20) << setfill(' ')<< left <<   getFirstName() ;
		cout << setw(20) << setfill(' ')<< left <<   getLastName() ;
		cout << setw(20) << setfill(' ')<< left << getClass();
		cout << setw(20) << setfill(' ')<< left << getFav(); 
		address->printAddress(); 
		cout << setw(40) << left; 
		for (int i = 0; i < phoneSize; i++)
		{
			if (i == phoneSize - 1)
			{
				cout <<  getPhoneNumbers() ;
			}	
			else
			{	
				cout << getPhoneNumbers() << ", ";

			}
			
		}
		cout << setw(40) << left;
		for (int i = 0; i < mailSize; i++)
		{
			if (i == mailSize - 1)
			{
				cout << setw(20) << left << getMails();
			}
			else
			{
				cout << setw(20) << left << getMails() << ", ";

			}
			
		}

	}

};

int Contact::id = 0; 
// ContactBook Class 
class contactBook
{
private : 
	Array<Contact> ContactArray[10];



};
// Main 
int main()
{
	Address address; 
	Contact contact;	contact.readContactDetails(); 
	contact.displayContacDetails(); 

}