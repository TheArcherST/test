#include <iostream>

using namespace std;

int BIN_SIZE = sizeof(int) * 8;


int pow (int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}


bool* decimal2binary (int decimal) {
    bool* result = new bool[BIN_SIZE] {};
    
    int i = 0;
    while (decimal) {
        result[BIN_SIZE - i++] = decimal % 2;
        decimal /= 2;
    }

    return result;
}


int binary2decimal (bool arr[BIN_SIZE]) {
    int result = 0;
    
    for (int i = 0; i < BIN_SIZE; i++) {
        if (arr[BIN_SIZE - i]) result += pow(2, i);
    }
    
    return result;
}


void printBinary (bool arr[BIN_SIZE]) {
    bool flag = false;
    
    for (int i = 0; i < BIN_SIZE; i++) {
        if (arr[i]) flag = true;
        if (flag) cout << arr[i] << ' ';
    }
}



int main() {
    for (int i = 0; i < 999; i++) {
        int a = binary2decimal(decimal2binary(i));
        int b = i;
        
        if (a != b) {
            cout << "Test#" << i << " failed, " << a << " != " << b << endl;
            return -1;
        }
    }
    
    cout << "All tests passed" << endl;
}
