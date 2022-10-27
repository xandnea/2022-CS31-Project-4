#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int appendToAll(string a[], int n, string value) {
    
    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int i = 0; i < n; i++) {
        a[i] += value;
        cout << a[i] << endl;
    }

    return n;
}

int lookup(const string a[], int n, string target) {

    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }

    cerr << "Target not found in array, Return code: ";
    return -1;
}

int positionOfMax(const string a[], int n) {
    string max = a[0];
    int empty = 0;

    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < max.size(); j++) {
            //cout << "array is at " << a[i] << " : " << a[i][j] << " max is " << max << " : " << max[j] << endl;
            if (a[i][j] < max[j]) {
                break;
            } else if (a[i][j] > max[j]) {
                max = a[i];
                break;
            }
        }  
    }

    if (empty == n) {
        cerr << "No interesting elements in array, Return code: ";
        return -1;
    }

    cout << max << endl;
    return lookup(a, n, max);
}

int rotateLeft(string a[], int n, int pos) {
    
    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    } else if (n <= pos) {
        cerr << "String in position " << pos << " is already on the right or is non-existant, Return code: ";
        return -2;
    }

    string temp = a[pos];

    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    a[n - 1] = temp;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return pos;
}

int countRuns(string a[], int n) {
    int runs = 0;

    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i + 1] != a[i]) {
            runs++;
        }
    }

    return runs;
}


int flip(string a[], int n) {
    int i = 0; 
    int j = n - 1;
    string temp;

    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    while (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2) {
    int i = 0;
    
    if ((n1 < 0) || (n2 < 0)) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    while ((i <= n1) && (i <= n2)) {
        if (a1[i] != a2[i]) {
            return i;
        }
        
        i++;
    }

    if (n1 <= n2) {
        return n1;
    } else {
        return n2;
    }
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
    int count = 0;

    if ((n1 < 0) || (n2 < 0)) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int i = 0; i < n1; i++) {
        if (a1[i] == a2[count]) {
            count++;
            if (count == n2) {
                return ((i + 1) - n2);
            }
        } else {
            count = 0;
        }
    }

    return -1;
}


int lookupAny(const string a1[], int n1, const string a2[], int n2) {

    if ((n1 < 0) || (n2 < 0)) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a1[i] == a2[j]) {
                return i;
            }
        }
    }

    return -1;
}

