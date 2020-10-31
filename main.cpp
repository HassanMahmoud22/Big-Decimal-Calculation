#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


class BigDecimalInt
{
private:
	string decStr;      //decStr is the value of the number we want to add
	int counter;        //counter used in constructor to check if there is any letter in string
	int length;         // the length of a string
	bool negative;      // boolean to check if the number is negative or not
    bool test;          // boolean used in a while loop to take a suitable input
public:
	BigDecimalInt()
	{                   //default constructor to initialize values
		decStr = " ";
		counter = 0;
		length = 0;
		negative = false;
		test = true;
	}
	BigDecimalInt(int decInt)  //parametrized constructor to take integer as an input and convert it to string
	{
        string str = "";
        stringstream converter;     //creating object from stringstream which convert int to string
        converter<<decInt;          // converter will be the value of int in a string form
        converter>>str;             // then str will be the value of converter
        decStr = str;               // then decStr = str

	}
	int size(int value)     //function take the size of string and equates it with length
	{
		this->length = value;
		return length;
	}
	BigDecimalInt(string value)    //parametrized constructor takes the string and check if it's number or not
	{
		while (test)
		{
			if (value[0] == '-') //if the first letter of string is negative
			{
				for (int i = 1; i < value.size(); i++)  //for loop to check if there is any letter except integers
				{
					if (!isdigit(value[i]))
					{
						counter = 1;        //if he found anything except integer then counter = 1
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < value.size(); i++) //for loop to check if there is any letter except integers
				{
					if (!isdigit(value[i]))
					{
						counter = 1;   //if he found anything except integer then counter = 1
						break;
					}
				}
			}
			if (value[0] == '0') //if it found the index 0 of string is zero then delete it untill he find a number
			{
				size(value.length());
				for (int i = 0; i < length; i++)
				{
					if (value[0] == '0' && length > 1)  // if it found zero and the length is still more than 1
					{
						value.erase(value.begin());     //then delete it
					}
					else
						break;

				}
			}

			else if (value[0] == '-')       //if index 0 is negative
			{
			    if(value[1] == '0')         //if it found the index 0 of string is zero then delete it untill he find a number
                {
                    value.erase(value.begin());
                    size(value.length());
                    for (int i = 1; i < length; i++)
                    {
                        if (value[0] == '0' && length > 1)   // if it found zero and the length is still more than 1
                        {
                            value.erase(value.begin());     //then delete it
                        }
                        else
                            break;
                    }
                    value = '-' + value;
                }
			}
			if (counter == 1)       //if counter equal 1 then ask user to enter it again
			{
				cout << "please enter numerical values" << endl;
				getline(cin, value);
				counter = 0;
				test = true;
			}
			else
            {
                test = false;  //if didn't found then exit loop
            }
		}
		decStr = value;
	}


	BigDecimalInt operator - (BigDecimalInt& obj)
	{
		BigDecimalInt obj3;
		if (decStr.length() < obj.decStr.length()  )  //if first number is smaller than second number
		{
			if (decStr[0] == '-' && obj.decStr[0] == '-')   //if first number and second number are negative
			{
				decStr.erase(decStr.begin());   //then delete negative sign from first number
				obj.decStr.erase(obj.decStr.begin());   //and second number too
				negative = false;
			}
			else if(decStr[0] == '-' && isdigit(obj.decStr[0])) //if first one is negative and second one is positive
            {
                obj.decStr = '-' + obj.decStr;  //then make second one is negative
                obj3.decStr = decStr;       // make the third number equals the first number
                return obj + obj3;          // and then add them
            }
            else if(isdigit(decStr[0]) && obj.decStr[0] == '-')  //if first number is positive and second one is negative
            {
                obj.decStr.erase(obj.decStr.begin());   //then delete the negative sign
                obj3.decStr = decStr;   // make the third number equals the first number
                return obj + obj3;      //then sum them
            }
			else
			{
				negative = true;
			}
			string tmp = decStr;    //swaping the two numbers
			decStr = obj.decStr;
			obj.decStr = tmp;

		}
		else if ((decStr.length()) == (obj.decStr.length()))    //if the two numbers are equal
		{
		    if(isdigit(decStr[0]) && obj.decStr[0] == '-')     //if second one is the negative number
            {
                obj.decStr.erase(obj.decStr.begin());       //then delete the negative sign
                obj3.decStr = decStr;       // make the third number equals the first number
                return obj3 + obj;      //then return the sum of the two numbers
            }
            else if(decStr[0] == '-' && obj.decStr[0] == '-')   //if both numbers are negative
            {
                obj.decStr.erase(obj.decStr.begin());  //then delete negative sign of both
                decStr.erase(decStr.begin());
                obj3.decStr = decStr;           // make the third number equals the first number
                return obj - obj3;        //return their difference
            }
            else if(decStr[0] == '-' && isdigit(obj.decStr[0])) //if first number is negative and second one is positive
            {
                obj.decStr = '-' + obj.decStr;     //then giving negative sign to second number
                obj3.decStr = decStr;              //make third number equals first number
                return obj + obj3;                // return their sum
            }

            else
            {           //that means that both numbers are positive
                int checker = 0;
                if ((decStr[0] - '0') < (obj.decStr[0] - '0'))  //if first number smaller than second number
                {
                    negative = true;            //then the result will be negative
                    string tmp = decStr;        //swaping the two numbers
                    decStr = obj.decStr;
                    obj.decStr = tmp;
                }
                else if((decStr[0] - '0') == (obj.decStr[0] - '0'))     //if both first numbers are equal
                {
                    for (int i = 1 ; i < decStr.length() ; i ++)        //then go to loop to reach to number which is greater than the other
                    {
                        if((decStr[i] - '0') < (obj.decStr[i]-'0'))
                        {                   //if found that the first one is smaller than the second one then swap
                            checker = 1;
                            negative = true;
                            string tmp = decStr;
                            decStr = obj.decStr;
                            obj.decStr = tmp;
                            break;
                        }
                    }

                    if(checker != 1)
                    {
                        negative = false;
                    }
                }
                else
                {
                  negative = false;
                }
            }
		}
		else if (decStr.length() > obj.decStr.length()) //if first number is greater than the second one
		{
			if (decStr[0] == '-' && obj.decStr[0] == '-')   //if both numbers are negative
			{
				decStr.erase(decStr.begin());          //then delete negative signs
				obj.decStr.erase(obj.decStr.begin());
				negative = true;        //and the answer will be negative
			}
			else if(decStr[0] == '-' && isdigit(obj.decStr[0]))     //if first one is the only negative
            {
                obj.decStr = '-' + obj.decStr;      //add negative to second one
                obj3.decStr = decStr;       // make the third number equals the first number
                return obj3 + obj;  //return their sum
            }
            else if(isdigit(decStr[0]) && obj.decStr[0] == '-')     //if the second one is the negative
            {
                obj.decStr.erase(obj.decStr.begin());       //then delete the negative sign
                obj3.decStr = decStr;           // make the third number equals the first number
                return obj3 + obj;          //then return their sum
            }
			else
			{
				negative = false;       //if both are positive then answer will be positive
			}
		}

		// Take an empty string for storing result
		obj3.decStr = "";


		// Calculate length of both strings
		int number1 = decStr.length(), number2 = obj.decStr.length();

		// Reverse both of strings
		reverse(decStr.begin(), decStr.end());
		reverse(obj.decStr.begin(), obj.decStr.end());

		int carry = 0;

		// run in loop till small string length
		// and subtract digit of both of them
		for (int i = 0; i < number2; i++)
		{
			//calculate difference of current digits

			int subtract = ((decStr[i] - '0') - (obj.decStr[i] - '0') - carry);

			// If subtraction is less than zero
			// we add 10 into subtract and
			// take carry as 1 for calculating next step
			if (subtract < 0)
			{
				subtract = subtract + 10;
				carry = 1;

			}
			else
				carry = 0;

			obj3.decStr.push_back(subtract + '0');
		}


		// subtract remaining digits of larger number
		for (int i = number2; i < number1; i++)
		{
			int subtract = ((decStr[i] - '0') - carry);

			// if the subtract value is negative, then make it positive
			if (subtract < 0)
			{
				subtract = subtract + 10;
				carry = 1;
			}
			else
				carry = 0;

			obj3.decStr.push_back(subtract + '0');
		}



		// reverse resultant string

		reverse(obj3.decStr.begin(), obj3.decStr.end());

		if (obj3.decStr[0] == '0')
		{           //if found that first index of the number equals zero delete it untill find a number
		    size(obj3.decStr.length());
			for (int i = 0; i < length; i++)
			{
			    if(obj3.decStr[0] == '0' && obj3.decStr.length() > 1)
                {
                    obj3.decStr.erase(obj3.decStr.begin());
                }
			}

		}
		if (negative == true)       //if negative equals true then add negative to the number
		{
			return '-' + obj3.decStr;
		}

		return obj3.decStr;
	}

	BigDecimalInt operator + (BigDecimalInt& obj)
	{
		BigDecimalInt obj2;

		//make sure length of string2 is larger.
		if (decStr.length() > obj.decStr.length()) //if first one is larger
		{

		    if(decStr[0] == '-' && obj.decStr[0] == '-')    //and both are negative
            {
                decStr.erase(decStr.begin());       //then delete the negative sign
                obj.decStr.erase(obj.decStr.begin());
                negative = true;        //and the result will be negative
            }
            else if(isdigit(decStr[0]) && obj.decStr[0] == '-') //if the second one is negative
            {
                obj.decStr.erase(obj.decStr.begin());       //then delete the negative sign
                obj2.decStr = decStr;    //then the third number will be equal the first one
                return obj2 - obj;      //then return their difference
            }
            else if(decStr[0] == '-' && isdigit(obj.decStr[0])) //if first one is negative
            {
                decStr.erase(decStr.begin());   //then erase negative sign
                obj2.decStr = decStr;       //third number will be equal the first one
                return obj - obj2;          //return their difference
            }
            else
            {           //means that both are psitive in length then the result will be positive
                negative = false;
            }                       //swapping both numbers
			string tmp = decStr;
			decStr = obj.decStr;
			obj.decStr = tmp;
		}
		else if(decStr.length() < obj.decStr.length())      //if second one it's length is less than first one
        {
            if(decStr[0] == '-' && isdigit(obj.decStr[0]))  //if first one is negative
            {
                decStr.erase(decStr.begin());       //then delete the negative sign
                obj2.decStr = decStr;
                return obj - obj2;      //return their difference
            }
            else if(decStr[0] == '-' && obj.decStr[0] == '-')   //if both are negative
            {
                decStr.erase(decStr.begin());       //delete bth negative signs
                obj.decStr.erase(obj.decStr.begin());
                negative = true;        //the result will be negative
            }
            else if(isdigit(decStr[0]) && obj.decStr[0]=='-')       //if second one is negative
            {
                obj.decStr.erase(obj.decStr.begin());   //delete negative sign
                obj2.decStr = decStr;
                return obj2 - obj;  //return their difference
            }
            else
            {
                negative = false;
            }
        }
        else if(decStr.length() == obj.decStr.length())     //if both lengths are equal
        {
            if(decStr[0] == '-' && obj.decStr[0] == '-')        //if both are negative
            {
                decStr.erase(decStr.begin());       //delete negative signs
                obj.decStr.erase(obj.decStr.begin());
                negative = true;        //result will be negative
            }
            else if(isdigit(decStr[0]) && obj.decStr[0] == '-') //if second one is negative
            {
                obj.decStr.erase(obj.decStr.begin());   // delete negative sign
                obj2.decStr = decStr;
                return obj2 - obj;      //return their difference
            }
            else if(decStr[0] == '-' && isdigit(obj.decStr[0]))     //if first one is negative
            {
                decStr.erase(decStr.begin());   //delete negative sign
                obj2.decStr = decStr;
                return obj - obj2;      //return their difference

            }
            else
            {
                negative = false;
            }

        }


		// Take an empty string for storing result
		obj2.decStr = "";

		// Calculate length of both strings
		int number1 = decStr.length(), number2 = obj.decStr.length();

		// Reverse both of strings
		reverse(decStr.begin(), decStr.end());
		reverse(obj.decStr.begin(), obj.decStr.end());

		int carry = 0;
		for (int i = 0; i < number1; i++)
		{
			// calculate sum of current digits and carry
			int sum = ((decStr[i] - '0') + (obj.decStr[i] - '0') + carry);
			obj2.decStr.push_back(sum % 10 + '0');

			// Calculate carry for next step
			carry = sum / 10;
		}

		// Add remaining digits of larger number
		for (int i = number1; i < number2; i++)
		{
			int sum = ((obj.decStr[i] - '0') + carry);
			obj2.decStr.push_back(sum % 10 + '0');
			carry = sum / 10;
		}

		// Add remaining carry
		if (carry)
			obj2.decStr.push_back(carry + '0');

		// reverse resultant string
		reverse(obj2.decStr.begin(), obj2.decStr.end());

        if(negative == true)   //if negative equals true then add negative to the result
        {
            return '-' + obj2.decStr;
        }
		return obj2.decStr;
	}

	friend ostream& operator<<(ostream& out, const BigDecimalInt& b) //cout overloading
	{
		out << b.decStr;   //cout decStr
		return out;
	}





};
int main()
{

		string s , st;
		//int num = 100;
		getline(cin, s);
		BigDecimalInt obj(s);
		getline(cin, st);
		BigDecimalInt obj2(st);
		BigDecimalInt obj3;
		obj3 = obj + obj2;
		cout << obj3;


}


