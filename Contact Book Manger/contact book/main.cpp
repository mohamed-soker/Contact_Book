#include <iostream>
#include <fstream>
#include <iomanip>
class Contact {
public:
    std::string firstName, lastName, classification;
    std::string phone1,phone2, email1,email2;
    std::string streetnum, streetname, town, state;
    bool isFavorite = false;
   /*void display() const {
    std::cout << std::left;
    std::cout << "-------------------------------------------------------------------------------\n";

    std::cout << std::setw(12) << "FName"
              << std::setw(12) << "LName"
              << std::setw(20) << "Classification"
              << std::setw(12) << "Phone"
              << std::setw(12) << "Phone2"
              << std::setw(20) << "Email|"
              << std::setw(20) << "Email2"
              << std::setw(15) << "Street Number"
              << std::setw(20) << "Street Name"
              << std::setw(12) << "Town"
              << "State| \n";

    std::cout << "- - - - - - - - - - - - - - - - - -- - - -- - - - - -- - - - - - -- - - - - - -- - - - - - - - - - -- - - - -- - - - -- - - - - -- - - - - - -- - - \n";

    std::cout << std::setw(12) << firstName
              << std::setw(12) << lastName
              << std::setw(20) << classification
              << std::setw(12) << phone1
              << std::setw(12) << phone2
              << std::setw(20) << email1
              << std::setw(20) << email2
              << std::setw(15) << streetnum
              << std::setw(20) << streetname
              << std::setw(12) << town
              << state << "\n";
}*/
void display() const {
        std::cout << "-------------------------- \n"
                  << "Name: " << firstName << " " << lastName << "\n"
                  << "Classification: " << classification << "\n"
                  << "Phone 1: " << phone1 << "\n";
        if (!phone2.empty()) {
            std::cout << "Phone 2: " << phone2 << "\n";}
            std::cout << "Email 1: " << email1 << "\n";
        if (!email2.empty()) {
            std::cout << "Email 2: " << email2 << "\n";}
            std::cout << "Street Number: " << streetnum << "\n"
                  << "Street Name: " << streetname << "\n"
                  << "Town: " << town << "\n"
                  << "State: " << state << "\n"
                  << "fav: " ;
                  if(isFavorite){
                  std::cout<<"1"<<"\n";}
                  else
                  std::cout<<"0";
    }


};

class ContactBook {
private:
    Contact* contacts;
    int size;
    int capacity;

