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
    vector<string> roasts = {
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code - they negotiate with bugs.",
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed.",
        "{name} is the reason why software engineers have trust issues.",
        "When {name} compiles code, the computer prays for mercy.",
        "{name} treats bugs like features.",
        "{name} code is like a horror movie—you don't want to see what happens next."
    };

    string name;
    cout << "Enter name: ";
    getline(cin, name);
    
    if(name.empty()) {
        cout << "Please enter a valid name." << endl;
        return 0;
    }

    int index = rand() % roasts.size();
    cout << replaceName(roasts[index], name) << endl;

    return 0;
}
