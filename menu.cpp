#include "menu.h"
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <iomanip>
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

using namespace std;

void displayMenu(const string& studentID, const string& studentName, const string& filterCriteria, const string& sortCriteria, const string& sortOrder) {
    cout << endl;
    cout << "Student ID   : " << studentID << endl;
    cout << "Student Name : " << studentName << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Welcome to Assn3 program!" << endl;
    cout << endl;
    cout << "1)   Read in data" << endl;
    cout << "2)   Specify filtering criteria (current : " << filterCriteria << ")" << endl;
    cout << "3)   Specify sorting criteria (current : " << sortCriteria << ")" << endl;
    cout << "4)   Specify sorting order (current : " << sortOrder << ")" << endl;
    cout << "5)   View data" << endl;
    cout << "6)   Store data" << endl;
    cout << "7)   Quit" << endl;
    cout << endl;
    cout << "Please enter your choice : ";
}

//Function menu for the main criteria (Point2D, Line3D etc..)
void specifyFilterCriteria(string& filterCriteria, string& sortCriteria) {
    cout << "\n[ Specifying filtering criteria (current : " << filterCriteria << ") ]" << endl;
    cout << endl;
    cout << "   a)   Point2D records" << endl;
    cout << "   b)   Point3D records" << endl;
    cout << "   c)   Line2D records" << endl;
    cout << "   d)   Line3D records" << endl;
    cout << endl;
    cout << "   Please enter your criteria (a - d) : ";
    char choice;
    cin >> choice;

    switch (choice) {
        case 'a':
            filterCriteria = "Point2D";
            sortCriteria = "x-ordinate"; // Default sorting for Point2D
            break;
        case 'b':
            filterCriteria = "Point3D";
            sortCriteria = "x-ordinate"; // Default sorting for Point3D
            break;
        case 'c':
            filterCriteria = "Line2D";
            sortCriteria = "Pt. 1"; // Default sorting for Line2D
            break;
        case 'd':
            filterCriteria = "Line3D";
            sortCriteria = "Pt. 1"; // Default sorting for Line3D
            break;
        default:
            cout << "Invalid choice! Keeping current filter criteria." << endl;
            return;
    }
    cout << "   Filter criteria successfully set to '" << filterCriteria << "'!" << endl;
    cout << endl;
}

//Function menu for the sort sub-criterias (x, y or z and scalarValue)
void specifySortingCriteria(const string& filterCriteria, string& sortCriteria) {
    cout << "\n[ Specifying sorting criteria (current : " << sortCriteria << ") ]" << endl;
    cout << endl;
    string endOption;

    if (filterCriteria == "Point2D") {
        endOption = "c";
        cout << "   a) x-ordinate value" << endl;
        cout << "   b) y-ordinate value" << endl;
        cout << "   c) Dist. Fr Origin value" << endl;
    } else if (filterCriteria == "Point3D") {
        endOption = "d";
        cout << "   a) x-ordinate value" << endl;
        cout << "   b) y-ordinate value" << endl;
        cout << "   c) z-ordinate value" << endl;
        cout << "   d) Dist. Fr Origin value" << endl;
    } else if (filterCriteria == "Line2D") {
        endOption = "c";
        cout << "   a) Pt. 1's (x, y) values" << endl;
        cout << "   b) Pt. 2's (x, y) values" << endl;
        cout << "   c) Length value" << endl;
    } else if (filterCriteria == "Line3D") {
        endOption = "c";
        cout << "   a) Pt. 1's (x, y) values" << endl;
        cout << "   b) Pt. 2's (x, y) values" << endl;
        cout << "   c) Length value" << endl;
    } else {
        cout << "Invalid filter criteria!" << endl;
        return;
    }

    cout << "\n   Please enter your criteria " << "(a - " + endOption +")" <<" :";
    char choice;
    cin >> choice;

    if (filterCriteria == "Point2D") {
        switch (choice) {
            case 'a':
                sortCriteria = "x-ordinate";
                break;
            case 'b':
                sortCriteria = "y-ordinate";
                break;
            case 'c':
                sortCriteria = "Dist. Fr Origin value";
                break;
            default:
                cout << "Invalid choice! Keeping current sorting criteria." << endl;
                return;
        }
    } else if (filterCriteria == "Point3D") {
        switch (choice) {
            case 'a':
                sortCriteria = "x-ordinate";
                break;
            case 'b':
                sortCriteria = "y-ordinate";
                break;
            case 'c':
                sortCriteria = "z-ordinate";
                break;
            case 'd':
                sortCriteria = "Dist. Fr Origin value";
                break;
            default:
                cout << "Invalid choice! Keeping current sorting criteria." << endl;
                return;
        }
    } else if (filterCriteria == "Line2D") {
        switch (choice) {
            case 'a':
                sortCriteria = "Pt. 1";
                break;
            case 'b':
                sortCriteria = "Pt. 2";
                break;
            case 'c':
                sortCriteria = "Length";
                break;
            default:
                cout << "Invalid choice! Keeping current sorting criteria." << endl;
                return;
        }
    } else if (filterCriteria == "Line3D") {
        switch (choice) {
            case 'a':
                sortCriteria = "Pt. 1";
                break;
            case 'b':
                sortCriteria = "Pt. 2";
                break;
            case 'c':
                sortCriteria = "Length";
                break;
            default:
                cout << "Invalid choice! Keeping current sorting criteria." << endl;
                return;
        }
    }

    cout << "\n   Sorting criteria successfully set to '" << sortCriteria << "'!" << endl;
}



