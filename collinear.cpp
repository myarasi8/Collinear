//Mahesh Yarasi
//Partner: Tiffany Wu

//To compile I used a make and file and ./hw4
//I used pairs of sets by making each coordinate pain the "origin" to compute the slopes in comparison
//to all the other points. So, I used a foor loop with a for loop inside of it which is O(n^2) and I had to use a loop to print 
//the contents. This amounts to a runtime of O(n^2)

#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <cmath>
#include <vector>
using namespace std;


int collinear(string filename)
{
	string word = "first";
	int increment = 0;
	float slope = 0;
	float vecSize = 0;


	vector <float> commonSlope;

	//Used pairs for the x and y coordinates and then put them in sets to organize them.
	//Also used iterators to iterate through the sets
	pair <float, float> coordinate1;
	set <pair <float, float> > coordinateSet;
	pair < float, pair < float, float> > coordinateSlope;

	set < pair < float, pair < float, float> > >coordinateSetSlope;

	//the points of the slopes that occur most
	pair <float, float> slopeIntercept;
	set <pair <float, float> >repeatingSlopeInterceptCoords;
	

	float value;

	ifstream myfile;
	myfile.open(filename); //opens file

	if (!myfile.is_open()) //checks if file is open
		cout << "not open" << endl;
	else
	{
		//Loops through the input file until the end and stores the numbers into pairs to create a set called CoordinateSet
		while (!myfile.eof())
		{
			if (word == "first")
			{
				myfile >> value;
				int length = value;
				word = "";
			}
			else
			{
				if (increment == 0)
				{
					myfile >> value;
					coordinate1.first = value;
					increment = 1;
				}
				else
				{
					myfile >> value;
					coordinate1.second = value;
					coordinateSet.insert(coordinate1);
					cout << "coordinate1.first: " << coordinate1.first << " coordinate1.second: " << coordinate1.second << endl;
					increment = 0;					
				}
			}
		}

		/*used for printing coordinateSet*/
		//set <pair <float, float> >::iterator it;

		//for (it=coordinateSet.begin(); it!=coordinateSet.end(); ++it)
		//{
		//	cout << ' ' << (*it).first;
        //	cout << ' ' << (*it).second;
        //	cout << '\n';
    	//}

    	//Loops through each coordinate pair in coordinateSet to individuall calculate the slopes with respect to the firstcalue as the origin. 
    	//This is stored in a set that 
    	set <pair <float, float> >::iterator it;
		for (it=coordinateSet.begin(); it!=coordinateSet.end(); ++it)
		{
			float x_temp = (*it).first;
			float y_temp = (*it).second;

			//cout << "x_temp: " << x_temp << " y_temp: " << y_temp << endl;
			set <pair <float, float> >::iterator it2;
			for (it2=coordinateSet.begin(); it2!=coordinateSet.end(); ++it2)
			{
				if ((*it2).first != x_temp && (*it2).second != y_temp)
				{
					float dx = ((*it2).first)-(x_temp);
					float dy = ((*it2).second)-(y_temp);
					slope = abs(dy/dx);

					coordinateSlope.first = slope;
					coordinate1 = (*it2);
					//cout << (*it).first << (*it).second << endl;
					coordinateSlope.second = coordinate1;
					coordinateSetSlope.insert(coordinateSlope);
				}
			}
			set < pair < float, pair <float, float> > >::iterator it3;
			for (it3=coordinateSetSlope.begin(); it3!=coordinateSetSlope.end(); ++it3)
       		{
       		//cout << "here2" << endl;
       		//if ((*it3).first)
       	 	   	cout << ' ' << (*it3).first << ",";
         	  	cout << ' ' << '(' <<(*it3).second.first;
         	  	cout << ' ' << (*it3).second.second << ')';
          	 	cout << '\n';
          	 	vecSize += 1;
       		}

       		//cout << "vecSize: " << vecSize << endl;

       		//y-intercept --> b = y - mx
			set < pair < float, pair <float, float> > >::iterator it5;
       		for (it5=coordinateSetSlope.begin(); it5!=coordinateSetSlope.end(); ++it5)
       		{
       			//b = y-mx
       			float y_int = ((*it5).second).second - ((*it5).first) * ((*it5).second).first;
       			cout << "y_int: " << y_int << endl; 
       		}

       		coordinateSetSlope.clear();
       		cout << '\n';
		}

	}


	myfile.close();
	return 0;
}

int main()
{
	collinear("points.txt");
}
       			//slopeIntercept.second = y_int;
       			//cout << "slopeIntercept: " << slopeIntercept.second << endl;


