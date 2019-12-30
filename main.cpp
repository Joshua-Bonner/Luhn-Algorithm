//Joshua Bonner

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants
enum CrdCard{AmericanExpress, Visa, MasterCard, Discover, ALL} CrdCard;

//Function Prototypes
int rndDgit();
void genCC(enum CrdCard, int[]);
void flipDig(int[]);
void transP(int[]);
bool validCC(int[]);



int main() 
{
	int choice;
	const int size = 20;
        int cc[size];
        srand(static_cast<unsigned int>(time(0)));
        int cor=0;
        int wro=0;
  
	cout << "This program generates random valid credit card numbers based on the type" << endl;
    cout << "Then randomly flips a single digit and tests the account number with the Luhn Algorithm"<<endl;
    cout << "Then provides the percentage of correct instances of account numbers"<<endl;
	cout << "Please select a credit card type from the list using the corresponding digits:" << endl;

	do
	{

	cout << "AmericanExpress = 0" << endl;
	cout << "Visa = 1" << endl;
	cout << "MasterCard = 2" << endl;
	cout << "Discover = 3" << endl;
    cout << "End Program = 4" << endl;
	cin >> choice;
	
	
		if (choice == 0)
		{
			for (int i = 0; i < 10000; i++)
			{
				CrdCard = AmericanExpress;
				genCC(CrdCard::AmericanExpress, cc);
				transP(cc);
				flipDig(cc);
				if (validCC(cc) == true)
					cor++;
				else
					wro++;
			}
			cout << "Correct instances : " << cor << endl;
			cout << "Incorrect instances : " << wro << endl;
			cout << endl;
		}
		if (choice == 1)
		{
			for (int i = 0; i < 10000; i++)
			{
				CrdCard = Visa;
				genCC(CrdCard::Visa, cc);
				transP(cc);
				flipDig(cc);
				if (validCC(cc) == true)
					cor++;
				else
					wro++;
			}
			cout << "Correct instances : " << cor << endl;
			cout << "Incorrect instances : " << wro << endl;
			cout << endl;
		}
		if (choice == 2)
		{
			for (int i = 0; i < 10000; i++)
			{
				CrdCard = MasterCard;
				genCC(CrdCard::MasterCard, cc);
				transP(cc);
				flipDig(cc);
				if (validCC(cc) == true)
					cor++;
				else
					wro++;
			}
			cout << "Correct instances : " << cor << endl;
			cout << "Incorrect instances : " << wro << endl;
			cout << endl;
		}
		if (choice == 3)
		{
			for (int i = 0; i < 10000; i++)
			{
				CrdCard = Discover;
				genCC(CrdCard::Discover, cc);
				transP(cc);
				flipDig(cc);
				if (validCC(cc) == true)
					cor++;
				else
					wro++;
			}
			cout << "Correct instances : " << cor << endl;
			cout << "Incorrect instances : " << wro << endl;
			cout << endl;
		}
	} while (choice != 4);
        return 0;
	
}

bool validCC(int cc[])
{
	// Double every other digit and get the sum
            int sum = 0;
            for (int i = 0; i < 20; i++)
            {
		if (i % 2 == 0)
                    sum += cc[i];
		else
		{
                    int temp = cc[i];
                    temp += temp;
                    if (temp >= 10)
										temp -= 9;
                    sum += temp;
		}
            }

		// Set the check digit so that the overall sum ends in 0
		
                if(cc[15]==(sum*9)%10)
                    return true;
                else
                    return false;
}

void transP(int cc[])
{
	cc[rand() % 8 + 6] = cc[rand() % 3];
	cc[rand() % 8 + 6] = cc[rand() % 4+3];
}

void flipDig(int cc[])
{
    cc[rand()%5+9]=rand()%9;
	cc[rand()%5+9]=rand()%9;
}

void genCC(enum CrdCard, int cc[])
{
	int sum;

	switch (CrdCard)
	{
	case AmericanExpress:
            
            // Set the appropriate digits for the specific account number
            cc[0]=3;
            cc[1]=4;
            // Randomly populate the first 14 digits
            for (int i = 2; i < 15; i++)
		cc[i] = rndDgit();

            // Double every other digit and get the sum
            sum = 0;
            for (int i = 0; i < 15; i++)
            {
		if (i % 2 == 0)
                    sum += cc[i];
		else
		{
                    int temp = cc[i];
                    temp += temp;
                    if (temp >= 10)
			temp -= 9;
                    sum += temp;
		}
            }

		// Set the check digit so that the overall sum ends in 0
		cc[15] = (sum * 9) % 10;
           
		break;

	case Visa:
		
            // Set the appropriate digits for the specific account number
            cc[0]=4;
            // Randomly populate the first 14 digits
            for (int i = 1; i < 16; i++)
		cc[i] = rndDgit();

            // Double every other digit and get the sum
            sum = 0;
            for (int i = 0; i < 16; i++)
            {
		if (i % 2 == 0)
                    sum += cc[i];
		else
		{
                    int temp = cc[i];
                    temp += temp;
                    if (temp >= 10)
			temp -= 9;
                    sum += temp;
		}
            }

		// Set the check digit so that the overall sum ends in 0
		cc[16] = (sum * 9) % 10;
            
		break;

	case Discover:
            
            // Set the appropriate digits for the specific account number
            cc[0]=6;
            cc[1]=0;
             // Randomly populate the first 14 digits
            for (int i = 2; i < 19; i++)
		cc[i] = rndDgit();

            // Double every other digit and get the sum
            sum = 0;
            for (int i = 0; i < 19; i++)
            {
		if (i % 2 == 0)
                    sum += cc[i];
		else
		{
                    int temp = cc[i];
                    temp += temp;
                    if (temp >= 10)
			temp -= 9;
                    sum += temp;
		}
            }

		// Set the check digit so that the overall sum ends in 0
		cc[19] = (sum * 9) % 10;
                
                break;
            
	case MasterCard:
            
            // Set the appropriate digits for the specific account number
            cc[0]=5;
            cc[1]=1;
            // Randomly populate the first 14 digits
            for (int i = 2; i < 19; i++)
		cc[i] = rndDgit();

            // Double every other digit and get the sum
            sum = 0;
            for (int i = 0; i < 19; i++)
            {
		if (i % 2 == 0)
                    sum += cc[i];
		else
		{
                    int temp = cc[i];
                    temp += temp;
                    if (temp >= 10)
			temp -= 9;
                    sum += temp;
		}
            }

		// Set the check digit so that the overall sum ends in 0
		cc[19] = (sum * 9) % 10;
		
		break;

	default:
		break;
	}
}

int rndDgit()
{
    return rand()%9;
}
