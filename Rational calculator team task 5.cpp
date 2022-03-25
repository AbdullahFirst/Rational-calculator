/******************************************************************************

Author: Abdullah Mohammed Abdullah farg
ID  : 20210541
Author and ID and Group: Selsabeel Asim Ali Elbagir 20210714
Course: CS112
Instructor: Doctor Mohamed_Elramly
Assignment: 2
Taske : 5
Problem 1: Rational Number Calculator

In this application create a rational number calculator that is capable of taking two
rational numbers and an operation to perform on them. Program should handle cases of
–ve numbers and nominator without denominator. It should also use defensive
programming to reject bad inputs.


*******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
void simplify_fraction(int num, int denom);//this function convert decimal number to fraction
void decimalToFraction (double number);//this function used in this function which convert decimal number to fraction
float calc (float  num1,char oprator,float num2);//the function take two numbers and the operator and use them to do the operation
using namespace std;
int main()
{

 for (int m = 1 ; m<=2 ;m++)
 {
   	char  operation[1000] ;
   	char  operators [3];
   	float   numbers[4];
   	int   indx = 0;
    int   min_max[3] ;
    float result1 ,result2 ,result;
    char list1[10] ,list2[10],list3[10],list4[10] ;
    cout << "Please enter you operation"<<endl<<endl;
	cin.getline (operation,10000,'\n');//take the operation from the user in one line without spaces
	cout << endl;
	for (int i = 1 ; i<=strlen(operation);i++)//for loop on the operation to take the operators
	{
	    if (!(isdigit(operation[i]))&&((operation[i + 1]=='-')))//if there are two operator without numbers
                                                                // between them take the first operator only
                                                                // and the second operator used as a sighn for the next number

	    {


            operators[indx] = operation[i];//take the operators form the operation and put it in a list
            min_max[indx] = i;//take the index of the operator and put it in a list

            indx +=1;

            i+=1; // to skip the second operator (the sighn)

	    }
	    else if ((!(isdigit(operation[i]))&&((operation[i + 1])!='-')))
	    {
	        operators[indx] = operation[i]; //take the operators form the operation and put it in a list
            min_max[indx] = i;//take the index of the operator and put it in a list

            indx +=1;

	    }
	}

	indx = 0;//index of the operator
    for (int i = 0 ; i <min_max[0];i++)//form the begin of the operation to the first operator
    {
         list1[indx]=operation[i];//take the first number before the first operator in a list
         indx += 1;
    }
    numbers[0] = atoi(list1);//convert the number form string to integer

    indx = 0;//index of the operator
    for (int i = (min_max[0] + 1) ; i <min_max[1];i++)//form the first operator to the second operator
    {
         list2[indx]=operation[i];//take the second number before the first operator in a list
         indx += 1;
    }
    numbers[1] = atoi(list2);//convert the number form string to integer


    indx = 0;//index of the operator
    for (int i = (min_max[1] + 1) ; i <min_max[2];i++)//form the second operator to the third operator

    {
         list3[indx]=operation[i];//take the third number before the first operator in a list
         indx += 1;
    }
    numbers[2] = atoi(list3);//convert the number form string to integer

    if (strlen(operators)==2)// if the operation was between integer and rational number(the operation has two operator)
    {
        if ((operators[0]=='/')||(operators[0]=='*'))//if the first operator was * or / do it at first
            {
                if ((numbers[1]==0)&& (operators[0]=='/'))//if the denmnator = 0 of the first fraction
                    cout << "Divide by zero is undefined "<<endl;
                else if ((numbers[2]==0)&& (operators[1]=='/'))//if the denmnator = 0 of the second fraction
                    cout << "Divide by zero is undefined "<<endl;
                else
                {
                    result1 = calc(numbers[0],operators[0],numbers[1]);//do the operation between the first number and the second number using the first operator
                    result2 = calc(result1 , operators[1],numbers[2]);//do the operation between result1 number and the third number using the second operator
                }
            }
        else //if the first operator was + or - skip it and do the second operator at the first and it at the second
        {
            if ((numbers[2]==0)&& (operators[1]=='/'))//if the denmnator = 0 of the second fraction
                    cout << "Divide by zero is undefined "<<endl;
            else
            {
                result1 = calc(numbers[1],operators[1],numbers[2]);//do the operation between the second number and the third number using the second operator
                result2 = calc(result1 , operators[0],numbers[0]);//do the operation between result1 number and the first number using the first operator
            }
        }
        cout<< "Result = " ;
        decimalToFraction(result2);//output the result for the user as a fraction

    }
    else if (strlen(operators)>=3)//if the operation was between two rational numbers
    {
          indx = 0;//index of operator
        for (int i = (min_max[2] + 1) ; i <=strlen(operation);i++)//from the third operator to the end of the operation
        {
             list4[indx]=operation[i];//take the forth number in a list
             indx += 1;
        }
        numbers[3] = atoi(list4);//convert the number from the string to the integer number
    if ((numbers[1]==0)||(numbers[3]==0))//if the danmanator of the second fraction = 0
      cout << "Divide by zero is undefined "<<endl;//
    else
      {
        result1 = calc(numbers[0],operators[0],numbers[1]);//do the operation between the first number and the second number using the first operator
        result2 = calc(numbers[2],operators[2],numbers[3]);//do the operation between the third number and the forth number using the first operator
        result = calc(result1,operators[1],result2);//do the operation between the result1 and result2 using the second operator
        cout<< "Result = " ;
        decimalToFraction(result);//output the result for the user as a fraction
      }
    }
 }
   return 0;


}
float calc (float  num1,char oprator,float num2)//the function take two numbers and the operator and use them to do the operation
{
    	float result ;
   if (oprator == '+')
		result = num1 + num2;
   else if(oprator == '-')
		result = num1 - num2;
   else if(oprator == '/')
		result = num1 / num2;
   else if(oprator == '*')
		result = num1 * num2;
   return result ;
}

void decimalToFraction (double number)
{


  if ( floor(number) == ceil(number) )
    cout << number ;
  else
  {
      double fractional_part = number - floor(number);

     for (double i = 0.1, j = 10;  ; i/=10, j*=10)
     {
      if ( fractional_part >= i )
      {
       simplify_fraction(number * j, j);
       break;
      }
     }
  }


}


void simplify_fraction(int num, int denom)
{
 for (int i = denom; i>=2; i--)
 {
  if (num % i == 0 && denom % i == 0)
  {
   num = num/i;
   denom = denom/i;
  }
 }
 cout << "Fraction: ";
 if (denom == 1)
  cout << num;
 else
  cout << num << "/" << denom;
 cout << endl;
}




