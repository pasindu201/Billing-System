#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <iomanip>
using namespace std;

struct Items
{
	string Product;
	string Code;
	float Price;
}Products[20];

struct Bill {
	string Product;
	string Code;
	float Price;
	int quantity;
	int tot;
};

void ViewItems();										// Function definition to view Items
void Additems();										//Function definition to Add Items
void OptionNumberadmin();								// Function definition for Chossing the Option Number for admin
void OptionNumbercashier(string);						// Function definition for Chossing the Option number for cashier
void exitProgramadmin();								// Function definition to Exit Program for Admin Menu
void exitProgramcashier(string);						// Function definition to Exit program for Cashier Menu
void Logoutcashier(string);								//Function definition to LOGOUT for Cashier
void Logoutadmin();										//Function definition to LOGOUT for Admin
void Select_Print(string);								// Function definition to Select and Print Bill
void SalesRecords();									//Function definition to View all Sales Records
void Products1();										//Funtion declaration for the Products

int main() {
	string username;									//Username
	string password;									//Password
	bool LoginSuccess = false;							//boolean expression for login
	int attempt = 1;

	cout << "\t-------------------- _ _ _ _ STAR SUPERMARKET _ _ _ _------------------ -" << endl;
	cout << "" << endl;
	cout << "LOGIN\n" << "_ _ _ _ _" << endl;

	do {
		cout << "\t\tEnter Username: ";
		cin >> username;									//Reading username
		cout << "\t\tEnter Password: ";
		cin >> password;									//Reading Password
		cout << "" << endl;

		if ((username == "Enok" && password == "12345")) {
			cout << "Successfully Logged In!\n"<<endl;
			cout << "Welcome " << username+"!" << endl;
			system("pause");
			LoginSuccess = true;
			//option number choosing
			OptionNumberadmin();
		}
		else if ((username == "Shemalka" && password == "123") || (username == "Steve" && password == "123")) {
			cout << "Successfully Logged In!\n" << endl;
			cout << "Welcome " << username + "!" << endl;
			system("pause");
			LoginSuccess = true;
			//option number choosing
			OptionNumbercashier(username);
		}

		else {
			//Message will appear for 3 times if the user inputs wrong username and password
			system("cls");
			cout << "\t-------------------- _ _ _ _ STAR SUPERMARKET _ _ _ _------------------ -" << endl;
			cout << "" << endl;
			cout << "LOGIN\n" << "_ _ _ _ _" << endl;
			cout << "\t\tInvalid Username and Password    " << 3 - attempt << " Attempt(s) left " << endl;
			cout << "" << endl;
			
			++attempt;
			
		}
		
	} while (!LoginSuccess && attempt<=3);
	if (attempt = 3) {
		cout << "Program will be terminated" << endl;
	}
}

