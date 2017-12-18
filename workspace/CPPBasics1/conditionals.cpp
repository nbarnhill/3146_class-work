#include <iostream>
using namespace std;

int main()
{
    int input;
    bool error;
    
    do{
        
    input=0;
    error=false;
    
    cout << "Please enter your grade on the most recent exam.\n";
    
    cin>> input;
    
   if(input>=90 && input<=100)
        cout<< "You received an A based on the current 10 pt grading scale.\n";
    
    else if(input>=80 && input<=89)
        cout<< "You received an B based on the current 10 pt grading scale.\n";
    
    else if(input>=70 && input<=79)
        cout<< "You received an C based on the current 10 pt grading scale.\n";
    
    else if(input>=60 && input<=69)
        cout<< "You received an D based on the current 10 pt grading scale.\n";
    
    else if(input<60)
        cout<< "You received an F based on the current 10 pt grading scale.\n";
    
    else
    {
        cout << "***ERROR*** Please enter a value on a scale of 0-100\n";
        error=true;
        //decided to add a do while loop in order to allow both the graded
        // as well as the user to enter a variety of data
    }
    }while(error);
    
    return 0;
}