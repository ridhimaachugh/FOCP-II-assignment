#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>    

using namespace std;

string replaceName(string templateStr, string name) {
    size_t pos = templateStr.find("{name}");
    if (pos != string::npos) {
        templateStr.replace(pos, 6, name);
    }
    return templateStr;
}

int main() {
    srand(time(0));
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} couldn't finish the assignment because the laptop decided to install updates.",
        "{name} was about to complete the homework when the power went out.",
        "{name} tried saving the work, but the hard drive failed.",
        "{name} thought the deadline was tomorrow.",
        "{name} was busy rescuing a cat from a tree.",
        "{name} had a sudden emergency that required immediate attention.",
        "{name} could not access the portal due to server maintenance."
    };

    string name;
    cout << "Enter student name: ";
    getline(cin, name);
    
    if(name.empty()) {
        cout << "Name cannot be empty." << endl;
        return 0;
    }

    int index = rand() % excuses.size();
    cout << replaceName(excuses[index], name) << endl;

    return 0;
}
