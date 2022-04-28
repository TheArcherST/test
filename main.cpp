#include <fstream>
#include <iostream>
#include <string>
#include <malloc/malloc.h>


using namespace std;


void writeIntoFile (string path, string* content, int content_length) {
    ofstream stream {path};
    
    for (int i = 0; i < content_length; i++) {
        cout << content[i] << endl;
        stream << content[i] << endl;
    }
    
    stream.close();
}

string* readFromFile (string path) {
    int length = 0;
    fstream stream {path};
    string buff;
    while (getline(stream, buff)) {
        length++;
    }
    stream.close();
    stream.open(path);
    string* result = new string[length];
    int counter = 0;
    while (getline(stream, buff)) {
        result[counter++] = buff;
    }
    stream.close();
    return result;
}


int main() {
    string path = "/Users/mihailsapovalov/Desktop/C++/itstep/itstep/itstep/Empty.txt";
    int size = 2;
    string* content = new string[size] {"123", "12343"};
    writeIntoFile(path, content, size);
}
