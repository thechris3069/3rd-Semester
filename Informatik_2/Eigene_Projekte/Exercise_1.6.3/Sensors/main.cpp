#include <iostream>
#include <fstream>
#include <string>

int main ()
{
std::string filename (" test .bin");
{
std::ofstream ostrm ( filename , std::ios :: binary );
int value = 42;
ostrm . write ( reinterpret_cast < char * >(& value ), sizeof value );
ostrm << " hello " << '\n';
}
std::ifstream istrm ( filename , std::ios :: binary );
int value ;
istrm . read ( reinterpret_cast < char * >(& value ), sizeof value );
std::string s;
istrm >> s;
std::cout << "I got: " << value << " " << s << '\n';
return 0;
}