//Option Number Choosing for admin
void OptionNumberadmin() {
	int choose1;
	system("cls");
	// OKMED PHARMACY Header
	cout << "\t-------------------- _ _ _ _ STAR SUPERMARKET _ _ _ _------------------ -" << endl;
	cout << "" << endl;
	cout << "\t\t\t\tADMIN MENU\n" << "\t\t\t\t_ _ _ _ _ _ _" << endl;
	cout << "" << endl;
	cout << "\t\t\t\t1. View Items" << endl;								//View Item option to see all pharmacuticals
	cout << "\t\t\t\t2. Add Items" << endl;									//Add items to the database
	cout << "\t\t\t\t3. View Sales Records" << endl;						//View Sales Records
	cout << "\t\t\t\t4. Log out" << endl;									//Logging out
	cout << "\t\t\t\t5. Exit" << endl;										//Exit from the program
	cout << "" << endl;

	cout << "\tEnter Option: ";
	cin >> choose1;
	cout << "" << endl;
	switch (choose1) {
	case 1:
		ViewItems();													// Calling fucntion to view items
		system("pause");
		system("cls");													// clear CMD.
		OptionNumberadmin();
		break;
	case 2:
		Additems();														//Calling function to Add Items
		OptionNumberadmin();
		break;	
	case 3:
		system("cls");
		SalesRecords();													//Calling Function to View Sales Records
		system("pause");
		system("cls");													// clear CMD.
		OptionNumberadmin();
	case 4:
		system("cls");													// clear CMD.
		Logoutadmin();													//Calling for Logout funtion to reenter the username and password
		break;
	case 5:
		system("CLS");													// clear CMD.
		exitProgramadmin();
	default:
		cout << "Enter valid Input" << endl;					//Printing error message
		system("pause");
		OptionNumberadmin();									//Calling the Function to reenter the correct input 
		break;
	}
};
//Option number choosing for cashier
void OptionNumbercashier(string username) {
	int choose2;
	system("cls");
	// OKMED PHARMACY Header
	cout << "\t-------------------- - _ _ _ _ OKMED_ _ _ _ _------------------ -" << endl;
	cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ PHARMACY_ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "" << endl;
	cout << "\t\t\t\tCASHIER MENU\n" << "\t\t\t\t_ _ _ _ _ _ _ _" << endl;
	cout << "" << endl;
	cout << "\t\t\t\t1. View Items" << endl;								//View Item option to see all pharmacuticals
	cout << "\t\t\t\t2. Select & Print Bill" << endl;						//Select Items & Print Bill
	cout << "\t\t\t\t3. Log out" << endl;									//Log out
	cout << "\t\t\t\t4. Exit" << endl;										//Exit from the program
	cout << "" << endl;

	cout << "\tEnter Option: ";										//ASking user to enter option
	cin >> choose2;													//Reading option
	cout << "" << endl;
	switch (choose2) {
	case 1:
		ViewItems();												// Calling fucntion to view items
		system("pause");
		system("cls");												// clear CMD.
		OptionNumbercashier(username);								//After viewing going back to menu for cashier
		break;
	case 2:
		Select_Print(username);										//Calling function to Select Items
		OptionNumbercashier(username);								//After Selecting & printing going back to menu for cashier
		break;
	case 3:
		system("cls");												// clear CMD.
		Logoutcashier(username);									//Calling for Logout funtion to reenter the username and password
		break;
	case 4:
		system("CLS");												// clear CMD.
		exitProgramcashier(username);
		break;
	default:
		system("cls");												// clear CMD.
		cout << "Enter valid Input" << endl;						//Displaying error message
		system("pause");
		OptionNumbercashier(username);								//Calling function of Cashier Menu to re enter
		break;
	}
}
//Function to View Items
void ViewItems() {
	system("cls");
	std::string line_;
	cout << "" << endl;
	cout << " ITEMS\n" << "_ _ _ _ _" << endl;
	cout << "" << endl;
	ifstream itemList("ItemList.txt");
	if (itemList.is_open()) {
		while (getline(itemList, line_)) {
			std::cout << line_ << '\n';
		}
		itemList.close();
	}
	else
		std::cout << "file is not FOUND. Please Contact System Administrator for Maintainance" << '\n';
	std::cin.get();

}
//Funtion to view Sales Records 
void SalesRecords() {
	cout << "" << endl;
	cout << "SALES RECORDS\n" << "_ _ _ _ _ _ _" << endl;
	system("pause");
	cout << "" << endl;
	std::string line_;
	//Reading of File
	ifstream invoices("Invoices.txt");
	if (invoices.is_open()) {
		while (getline(invoices, line_)) {
			std::cout << line_ << '\n';
		}
		invoices.close();
	}
	else
		//Display of Error Message
		std::cout << "file is not FOUND. Please Contact System Administrator for Maintainance" << '\n';
	std::cin.get();
}
//Function to Add Items
void Additems() {
	int NoofItems;
	Items a[15];
	ofstream itemList("ItemList.txt");
	if (itemList.is_open()) {
		do {												//Array to store upto 15 new pharmceuticals at once
			system("cls");
			cout << "" << endl;
			cout << "ADD ITEMS\n" << "_ _ _ _ _ _ " << endl;
			cout << "" << endl;
			cout << "No of Items to be added : ";								//Asking the user the no. of items to be added
			cin >> NoofItems;
			cout << "" << endl;
            if (std::isdigit(NoofItems)) {
                if (NoofItems > 15) {
				system("cls");
				cout << "\n\t\t\t**YOU CAN ENTER 15 ITEMS AT ONCE\n " << endl;
				system("pause");
			    }

            } else {
                cout << "Please enter a valid number" ;
            }
			
		} while (NoofItems > 15);
		
		for (int c = 0; c < NoofItems; ++c) {					//The loop to Get the data of the items
			cout << "Product Name : ";
			cin >> a[c].Product;
			cout << "Product Code : ";
			cin >> a[c].Code;
			cout << "Price : ";
			cin >> a[c].Price;
			cout << "" << endl;
		}
		cout << "" << endl;

		for (int c = 0; c < NoofItems; c++) {			//THe loop to input data of the items into the text file
			ofstream itemList("ItemList.txt", std::ios::app);
			itemList << a[c].Code << "\t\t" << a[c].Product << "\t\t\t\t\t\t" << "LKR " << a[c].Price << endl;
			itemList.close();
		}
		cout << "Items Added successfully" << endl;		//Notification of success
		system("pause");
		system("cls");
	}
	else {
		cout << "File is not found to store new items" << endl;		//Error Message
		system("pause");
	}
}