    void expandCapacity() {
        capacity *= 2;
        Contact* newContacts = new Contact[capacity];
        for (int i = 0; i < size; ++i) {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
    };

public:
    ContactBook() : size(0), capacity(10) {
        contacts = new Contact[capacity];
    }

    ~ContactBook() {
        delete[] contacts;
    }

    void addContact() {
        if (size == capacity) {
            expandCapacity();
        }

        Contact contact;
        std::cout <<"                                   ---add a new contact--- \n";
        std::cout << "Enter First Name: ";
        std::cin >> contact.firstName;
        std::cout << "Enter Last Name: ";
        std::cin >> contact.lastName;
        std::cout << "Enter Classification (friend, work, family, other): ";
        std::cin >> contact.classification;
        std::cout << "how many numbers he has: (1 or 2) ";
        int y;
        std::cin>>y;
        std::cout << "Enter Phone: ";
        std::cin >> contact.phone1;

        if (y == 2) {
        std::cout << "Enter Phone 2: ";
        std::cin >> contact.phone2;
    }
        std::cout<< "how many emails he has: (1 or 2)";
        int z;
        std::cin>>z;
        std::cout << "Enter Email: ";
        std::cin >> contact.email1;
        if (z == 2){
            std::cout << "Enter Email2: ";
            std::cin >> contact.email2;
        }
        std::cout << "      ::Enter Address details::\n";
        std::cout << "Street Number: ";
        std::cin >> contact.streetnum;
        std::cout << "Street Name: ";
        std::cin >> contact.streetname;
        std::cout << "Town: ";
        std::cin >> contact.town;
        std::cout << "State: ";
        std::cin >> contact.state;
        std::cout << "Press 1 to add to favorites: ";
        int x;
        std::cin >> x;
        if (x == 1) {
            contact.isFavorite = true;
        }
        contacts[size++] = contact;
        std::cout << "Contact added successfully.\n";
    }

    void searchByLastName() {
        std::string lastName;
        std::cout << "Enter Last Name: ";
        std::cin >> lastName;

        for (int i = 0; i < size; ++i) {
            if (contacts[i].lastName == lastName) {
                contacts[i].display();
                return;
            }
        }
        std::cout << "No contact found with last name " << lastName << ".\n";
    }

    void listByClassification() {
        std::string classification;
        std::cout << "Enter Classification: ";
        std::cin >> classification;

        for (int i = 0; i < size; ++i) {
            if (contacts[i].classification == classification) {
                contacts[i].display();
            }
        }
    }

    void printAllContacts() {
        for (int i = 0; i < size; ++i) {
            contacts[i].display();
                std::cout<<"-------------------------- \n";

        }
    }
    void printfav() {
        for (int i = 0; i < size; ++i) {
            if (contacts[i].isFavorite) {
                contacts[i].display();
                std::cout << "--------------------\n";
            }
        }
    }
    void saveToFile() {
        std::ofstream file("contacts.txt");
        for (int i = 0; i < size; ++i) {
            file << contacts[i].firstName << " " << contacts[i].lastName << "\n"
                 << contacts[i].classification << "\n"
                 << contacts[i].phone1 << "\n"
                 << contacts[i].email1 << "\n"
                 << contacts[i].email2 << "\n"
                 << contacts[i].streetnum << "\n"
                 << contacts[i].streetname << "\n"
                 << contacts[i].town << "\n"
                 << contacts[i].state << "\n"
                 << contacts[i].isFavorite << "\n";
        }
        file.close();
        std::cout << "Contacts saved to file.\n";
    }

    void loadFromFile() {
        std::ifstream file("contacts.txt");
        Contact contact;
        size = 0;
        while (file >> contact.firstName >> contact.lastName >> contact.classification >> contact.phone1 >> contact.email1 >> contact.email2
                     >> contact.streetnum >> contact.streetname >> contact.town >> contact.state >>contact.isFavorite) {
            if (size == capacity) {
                expandCapacity();
            }
            contacts[size++] = contact;
        }
        file.close();
        std::cout << "Contacts loaded from file.\n";
    }

    void deleteContact() {
        std::string lastName;
        std::cout << "Enter Last Name of Contact to Delete: ";
        std::cin >> lastName;

        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (contacts[i].lastName == lastName) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < size - 1; ++i) {
                contacts[i] = contacts[i + 1];
            }
            --size;
            std::cout << "Contact deleted.\n";
        } else {
            std::cout << "No contact found with last name " << lastName << ".\n";
        }
    }

    void updateContact() {
        std::string lastName;
        std::cout << "Enter Last Name of Contact to Update: ";
        std::cin >> lastName;

        for (int i = 0; i < size; ++i) {
            if (contacts[i].lastName == lastName) {
                std::cout << "Updating contact.\n";
                std::cout << "Enter new First Name: ";
                std::cin >> contacts[i].firstName;
                std::cout << "Enter new Last Name: ";
                std::cin >> contacts[i].lastName;
                std::cout << "Enter new Classification: ";
                std::cin >> contacts[i].classification;
                int y;
                std::cout << "How many phone numbers do you want to add (1 or 2)? ";
                std::cin >> y;
                std::cout << "Enter Phone 1: ";
                std::cin >> contacts[i].phone1;
                if (y == 2) {
                    std::cout << "Enter Phone 2: ";
                    std::cin >> contacts[i].phone2;
                } else {
                    contacts[i].phone2 = "";
                }
                int z;
                std::cout << "How many email addresses do you want to add (1 or 2)? ";
                std::cin >> z;
                std::cout << "Enter Email 1: ";
                std::cin >> contacts[i].email1;
                if (z == 2) {
                    std::cout << "Enter Email 2: ";
                    std::cin >> contacts[i].email2;
                } else {
                    contacts[i].email2 = "";
                }
                int x;
                std::cout << "Press 1 to add to favorites, 0 to remove from favorites: ";
                std::cin >> x;
                if (x == 1) {
                    contacts[i].isFavorite = true;
                } else {
                    contacts[i].isFavorite = false;
                }
                std::cout << "Contact updated.\n";
                return;
            }
        }
        std::cout << "No contact found with last name " << lastName << ".\n";
    }

    void reverseContacts() {
        for (int i = 0; i < size / 2; ++i) {

            Contact temp = contacts[i];
            contacts[i] = contacts[size - i - 1];
            contacts[size - i - 1] = temp;
        }
        std::cout << "Contacts reversed successfully.\n";
    }

    void displayMenu() {
        std::cout <<"                                 ============================== \n"
                  <<"                                 contacts book menu \n"
                  <<"                                 ------------------------------ \n"
                  << "                                 1. Add a New Contact\n"
                  << "                                 2. Search by Last Name\n"
                  << "                                 3. List by Classification\n"
                  << "                                 4. Print All Contacts\n"
                  << "                                 5. Save to File\n"
                  << "                                 6. Load from File\n"
                  << "                                 7. Delete a Contact\n"
                  << "                                 8. Update Contact Information\n"
                  << "                                 9. Reverse Contacts\n"
                  << "                                 10. Print favourite Contacts\n "
                  << "                                 11. Exit\n"
                  <<"                                 ============================== \n";
    }

    void run() {
        int choice;
        do {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: addContact(); break;
                case 2: searchByLastName(); break;
                case 3: listByClassification(); break;
                case 4: printAllContacts(); break;
                case 5: saveToFile(); break;
                case 6: loadFromFile(); break;
                case 7: deleteContact(); break;
                case 8: updateContact(); break;
                case 9: reverseContacts(); break;
                case 10: printfav(); break;
                case 11: std::cout << "Exiting...\n"; break;
                default: std::cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 11);
    }
};

int main() {
    ContactBook contactBook;
    contactBook.run();
    return 0;
}
