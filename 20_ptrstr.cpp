#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    using namespace std;

    char animal[20] = "bear";//animal holds bear
    const char * bird = "wren";//bird holds wren
    char * ps;// uninitialized

    cout << animal << " and "//dispaly bear
         << bird << "\n";//display wren
    // cin >> ps; may display garbage, may cause a crash
    cout << "Enter a kind of animal: ";
    cin >> animal;//ok if input < 20 chars
    // cin >> ps;Too horiable a bluner to try; ps does't to allocate space
    ps = animal;// set ps to point to string
    cout << ps << "!\n";//ok some as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    // ps = animal;
    // cout << ps << "!\n";
    // cout << "Before using strcpy():\n";
    // cout << animal << " at " << (int *) ps << endl;

    ps = new char[strlen(animal) + 1];//get new storage
    strcpy(ps, animal);//copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    delete [] ps;

    return 0;
}