void Select_Print(string username) {
	Bill Array[20];						//Array to store selected medinicines
	time_t t;							//Variable to store time
	time(&t);
	int c = 0, item, tot, amount, balance = 0, qty, subtotal = 0;
	string Next,search,search1;
	Products1();

	ViewItems();
	cout << "" << endl;
	cout << "SELECT & PRINT BILL\n" << "_ _ _ _ _ _ _ _ _ _ _ _ _ _\n" << endl;
	cout << "" << endl;
	do {
		cout << "(Maximum 10 items)" << endl;
		cout << "How Many items : ";
		cin >> item;
		if (item > 10) {
			//Error message if he enters a number more than 10
			cout << "\t\t\t**Please Enter range between 1-10\n" << endl;
		}
	} while (item > 10);
	cout << "" << endl;
	while (c < item) {
		cout << "Enter Code:";
		cin >> search;
		cout << "" << endl;
		for (int c = 0; c < 20; c++) {
			if (search == Products[c].Code) {
				cout << "Product Name : " << Products[c].Product << endl;
				cout << "Product Price :" << Products[c].Price << endl;
				Array[c].Code = Products[c].Code;								//Storing selected product Code
				Array[c].Product = Products[c].Product;						//Storing selected product Name
				Array[c].Price = Products[c].Price;							//Storing selected Product Price
				cout << "" << endl;
				cout << "Enter quantity :";										//Asking the quantity of the selected item
				cin >> qty;
				cout << "*" << endl;
				tot = qty*Products[c].Price;									//Sum is equal to Price multiplied by Quantity
				subtotal = subtotal + tot;										//Subtotal of the selected products equal to Total of Sum
				Array[c].quantity = qty;										//Storing quantity of the selected product
				Array[c].tot = tot;												//Storing of sum of the selected product
			}
			
		}
		c++;
	}
	cout << "Your Payment is : LKR " << subtotal << endl;						//Display Subtotal
	cout << "Enter amount : ";
	cin >> amount;																//Enter amount given by costumer
	balance = amount - subtotal;												//Balance is equal to subtotal substracted by Amount
	cout << "Balance : " << balance << endl;									//Display balance
	system("pause");
	//Display of Bill
	system("cls");
	cout << ctime(&t) << endl;
	cout << "" << endl;
	cout << "\t-------------------- _ _ _ _ STAR SUPERMARKET _ _ _ _------------------ -" << endl;
	cout << "\t\t   No 101  Colombo - Hanwella Low Level Rd, Kaduwela" << endl;
	cout << "\t\t\tTEL # 0112 500000 / 0114 000000" << endl;
	cout << "Cashier : " << username << endl;
	cout << "" << endl;
	cout << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	for (int c = 0; c < 20; c++) {
		if (Array[c].quantity >= 1) {
			cout << Array[c].Product << endl;
			cout << setw(13) << Array[c].Code << setw(16) << "(" << Array[c].Price << "x" << Array[c].quantity << ")" << setw(38) << "LKR " << Array[c].tot << endl;
		}
	}
	cout << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << "SUB TOTAL" << setw(64) <<"LKR "<< subtotal << endl;
	cout << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << "Amount " << setw(66) << "LKR " << amount << endl;
	cout << "Balance" << setw(66) << "LKR " << balance << endl;
	cout << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << "\t\t\tTHANK YOU COME AGAIN!" << endl;
	cout << "Dear Customer," << endl;
	cout << "" << endl;
	cout << "Please note that items will not be accepted " << endl;
	cout << "as return or exchange." << endl;
	cout << "" << endl;
	cout << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	cout << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

	//Printing to Bill to the text file
	ofstream invoice("Invoices.txt", ios::app);
		invoice << ctime(&t) << endl;
		invoice << "" << endl;
		invoice << "\t-------------------- _ _ _ _ STAR SUPERMARKET _ _ _ _------------------ -" << endl;
		invoice << "\t\t   No 101  Colombo - Hanwella Low Level Rd, Kaduwela" << endl;
		invoice << "\t\t\tTEL # 0112 500000 / 0114 000000" << endl;
		invoice << "" << endl;
		invoice << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		for (int c = 0; c < 20; c++) {
			if (Array[c].quantity >= 1) {
				invoice << Array[c].Product << endl;
				invoice << setw(13) << Array[c].Code << setw(16) << "(" << Array[c].Price << "x" << Array[c].quantity << ")" << setw(38) << "LKR " << Array[c].tot << endl;
			}
		}
		invoice << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		invoice << "SUB TOTAL" << setw(64) << "LKR " << subtotal << endl;
		invoice << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		invoice << "Amount " << setw(66) << "LKR " << amount << endl;
		invoice << "Balance" << setw(66) << "LKR " << balance << endl;
		invoice << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		invoice << "\t\t\tTHANK YOU COME AGAIN!" << endl;
		invoice << "Dear Customer," << endl;
		invoice << "" << endl;
		invoice << "Please note that items will not be accepted " << endl;
		invoice << "as return or exchange." << endl;
		invoice << "" << endl;
		invoice << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		invoice << " _ _   _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		invoice << "" << endl;
		invoice << "" << endl;
		invoice.close();
		cout << "" << endl;
		cout << "" << endl;
		cout << "*Successfully stored to the database" << endl;
		system("pause");
	//Message to print another bill
	do {
		cout << "Do you want to print another Bill? (Y/N): ";
		cin >> Next;
		if (Next == "Y") {
			system("cls");
			Select_Print(username);									//Call function to Select and Priint Bill
		}
		else if (Next == "N") {
			system("cls");
			OptionNumbercashier(username);							//Calling Cashier Menu Function
		}
		else {
			system("cls");
			cout << "\n\t\t\t\t\t   ***   ENTER EITHER Y OR N  ONLY   *** \n" << endl; // prints error message.
		}
	} while (Next != "Y" || Next != "N");
}
		