int split(string a[], int n, string splitter) {
    string current;
    string temp;
    int sorted = 0;
    int splitPoint = 0;

    if (n < 0) {
        cerr << "N is less than zero, Return code: ";
        return -1;
    }

    for (int sort = 0; sort <= (n - sorted); sort++) {
        for (int i = 1; i < n; i++) {
            current = a[i - 1];
            for (int j = 0; j < current.size(); j++) { // tony dave tim jon // "b", "d", "g", "f", "e", "c", "a"
                if (a[i][j] < current[j]) {
                    temp = a[i];
                    a[i] = current;
                    a[i - 1] = temp;

                    if (i == (n - 1)) {
                        sorted++;
                    }
                    break;
                }
                else if (a[i][j] > splitter[j]) {
                    break;
                }
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "Splitter: " << splitter << " position: ";*/

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < splitter.size(); j++) {
            if (a[i][j] < splitter[j]) {
                break;
            }
            else if (a[i][j] > splitter[j]) {
                return i;
                break;
            }
        }
    }
}

int main() {
    string people[5] = { "boris", "gordon", "rishi", "liz", "john" };
    string pm_one[6] = { "david", "liz", "margaret", "tony", "gordon", "boris" };
    string pm_two[6] = { "david", "tonz", "margaret", "tony", "gordon", "boris" };
    string mp[5] = { "john", "david", "liz", "theresa", "margaret" };
    string alpha[7] = { "a", "b", "c", "d", "e", "f", "g" };
    string alpha2[7] = { "b", "d", "g", "f", "e", "c", "a" };
    string empty[3] = { "", "", "" }; 
    string d_one[9] = { "tony", "boris", "rishi", "rishi", "gordon", "gordon", "gordon", "rishi", "rishi" };
    string d_two[9] = { "tony", "tony", "tony", "tony", "rishi", "rishi", "rishi", "rishi", "rishi" };
    string d_three[9] = { "tony", "tony", "tony", "rishi", "rishi", "gordon", "rishi", "rishi", "rishi" };
    string leader[6] = { "boris", "rishi", "", "tony", "theresa", "david" };
    string politician[5] = { "boris", "rishi", "david", "", "tony" };
    string names[10] = { "john", "margaret", "theresa", "rishi", "boris", "liz", "john", "rishi" };
    string names1[10] = { "margaret", "theresa", "rishi" };
    string names2[10] = { "john", "rishi" };
    string set1[10] = { "david", "boris", "rishi", "margaret" };
    string set2[10] = { "tony", "gordon" };
    string set3[10] = { "gordon", "david", "liz" };
    
    /*cout << appendToAll(people, 5, "!!!") << endl;
    cout << appendToAll(people, -1, "!!!") << endl;
    cout << appendToAll(people, 5, "") << endl;*/
    
    /*cout << lookup(people, 5, "john") << endl;  
    cout << lookup(people, 5, "joHn") << endl;
    cout << lookup(people, -2, "john") << endl;*/

    /*cout << positionOfMax(people, 5) << endl;
    cout << positionOfMax(pm_two, 6) << endl;
    cout << positionOfMax(pm_one, 6) << endl;
    cout << positionOfMax(alpha, 7) << endl;
    cout << positionOfMax(people, -2) << endl;
    cout << positionOfMax(empty, 3) << endl;*/

    /*cout << rotateLeft(people, 5, 5) << endl;
    cout << rotateLeft(pm_one, 5, 2) << endl;
    cout << rotateLeft(mp, 5, 1) << endl;
    cout << rotateLeft(pm_one, -1, 2) << endl;*/

    /*cout << countRuns(d_one, 9) << endl;
    cout << countRuns(d_two, 9) << endl;
    cout << countRuns(d_three, 9) << endl;
    cout << countRuns(d_three, -3) << endl;*/

    /*cout << flip(leader, 4) << endl;
    for (int i = 0; i < 6; i++) {
        cout << '"' << leader[i] << '"' << " ";
    }
    cout << endl;
    cout << flip(leader, -4) << endl;*/

    //cout << differ(leader, 6, politician, 5) << endl;  //  returns 2
    //cout << differ(leader, 2, politician, 1) << endl;  //  returns 1
    //cout << differ(leader, 2, politician, -100) << endl;  //  returns -1
    //cout << differ(leader, -20, politician, 5) << endl;  //  returns -1

    //cout << subsequence(names, 6, names1, 3) << endl;  // returns 1
    //cout << subsequence(names, 5, names2, 2) << endl;  // returns -1
    //cout << subsequence(names, 8, names2, 2) << endl;  // returns 6
    //cout << subsequence(names, -8, names2, 2) << endl;  // returns -1
    //cout << subsequence(names, 8, names2, -2) << endl;  // returns -1

    //cout << lookupAny(names, 6, set1, 4) << endl;  // returns 1 (a1 has "margaret" there)
    //cout << lookupAny(names, 6, set2, 2) << endl;  // returns -1 (a1 has none)
    //cout << lookupAny(names, 6, set3, 3) << endl;  // returns 5
    //cout << lookupAny(names, 6, set3, -3) << endl;  // returns -1
    //cout << lookupAny(names, -6, set3, 3) << endl;  // returns -1

    //cout << split(alpha2, 7, "d") << endl; // returns 4
    //cout << split(names, 6, "test") << endl; // returns 5
    //cout << split(pm_one, 6, "john") << endl; // returns 3
    //cout << split(pm_one, -6, "john") << endl; // returns -1
}