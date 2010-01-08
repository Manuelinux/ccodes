// marcy.cpp : Defines the entry point for the console application.
//



#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;

const bool KEYBOARD = true;
ofstream Out("con");

int    getNumberOfSales(void);
int    getItemNumber(void);
double getPrice(int itemNumber);
bool   isTaxable(int itemNumber);
int    getQuantity(int itemNumber);
double getCost(int itemNumber, int count, double price);
double getTax(double sales);
void   printLine(ostream & w,int iNumber, int qty, double price,double cost, bool taxable);
void   printTotal(ostream & w, int loopCount, double grandTotal, double taxDue);
void   headings(ostream & w);
void   startRandom(void);
void   prepareOutput( ostream & w);

int main()
{
	  int differentItems,       // Number of items to purchase
			iNumber,              // Item number code
			qty;                  // Number of a particular item purchased
	  double price,             // Price of a particular item
				cost,              // The cost of the item purchase = price * qty
				taxableTotal,      // Total of all taxable purchases
				nonTaxableTotal,   // Total of all nontaxable purchases
				taxDue,            // Tax due on the taxable total
				grandTotal;        // Sum of taxableTotal, nonTaxableTotal
	  bool   taxable;           // Flag to indicate if the item is taxable

	  //  STUDENT -- Initialize ONLY those variables that need an initial value
	  taxableTotal=0;
	  nonTaxableTotal=0;
	  grandTotal=0;
	  prepareOutput(Out);
	  if (!KEYBOARD) startRandom();
	  headings(Out); // for computer generate 
	  differentItems = getNumberOfSales();
	  for( int i = 0; i < differentItems ; i++)
	  {
		  iNumber = getItemNumber();
		  qty     = getQuantity(iNumber);
		  price   = getPrice(iNumber);
		  cost    = getCost(iNumber, qty, price);
		  taxable = isTaxable(iNumber);
		  // headings(Out);   // for keyboard input
		  printLine(Out,iNumber,qty,price,cost,taxable);

		  if(taxable)
			  taxableTotal+=cost;
		  else
			  nonTaxableTotal+=cost;
		  //  accumulate
				 //   ******* -  taxable total
				 //   ********  -  nontaxable total

	  }  // end for
	  taxDue = getTax( taxableTotal   )   ;
	  grandTotal=taxableTotal+nonTaxableTotal;
	  printTotal( Out,differentItems, grandTotal, taxDue);
		return 0;
}  // end main


void startRandom(void)
{
	int seed;
	cout << "Enter seed value for random number generator: ";
	cin >> seed;
	srand(seed);
}


int getItemNumber(void)
{                             //  item number should be a 4-digit integer
		int num;
		if (KEYBOARD)
		{  cout << "Enter item number: ";
			cin >> num;
		}
		else
			num = rand() % 9000 + 1000;
		return num;
}

double getPrice(int num)
{                            //  price should be between .10 and 10.09
	double price;
	if (KEYBOARD)
		{  cout << "Enter price for item  " << num << " : ";
			cin >> price;
		}
	else
			price = double (rand() % 1000 + 10 ) / 100;
	return price;

}
bool isTaxable(int itemNumber)
{
	char ans;
	/*cout << " Is item number " << itemNumber << " taxable e(y or n ) : ";
	cin >> ans;
	if (ans == 'y')
		return true;
	else
		return false;              Aqui se te olvido checar si keyboard era true
	if(itemNumber % 5 == 0)
		return false;
	else
		return true;*/
  if(KEYBOARD)
{
  cout << " Is item number " << itemNumber << " taxable e(y or n ) : ";
	cin >> ans;
	if (ans == 'y')
		return true;
	else
		return false;
}
else
{
  if(itemNumber % 5 == 0)
		return false;
	else
		return true;
}
		//  ask the user     
		//       OR
		//   computer will make NOT taxable if itemNumer is divisible by 5
}
int getQuantity(int num)
{
	int ans;
	if (KEYBOARD)
	{
		cout << "How many of item " << num << " were purchased ? :";
		cin >> ans;
	}
	else
		ans = rand() % 9;
		//  ask the user
		//       OR
		//   computer will make a choice between 1 and 8
			
  return ans;  
}
int getNumberOfSales(void)
{
	int ans;
	if (KEYBOARD)
	{
		cout << "How many different items to purchased? ";
		cin >> ans;
	}
	else
		ans = rand() % 16;
		//  ask the user
		//       OR
		//   computer will make a choice between 1 and 15
 return ans; 
}
double getCost(int itemNumber, int count, double price)
{
	return count * price; 
}

double getTax( double sales)
{  const double tax = 0.0725;//   define a const for the sales tax rate  - USE a rate of  0.0725
	return sales * tax; // ********* this is just a stub
}

void printLine(ostream & w,int iNumber, int qty, double price,double cost, bool taxable)
{
    cout <<setw(10)<< iNumber<<setw(10)<<qty<<setw(10)<<price<<setw(10)<<cost;  // print a "*" for the item which is
	if (taxable == false)
		cout << "   *";									// not taxable
	cout<<endl;
}

void printTotal( ostream & w,int loopCount, double grandTotal, double taxDue)
{
	cout << "Purchase : "<<grandTotal<<endl<< "Tax :   "<<taxDue<<endl <<"Amount : " << grandTotal + taxDue << endl; // ********again a stub here

	cout << endl <<" * indicates item was not taxable ." << endl;
}

void headings(ostream & w)
{
  cout << setw(10) << "item #" << setw(10) << "quantity" << setw(10) <<"price"
		  << setw(10) << "cost" << endl << endl;
}

void prepareOutput(ostream & w)
{
	w << setiosflags(ios::showpoint | ios:: fixed) << setprecision(2);
}

