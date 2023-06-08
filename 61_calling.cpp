#include<iostream>

void simple();
int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "main() will call the simple() function:\n";
    simple();
    cout << "main() is finished with the simple() function.\n";
        
    return 0;
}

void simple()
{
    using namespace std;
    cout << "I'm but a simple function.\n";
}
