#include <iostream>
#include <cmath>
using namespace std;

 struct Point
 {
   float x, y;
     
     
 };
 
  float calculateDistance (Point* pt1, Point* pt2)
 {
   float tempX,tempY,distance;
   tempX=tempY=distance=0;
   
  
  tempX= (pt2->x - pt1->x);
  
  tempY= (pt2->y - pt1->y);
  
  distance= sqrt( pow(tempX,2) + pow(tempY, 2) );
  
  return distance;
 
 
 }


int main()
{
 Point p1, p2;
 
  cout << "Please enter your first coordinate (x then y)\n";
  cin >> p1.x;
  cin >> p1.y;
  
 
  
  cout << "Please enter your second coordinate (x then y)\n";
  cin >> p2.x;
  cin >> p2.y;
  
  cout << "The distance between point (" << p1.x <<","<< p1.y <<") and point (" << p2.x << "," << p2.y <<") is: ";
  cout << calculateDistance(&p1, &p2) << endl;
   
return 0;    
}

    