void readDataFromFile(const string& filename,
                      vector<Point2D>& point2DRecords,
                      vector<Point3D>& point3DRecords,
                      vector<Line2D>& line2DRecords,
                      vector<Line3D>& line3DRecords) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    //Set allows us to insert unique record which will
    //eliminate duplicates
    set<string> uniqueLines;
    string line;

    // Regex patterns
    regex point2DRegex(R"(Point2D,\s+\[\s*(-?\d+),\s*(-?\d+)\s*\])");
    regex point3DRegex(R"(Point3D,\s+\[\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s*\])");
    regex line2DRegex(R"(Line2D,\s+\[\s*(-?\d+),\s*(-?\d+)\s*\],\s+\[\s*(-?\d+),\s*(-?\d+)\s*\])");
    regex line3DRegex(R"(Line3D,\s+\[\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s*\],\s+\[\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s*\])");

    smatch match;


    while (getline(file, line)) {
        
        // Skip duplicate lines
        if (!uniqueLines.insert(line).second) {
            continue;
        }

        // Parse Point2D records
        if (regex_match(line, match, point2DRegex)) {
            int x = stoi(match[1].str());
            int y = stoi(match[2].str());
            point2DRecords.emplace_back(x, y);
            
        }
        // Parse Point3D records
        else if (regex_match(line, match, point3DRegex)) {
            int x = stoi(match[1].str());
            int y = stoi(match[2].str());
            int z = stoi(match[3].str());
            point3DRecords.emplace_back(x, y, z);
    
        }
        // Parse Line2D records
        else if (regex_match(line, match, line2DRegex)) {
            int x1 = stoi(match[1].str());
            int y1 = stoi(match[2].str());
            int x2 = stoi(match[3].str());
            int y2 = stoi(match[4].str());
            line2DRecords.emplace_back(Point2D(x1, y1), Point2D(x2, y2));
            
        }
        // Parse Line3D records
        else if (regex_match(line, match, line3DRegex)) {
            int x1 = stoi(match[1].str());
            int y1 = stoi(match[2].str());
            int z1 = stoi(match[3].str());
            int x2 = stoi(match[4].str());
            int y2 = stoi(match[5].str());
            int z2 = stoi(match[6].str());


            // Ensure correct construction of Line3D object
            line3DRecords.emplace_back(Point3D(x1, y1, z1), Point3D(x2, y2, z2));
        }
    }

    file.close();
    int totalRecords = point2DRecords.size() + point3DRecords.size() + line2DRecords.size() + line3DRecords.size();
    cout << "\n" << totalRecords << " records read in successfully!" << endl;
    cout << "\nGoing back to main menu ..." << endl;
}

//Ascending or Descending
void specifySortingOrder(string& sortOrder) {
    cout << "\n[ Specifying sorting order (current : " << sortOrder << ") ]" << endl;
    cout << endl;
    cout << "   a) ASC (Ascending order)" << endl;
    cout << "   b) DSC (Descending Order)" << endl;
    cout << "\n   Please enter your choice (a - b): ";
    char choice;
    cin >> choice;

    if (choice == 'a' || choice == 'A') {
        sortOrder = "ASC";
    } else if (choice == 'b' || choice == 'B') {
        sortOrder = "DSC";
    } else {
        cout << "Invalid choice! Keeping current sorting order." << endl;
    }
    cout << "   Sorting order successfully set to '" << sortOrder << "'!" << endl;
}


//Filtering section

