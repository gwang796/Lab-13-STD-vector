//
//  main.cpp
//  COMSC-210 | Lab 13: Lab 12: STD::vector | Guo An Wang
//  IDE used: Xcode
//  Created by Guo An Wang on 9/19/25.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    vector <int> weather; //declaring STD::vector weather with data type int
    ifstream inputFile("weather.txt"); //accessing external data file with 30 elements
    if (!inputFile) { //checks if weather.txt is accessible
        cout << "Error: Could not access input file" << endl;
        return 1;//exit program with error code
    }
    
    //copies values from weather.txt to temp variable then
    //temp variable is pushed back(added) to STD::vector
    //also checks to make sure there is enough elements to weather.txt
    //or else returns an error
    int temp;
    while (inputFile >> temp) {
        weather.push_back(temp);
    }
    inputFile.close(); //close input file
    
    cout << "1. Number of Days: " << weather.size() << endl; //print size of weather container
    cout << "\n2. First Day: " << weather.front() << endl; //print first value of container
    cout << "\n3. Last Day: " << weather.back() << endl; //prints last value of container
    cout << "\n4. Empty?: ";
    //checks if container is empty
    if (weather.empty()==0) {
        cout << "False" << endl;
    } else {
        cout << "True" << endl;
    }
    cout << "\n5. Highest Temperature: " << *max_element(weather.begin(),weather.end()) << endl; //finding max
    cout << "\n6. Lowest Temperature: " << *min_element(weather.begin(),weather.end()) << endl; //min
    cout << "\n7. Sum of temperatures: " << accumulate(weather.begin(),weather.end(),0) << endl; //sum
   vector<int> week1(weather.begin(),weather.begin() + 7); //declaring new STD::array week1, for first week temperature highs
    //prints each day temperature high
    cout << "\n8. Week 1: " << endl;
    int day = 1; //integer value for day
    for (int value : week1) {
        cout << "Day " << (day) << ": " << value << endl;
        day++;
    }
    //sort weather from least to greatest
    sort(weather.begin(),weather.end());
    cout << "\n9. Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " ";
    }
    cout << endl;
    //sort weather from biggest to smallest
    sort(weather.rbegin(),weather.rend());
    cout << "\n10. Reverse Sorted Weather Days: ";
    for (int value: weather) {
        cout << value << " ";
    }
    cout << endl;
    int target = 75;
    vector <int> :: iterator it;
    it = find(weather.begin(),weather.end(),target);
    cout << "\n11. Value " << target;
    if (it !=weather.end()) {
        cout << " found in position " << it - weather.begin() << endl;
    } else {
        cout << " was not found" << endl;
    }
    cout << "   Value: " << *it << endl;
    return 0;
}
