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

	void setState(string state) { this->state = state; }
	string getState() const { return state; }

	void setAddress(string streetNum, string streetName, string town, string state)
	{
		setStreetNum(streetNum);
		setStreetName(streetName);
		setState(state);
		setTown(town);
	}
	void printAddress()const
	{
		cout << setw(5) << getStreetNum() << ", "
			<< setw(5) << getStreetName() << ", "
			<< setw(5) << getTown() << ", "
			<< setw(20) << getState();

	}
};

// Contact Calss 

class Contact {
private:
	string firstName, lastName, classification;
	int favourite;
	Address* address;
	string* Phone;
	string* Mail;
	int static id; 
	int phoneSize, mailSize, phoneCounter, mailCounter;

public:
	Contact() : address(new Address()), phoneSize(0), mailSize(0), favourite(0), phoneCounter(-1), mailCounter(-1) {
		Phone = new string[phoneSize];
		Mail = new string[mailSize];
	}

	Contact(const Contact& other) :
		firstName(other.firstName),
		lastName(other.lastName),
		classification(other.classification),
		favourite(other.favourite),
		address(new Address(*other.address)),
		phoneSize(other.phoneSize),
		mailSize(other.mailSize),
		phoneCounter(other.phoneCounter),
		mailCounter(other.mailCounter)
	{
		Phone = new string[phoneSize];
		for (int i = 0; i < phoneSize; i++) Phone[i] = other.Phone[i];

		Mail = new string[mailSize];
		for (int i = 0; i < mailSize; i++) Mail[i] = other.Mail[i];
		id++; 
	}

	Contact& operator=(const Contact& other) {
		if (this == &other) return *this;
		delete address;
		delete[] Phone;
		delete[] Mail;

		firstName = other.firstName;
		lastName = other.lastName;
		classification = other.classification;
		favourite = other.favourite;
		address = new Address(*other.address);
		phoneSize = other.phoneSize;
		mailSize = other.mailSize;
		phoneCounter = other.phoneCounter;
		mailCounter = other.mailCounter;

		Phone = new string[phoneSize];
		for (int i = 0; i < phoneSize; i++) Phone[i] = other.Phone[i];

		Mail = new string[mailSize];
		for (int i = 0; i < mailSize; i++) Mail[i] = other.Mail[i];
		id++; 
		return *this;
	}

	~Contact() {
		delete address;
		delete[] Phone;
		delete[] Mail;
	}

	// get & set FirstName : 
	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	string getFirstName() const { return firstName; }

	// get & set LastName :
	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}
	string getLastName() const { return lastName; }

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
		//address->setStreetNum(streetNum); 

		cout << "Street Name : ";
		string streetName;
		cin >> streetName;
		//address->setStreetName(streetName); 

		cout << "Town : ";
		string town;
		cin >> town;
		//address->setTown(town);

		cout << "State : ";
		string state;
		cin >> state;
		address->setAddress(streetNum, streetName, town, state); 
		//address->setAddress(streetNum, streetName, town, state);


	}
	// Dispaly
	void printHeader()
	{
		cout << "First Name "
			<< setw(20) << "Last Name "
			<< setw(20) << "Classification "
			<< setw(20) << "Favourite "
			<< setw(20) << "Address "
			<< setw(57) << "Phone Number/s "
			<< setw(28) << "Mails" << endl;


	}
	void displayContactDetails()
	{
		cout << setw(20) << left << getFirstName();
		cout << setw(20) << left << getLastName();
		cout << setw(20) << left << getClass();
		cout << setw(20) << left << getFav();
		address->printAddress();

		// Display phone numbers

		for (int i = 0; i < phoneSize; i++)
		{
			if (i == phoneSize - 1)
			{
				cout << setw(30) << left << getPhoneNumbers();
			}
			else
			{
				cout << left << getPhoneNumbers() << " , ";
			}
			cout << setw(28);
		}
		// Display emails

		for (int i = 0; i < mailSize; i++)
		{
			if (i == mailSize - 1)
			{
				cout << getMails();
			}
			else
			{
				cout << getMails() << " , ";
			}
		}

		cout << endl;
	}

};