//Exit Function for Admin
void exitProgramadmin()
{
	string userInput1; // variable to get user input.
	cout << "EXIT\n" << "_ _ _ _" << endl;
	cout << "" << endl;
	cout << "\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t\t\t\t|          CONFIRM, DO YOU WANT TO EXIT		|" << endl;
	cout << "\t\t\t\t\t|               [ YES / NO ]			|" << endl;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cin >> userInput1;

	if (userInput1 == "Y") // if user input equal 'Y' loop.
	{
		exit(0); // exit completely.
	}

	else if (userInput1 == "N") // if user input equal 'N' loop.
	{
		system("CLS"); // clear CMD.
		OptionNumberadmin();
	}

	else
	{
		cout << "\n\t\t\t\t\t   ***   ENTER EITHER Y OR N  ONLY   *** \n" << endl; // prints error message.
		exitProgramadmin();

	}
}
// Exit Function for Cashier
void exitProgramcashier(string username)
{
	string userInput2; // variable to get user input.
	cout << "EXIT\n" << "_ _ _ _" << endl;
	cout << "" << endl;
	cout << "\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t\t\t\t|          CONFIRM, DO YOU WANT TO EXIT		|" << endl;
	cout << "\t\t\t\t\t|               [ YES / NO ]			|" << endl;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cin >> userInput2;

	if (userInput2 == "Y") // if user input equal 'Y' loop.
	{
		exit(0); // exit completely.
	}

	else if (userInput2 == "N") // if user input equal 'N' loop.
	{
		system("CLS"); // clear CMD.
		OptionNumbercashier(username);
	}

	else
	{
		cout << "\n\t\t\t\t\t   ***   ENTER EITHER Y OR N  ONLY   *** \n" << endl; // prints error message.
		exitProgramcashier(username);
	}
}
//Function to logout for Admin
void Logoutadmin()
{
	cout << "LOGOUT\n" << "_ _ _ _ _" << endl;
	cout << "" << endl;
	string userInput3; // variable to get user input.
	cout << "\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t\t\t\t|          CONFIRM, DO YOU WANT TO LOGOUT	|" << endl;
	cout << "\t\t\t\t\t|               [ YES / NO ]			|" << endl;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cin >> userInput3;

	if (userInput3 == "Y") // if user input equal 'Y' loop.
	{
		system("CLS");
		main(); // Logout completely.

	}

	else if (userInput3 == "N") // if user input equal 'N' loop.
	{
		system("CLS"); // clear CMD.
		OptionNumberadmin();
	}

	else
	{
		cout << "\n\t\t\t\t\t   ***   ENTER EITHER Y OR N  ONLY   *** \n" << endl; // prints error message.
		Logoutadmin();
	}
}
//Function to logout for cashier
void Logoutcashier(string username)
{
	string userInput4; // variable to get user input.
	cout << "LOGOUT\n" << "_ _ _ _ _" << endl;
	cout << "" << endl;
	cout << "\n\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t\t\t\t|          CONFIRM, DO YOU WANT TO LOGOUT	|" << endl;
	cout << "\t\t\t\t\t|               [ YES / NO ]			|" << endl;
	cout << "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cin >> userInput4;

	if (userInput4 == "Y") // if user input equal 'Y' loop.
	{
		system("CLS");
		main(); // Logout completely.
		
	}

	else if (userInput4 == "N") // if user input equal 'N' loop.
	{
		system("CLS"); // clear CMD.
		OptionNumbercashier(username);
	}

	else
	{
		cout << "\n\t\t\t\t\t   ***   ENTER EITHER Y OR N  ONLY   *** \n" << endl; // prints error message.
		Logoutcashier(username);
	}
}