//Filter function for Point2D
void filterAndSortPoint2D(vector<Point2D>& point2DRecords, const string& sortCriteria, const string& sortOrder) {
    // Step 1: Copy the records (no need to modify the original data)
    vector<Point2D> filteredRecords = point2DRecords;

    // Step 2: Sort based on the selected sort criteria and order
    if (sortCriteria == "x-ordinate") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point2D::compareByX_ASC : Point2D::compareByX_DESC);
    } else if (sortCriteria == "y-ordinate") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point2D::compareByY_ASC : Point2D::compareByY_DESC);
    } else if (sortCriteria == "Dist. Fr Origin value") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point2D::compareByDistance_ASC : Point2D::compareByDistance_DESC);
    }

    // Step 3: Display the sorted records
    cout << "\n[ View data ... ]" << endl;
    cout << " filtering criteria : " << "Point2D" << endl;
    cout << " sorting criteria : " << sortCriteria << endl;
    cout << " sorting order : " << sortOrder << endl;
    cout << endl;

    //Header formatting
    cout << setw(5) << "X" << setw(6) << "Y";
    cout << setw(19) << "Dist. Fr Origin";
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;

    for (const auto& point : filteredRecords) {
        cout << "[" << setw(4) << point.getX() << ", " 
             << setw(4) << point.getY() << "]   "
             << fixed << setprecision(3) << point.getScalarValue() << endl;
    }

    if (filteredRecords.empty()) {
        cout << "No records available." << endl;
    }
}


//Filter function for Point3D
void filterAndSortPoint3D(vector<Point3D>& point3DRecords, const string& sortCriteria, const string& sortOrder) {
    // Step 1: Copy the records to avoid modifying the original data
    vector<Point3D> filteredRecords = point3DRecords;

    // Step 2: Sort based on the selected sorting criteria and order
    if (sortCriteria == "x-ordinate") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point3D::compareByX_ASC : Point3D::compareByX_DESC);
    } else if (sortCriteria == "y-ordinate") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point3D::compareByY_ASC : Point3D::compareByY_DESC);
    } else if (sortCriteria == "z-ordinate") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point3D::compareByZ_ASC : Point3D::compareByZ_DESC);
    } else if (sortCriteria == "Dist. Fr Origin value") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Point3D::compareByDistance_ASC : Point3D::compareByDistance_DESC);
    }

    // Step 3: Display the sorted records
    cout << "\n[ View data ... ]" << endl;
    cout << " filtering criteria : " << "Point3D" << endl;
    cout << " sorting criteria : " << sortCriteria << endl;
    cout << " sorting order : " << sortOrder << endl;
    cout << endl;

    //Header formatting
    cout << setw(5) << "X" << setw(6) << "Y" << setw(6) << "Z";
    cout << setw(19) << "Dist. Fr Origin";
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - -" << endl;

    for (const auto& point : filteredRecords) {
        cout << "[" << setw(4) << point.getX() << ", " 
             << setw(4) << point.getY() << ", " 
             << setw(4) << point.getZ() << "]   "
             << fixed << setprecision(3) << point.getScalarValue() << endl;
    }

    if (filteredRecords.empty()) {
        cout << "No records available." << endl;
    }
}

//Filter function for Line2D
void filterAndSortLine2D(vector<Line2D>& line2DRecords, const string& sortCriteria, const string& sortOrder) {
    // Step 1: Copy the records to avoid modifying the original data
    vector<Line2D> filteredRecords = line2DRecords;

    // Step 2: Sort based on criteria and order
    if (sortCriteria == "Pt. 1") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Line2D::compareByP1X_ASC : Line2D::compareByP1X_DESC);
    } else if (sortCriteria == "Pt. 2") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Line2D::compareByP2X_ASC : Line2D::compareByP2X_DESC);
    } else if (sortCriteria == "Length") {
        sort(filteredRecords.begin(), filteredRecords.end(),
             sortOrder == "ASC" ? Line2D::compareByLength_ASC : Line2D::compareByLength_DESC);
    }

    // Step 3: Display the sorted records
    cout << "\n[ View data ... ]" << endl;
    cout << " filtering criteria : " << "Line2D" << endl;
    cout << " sorting criteria : " << sortCriteria << endl;
    cout << " sorting order : " << sortOrder << endl;
    cout << endl;

    //Header formatting
    cout << setw(5) << "P1-X" << setw(6) << "P1-Y";
    cout << setw(9) << "P2-X" << setw(6) << "P2-Y";
    cout << setw(10) << "Length";
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    // Step 5: Print Data with Proper Formatting
    for (const auto& line : filteredRecords) {
        cout << "[" << setw(4) << line.getPt1().getX() << ", "
             << setw(4) << line.getPt1().getY() << "]   "
             << "[" << setw(4) << line.getPt2().getX() << ", "
             << setw(4) << line.getPt2().getY() << "]   "
             << fixed << setprecision(3) << line.getScalarValue() << endl;
    }

    //If no records for some reason
    if (filteredRecords.empty()) {
        cout << "No records available." << endl;
    }
}