int Contact::id = 0;
// ContactBook Class 
class contactBook
{
private: 
	DArray<Contact> obj; 

public: 
	// Add New Contact 
	void addNewContact(Contact newCon)
	{
		obj.append(newCon);
	}

	// Search By lastName 
	void searchByLastName(string lastName)
	{
		for (int i = 0; i < obj.getSize(); i++)
		{
			if (obj[i].getLastName() == lastName)
			{
				obj[i].displayContactDetails(); 
			}
		}

	}
	// Search By Classification (friend , work , family , other )
	void searchByClas(string classification)
	{
		for(int i = 0 ; i < obj.getSize(); i++)

			if (obj[i].getClass() == classification)
			{
				obj[i].displayContactDetails(); 
		    }
		
	}
	// Print All Contacts	
	void printAllContacts()
	{
		if (obj.getSize() == 0) {
			cout << "No contacts to display." << endl;
			return;
		}
		obj[0].printHeader();  // Print the header once
		for (int i = 0; i < obj.getSize(); i++) {
			obj[i].displayContactDetails();
		}
	}

	// Print Fav Contacts 
	bool printFavContacts()
	{
		bool hasFavContacts = false;
		for (int i = 0; i < obj.getSize(); i++)
		{
			if (obj[i].getFav() == 1) {
				obj[i].displayContactDetails();
				hasFavContacts = true;
			}
		}
		if (!hasFavContacts) {
			cout << "No favorite contacts found." << endl;
		}
		return hasFavContacts;
	}

	// Delete Contact 
	void DeleteContact(int index)
	{
		obj.Delete(index); 
	}
	// Update Contact 
	void update(Contact con, int index)
	{
		obj.insert(con, index); 
	}
	// Reverse Contacts book 
	void reverseContactBook()
	{
		obj.reverse(); 
	}
};

// Some Helper Function : 

int ReadNumberInRange(int From, int To)
{
	int Number;
	do
	{
		cout << "Enter Your Choice : "; 
		cin >> Number;
	} while (Number > To || Number < From);
	return Number;
}

int DisplayMenu()
{
	cout << "----------------------------------------------------------------------------------------\n";
	cout << "                                      Contact book menu:\n";
	cout << "========================================================================================\n";
	cout << "     1. Add new contact\n";
	cout << "     2. Search by last name (Enter last name correctly)\n";
	cout << "     3. Search by classification (Enter classification correctly)\n";
	cout << "     4. Print all contacts\n";
	cout << "     5. Print favorite contacts\n";
	cout << "     6. Save to file\n";
	cout << "     7. Load from file\n";
	cout << "     8. Delete contact\n";
	cout << "     9. Update contact information\n";
	cout << "     10. Reverse contact book\n";
	cout << "     11. Exit\n";
	cout << "----------------------------------------------------------------------------------------\n";
	return ReadNumberInRange(1,11);
}

void makeChoice(int choice)
{
	

}

// Main 
int main()
{
	Contact con;
	contactBook contact;
	string lastName, Classification;

	int order = 0;
	do
	{
		order = DisplayMenu(); 
		makeChoice(order); 

		switch (order)
		{
		case 1:
			system("cls");
			con.readContactDetails();
			contact.addNewContact(con);
			DisplayMenu();

			break;
		case 2:
			system("cls");

			cout << "Enter Last Name In Correct Form : ";
			cin >> lastName;
			contact.searchByLastName(lastName);
			break;

		case 3:
			system("cls");
			cout << "Enter Classification In Correct From (friend , family , work , other ) : ";
			cin >> Classification;
			contact.searchByClas(Classification);
			break;

		case 4:
			system("cls");
			contact.printAllContacts();
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		case 9:
			break;

		case 10:
			break;

		case 11:
			break;

		case 12:
			break;

		default:
			break;
		}
		
	} while (order != 0); 
	return 0;
}
