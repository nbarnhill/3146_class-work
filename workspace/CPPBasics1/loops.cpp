#include <iostream>
using namespace std;

int main()
{
    double sum, average, temp, positive, negative, zeros;
    sum=average=temp=positive=negative=zeros=0;
    cout << "Please enter 10 random whole numbers (sign does not matter)\n ";
    for (int x=0; x<10; x++)
    {
       
        cin >> temp;
        sum+=temp;
        if (temp>0)
        positive++;
        else if (temp<0)
        negative++;
        else
        zeros++;
        
    }
    
    average=sum/10;
    
    cout << "\n";
    
    cout<< positive <<" of the numbers you entered were positive. \n";
    
    cout<< negative <<" of the numbers you entered were negative. \n";
    
    cout<< sum <<" is the sum of all of the numbers you entered. \n";
    
    cout<< average <<" is the average of all the numbers you entered. \n";
    
    return 0;
}