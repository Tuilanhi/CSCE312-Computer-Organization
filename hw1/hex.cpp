#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

/*
* This function will convert Decimal to Binary
*/
void DecimaltoBinary(int n)
{
  int binaryNum[100]; //initialize the binaryNum list with nothing
  int num = n;
  int i = 0;

  do
  {
    binaryNum[i] = n % 2; //takes the remainder of the quotient after dividing by 2
    n /= 2;               //divide the quotient by 2 until it is 0
    ++i;
  } while (n > 0);

  for (int j = i - 1; j >= 0; --j) //reverse the order of binaryNum and output the answers when the function is called
  {
    cout << binaryNum[j];
  }
  cout << endl;
}

/*
* This function will convert Binary to Decimal
*/
void BinarytoDecimal(int binary)
{

  int dec = 0, i = 0, last_digit; //initialize and declare variables

  do
  {
    last_digit = binary % 10; //take the modulus of binary number
    binary /= 10;
    dec += last_digit * pow(2, i); //the decimal number is adding on the last digit of binary and multiply that by the 2 to the power of i. E.G. if there is a 1 in the index of 1 then 1 * 2^1.
    ++i;
  } while (binary != 0);

  cout << dec;
}

/*
* This function will convert Decimal to Hexadecimal
*/
void DecimaltoHexa(int n)
{
  char hex[1000]; //initialize the hexadecimal list
  int i = 0;
  do
  {
    int j = 0;

    j = n % 16; //modulus 16 to find the remainder

    if (j < 10)
    {
      hex[i] = (char)(j + 48); //turn the number to a string
      ++i;
    }
    else //if the number is greater than 9
    {
      hex[i] = char(j + 55); //turn the number into a character from a to f
      ++i;
    }
    n /= 16; //number slicing

  } while (n != 0);

  for (int k = i - 1; k > -1; --k)
  {
    cout << hex[k]; //print out the result in reverse order
  }
}

int main()
{
  char ans1, ans2;
  cin >> ans1;                                      //read in the first user's input
  if (!(ans1 == 'd' || ans1 == 'h' || ans1 == 'b')) //checks for invalid input
  {
    cout << "Usage: ./hex [ h | d | b ] [ h | d | b] ";
  }
  else
  {
    if (ans1 == 'd')
    {
      int num;

      cin >> ans2 >> num;
      if (ans2 == 'b')
      {
        cout << "decimal " << num << " is binary ";
        DecimaltoBinary(num); //calls the function to perform conversion and computation
        cout << endl;
      }
      if (ans2 == 'h')
      {
        cout << "decimal " << num << " is hexadecimal ";
        DecimaltoHexa(num);
        cout << endl;
      }
    }
    if (ans1 == 'h')
    {
      int num = 0;
      cin >> ans2;
      string hexNum; //initialize hexadecimal as string
      cin >> hexNum;
      if (ans2 == 'd')
      {

        num = stoi(hexNum, 0, 16); //convert characters in hexadecimal to a value of integers and return its value
        cout << "hexadecimal " << hexNum << " is decimal " << num << endl;
      }
      if (ans2 == 'b')
      {
        cout << "hexadecimal " << hexNum << " is binary " << num;
        num = stoi(hexNum, 0, 16); //convert characters in hexadecimal to a value of integers and return its value
        DecimaltoBinary(num);
        cout << endl;
      }
    }

    if (ans1 == 'b')
    {
      int num = 0;
      cin >> ans2 >> num;
      if (ans2 == 'd')
      {
        cout << "binary " << num << " is decimal ";
        BinarytoDecimal(num);
        cout << endl;
      }
      if (ans2 == 'h')
      {
        cout << "binary " << num << " is hexadecimal ";
        BinarytoDecimal(num);
        DecimaltoHexa(num);
        cout << endl;
      }
    }
  }
  return 0;
}