//Filter function for Line3D
void filterAndSortLine3D(vector<Line3D>& line3DRecords, const string& sortCriteria, const string& sortOrder) {
    // Step 1: Copy the records to avoid modifying the original data
    vector<Line3D> filteredRecords = line3DRecords;

    // Step 2: Sort based on criteria and order
    if (sortCriteria == "Pt. 1") {
        sort(filteredRecords.begin(), filteredRecords.end(),
                  sortOrder == "ASC" ? Line3D::compareByP1X_ASC : Line3D::compareByP1X_DESC);
    } else if (sortCriteria == "Pt. 2") {
        sort(filteredRecords.begin(), filteredRecords.end(),
                  sortOrder == "ASC" ? Line3D::compareByP2X_ASC : Line3D::compareByP2X_DESC);
    } else if (sortCriteria == "Length") {
        sort(filteredRecords.begin(), filteredRecords.end(),
                  sortOrder == "ASC" ? Line3D::compareByLength_ASC : Line3D::compareByLength_DESC);
    }

    // Step 3: Display the sorted records
    cout << "\n[ View data ... ]" << endl;
    cout << " filtering criteria : Line3D" << endl;
    cout << " sorting criteria : " << sortCriteria << endl;
    cout << " sorting order : " << sortOrder << endl;
    cout << endl;

    //Header formatting
    cout << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z";
    cout << setw(9) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z";
    cout << setw(10) << "Length";
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    //Display records and format the width
    for (const auto& line : filteredRecords) {
        cout << "[" << setw(4) << line.getPt1().getX() << ", "
                  << setw(4) << line.getPt1().getY() << ", "
                  << setw(4) << line.getPt1().getZ() << "]   "
                  << "[" << setw(4) << line.getPt2().getX() << ", "
                  << setw(4) << line.getPt2().getY() << ", "
                  << setw(4) << line.getPt2().getZ() << "]   "
                  << fixed << setprecision(3) << line.getScalarValue() << endl;
    }

    if (filteredRecords.empty()) {
        cout << "No records available." << endl;
    }
}

//Storing the data in .txt file
template <typename T>
int storeDataToFile(const string& fileName, const vector<T>& records, 
                     const string& filterCriteria, const string& sortCriteria, 
                     const string& sortOrder) {
    ofstream outFile(fileName);

    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 0;
    }

    // Write header
    outFile << "[ View data ... ]\n";
    outFile << " filtering criteria : " << filterCriteria << "\n";
    outFile << " sorting criteria : " << sortCriteria << "\n";
    outFile << " sorting order : " << sortOrder << "\n\n";

    // Write column headers
    if (filterCriteria == "Point2D") {
        

    } else if (filterCriteria == "Point3D") {
        outFile << " X   Y   Z   Dist. Fr Origin\n";
        outFile << "- - - - - - - - - - - - - - - -\n";
    } else if (filterCriteria == "Line2D") {
        outFile << " P1-X  P1-Y     P2-X  P2-Y    Length\n";
        outFile << "- - - - - - - - - - - - - - - - - - -\n";
    } else if (filterCriteria == "Line3D") {
        outFile << " P1-X  P1-Y  P1-Z     P2-X  P2-Y  P2-Z    Length\n";
        outFile << "- - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    }

    // Write data
    int count = 0;
    for (const auto& record : records) {
        outFile << record << "\n";  // Assuming operator<< is overloaded for each class
        count++;
    }

    outFile.close();
    return count;
}

void storePoint2DToFile(const string& filename, const vector<Point2D>& records, const string& filterCriteria, const string& sortCriteria, const string& sortOrder) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    outFile << "[ View data ... ]\n";
    outFile << "filtering criteria : " << filterCriteria << "\n";
    outFile << "sorting criteria : " << sortCriteria << "\n";
    outFile << "sorting order : " << sortOrder << "\n\n";
    outFile << setw(5) << "X" << setw(6) << "Y";
    outFile << setw(19) << "Dist. Fr Origin";
    outFile << endl;
    outFile << "- - - - - - - - - - - - - - - - - - -" << endl;

    for (const auto& point : records) {
        outFile << "[" << setw(4) << point.getX() << ", " << setw(4) << point.getY() << "]   " << point.getScalarValue() << "\n";
    }

    outFile.close();
    cout << "\n" << records.size() << " records output successfully!" << "\n";
}