void Products1() {

	Products[0].Code = "MLK";
	Products[0].Product = "Milk (1 liter)";
	Products[0].Price = 250.00;

	Products[1].Code = "BRD";
	Products[1].Product = "Bread (loaf)";
	Products[1].Price = 150.00;

	Products[2].Code = "RICE";
	Products[2].Product = "Rice (1 kg)";
	Products[2].Price = 300.00;

	Products[3].Code = "EGGS12";
	Products[3].Product = "Eggs (12 pieces)";
	Products[3].Price = 400.00;

	Products[4].Code = "CHICK1";
	Products[4].Product = "Chicken (1 kg)";
	Products[4].Price = 1200.00;

	Products[5].Code = "APPL1";
	Products[5].Product = "Apples (1 kg)";
	Products[5].Price = 600.50;

	Products[6].Code = "BNN12";
	Products[6].Product = "Bananas (1 dozen) ";
	Products[6].Price = 250.00;

	Products[7].Code = "PTT1";
	Products[7].Product = "Potatoes (1 kg)";
	Products[7].Price = 200.00;

	Products[8].Code = "ONION1	";
	Products[8].Product = "Onions (1 kg)";
	Products[8].Price = 150.00;

	Products[9].Code = "TMT1";
	Products[9].Product = "Tomatoes (1 kg)";
	Products[9].Price = 250.00;

	Products[10].Code = "OIL1";
	Products[10].Product = "Cooking Oil (1 liter)";
	Products[10].Price = 500.00;

	Products[11].Code = "SGR1";
	Products[11].Product = "Sugar (1 kg)";
	Products[11].Price = 250.00;

	Products[12].Code = "TEA250";
	Products[12].Product = "Tea Leaves (250 grams)";
	Products[12].Price = 350.00;

	Products[13].Code = "SLT1";
	Products[13].Product = "Salt (1 kg)";
	Products[13].Price = 100.00;

	Products[14].Code = "PST500";
	Products[14].Product = "Pasta (500 grams)";
	Products[14].Price = 300.00;

	Products[15].Code = "YGRT500		";
	Products[15].Product = "Yogurt (500 grams)";
	Products[15].Price = 300;
}