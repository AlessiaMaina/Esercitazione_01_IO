#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

// Function to map points in the interval [-1,2]
double mapPoint(double inputVal)
{
    return(((inputVal-1)*(3./4))-1);    // Definition of the function
}


int main()
{
    std::string fileNameInput = "data.csv";    // Opening the Input File, called "data.csv"
    std::fstream fstr;
    fstr.open(fileNameInput);

    if(fstr.fail())
    {
        std::cerr << " ATTENTION: File doesn't exist! " << std::endl;    // Type of error
        return 1;
    }


    std::ofstream fileNameOutput("result.csv");    // Making an Output File, called "result.csv"
    std::string header = "#  N Mean";
    fileNameOutput << header << std::endl;    // Print # N mean on the Output File

    double value;
    double sumValues = 0;    // Sum initialized to zero
    int countVal = 0;    // It's a Counter, initialized to zero
    while(fstr >> value)
    {
        countVal++;
        // Application of the FUNCTION THAT MAPS POINTS IN THE INTERVAL [−1,2]
        value = mapPoint(value);
        sumValues += value;
        // Definition of COMPUTE THE MEAN OF THE FIRST i MAPPED VALUES
        double meanValues = sumValues/countVal;
        // Print the result on the Output File
        fileNameOutput << std::fixed << std::setprecision(16) << std::scientific << countVal << "  " << meanValues << std::endl;
    }

    fstr.close();
    fileNameOutput.close();

    return 0;
}

