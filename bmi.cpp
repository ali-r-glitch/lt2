// KJN - it is good practice to insert comment about intended use, context, contributors, etc
// This code calculates bmi. It takes a unique code ,stone, poundsm 
//ounces, feet,inches. They should seperated by a space . It then output 
// id and score 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//converts the weight in ounces to pounds
double ounces2pounds(int x)
{
    return(x/16.0);
}
//converts from  stones to pounds
int stones2pounds(char x)
{
    return(x*114);
}
//converts total weight to metric kilgrams
double weight2kg(int stones, int pounds, int ounces)
{
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}
//calculates the total height in meters
double height2metres(int feet, int inches)
{
    return (((feet*12) + inches) *0.0254);
}

char categorise(double kg, double metre)
{//groups the bmi toa responding symbol 
    double bmi = kg/(metre*metre);
    char cat;
       if (bmi < 19)
        return 'A';
    else if (bmi <= 26)
        return 'B';
    else if (bmi <= 30)
        return 'C';
    else
        return 'D';
}

void process_data(char* input_file, char* output_file)
{//gets infromation and strips it into  variables 
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet, inches;
    double kg, m;
    int cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> person_id >>stones>> pounds >> ounces >> feet >> inches;
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),int(inches));
        cat=categorise(kg,m);
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}

int main(int argc, char *argv[])
{
if(argc==3)    // KJN - Need to check that 3 arguments were supplied upon execution
{    
process_data(argv[1], argv[2]);
}
return -1;
}
