#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::string;
using std::list;
using std::endl;

// Python like print function
void print() { cout << '\n'; }
template <typename T, typename ...TAIL>
void print (const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

bool strongPasswordCheckerII(string password) {
       if (password.length() < 8)
            return false;

        bool lower, upper, digit, special, consecutive;

        string specialchars = "!@#$%^&*()-+";

        for (int i = 0; i < password.length(); i++)
        {
            char ch = password[i];

            if (islower(ch))
                lower = true;

            if (isupper(ch))
                upper = true;

            if (isdigit(ch))
                digit = true;

            if (specialchars.find(ch) < specialchars.length())
                special = true;

            if (ch == password[i + 1]){

                consecutive = true;

            }
            
        }

        // print(lower, upper, digit, special, consecutive);

        if (lower and upper and digit and special and not consecutive)
            return true;

        else return false;
    }

int main()
{
    cout << strongPasswordCheckerII("IloveLe3tcode!");
    return 0;
}
