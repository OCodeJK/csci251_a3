#include "menu.h"
#include <fstream>
#include <sstream>
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

// Global variables to store the last sorted data
vector<Point2D> lastSortedPoint2D;
vector<Point3D> lastSortedPoint3D;
vector<Line2D> lastSortedLine2D;
vector<Line3D> lastSortedLine3D;
string lastFilterCriteria = "";
string lastSortCriteria = "";
string lastSortOrder = "";

// Global string stream to store formatted output
ostringstream lastFormattedOutput;


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

//write the sorted data to .txt file
void storeSortedDataToFile(const string& fileName) {
    if (lastFormattedOutput.str().empty()) {
        cout << "Error: No sorted data available. Please sort data first.\n";
        return;
    }

    ofstream outFile(fileName);
    if (!outFile) {
        cout << "Error: Unable to create file.\n";
        return;
    }

    outFile << lastFormattedOutput.str();
    outFile.close();

}

//read the .txt and process it
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

    while (getline(file, line)) {
        // Skip duplicate lines
        if (!uniqueLines.insert(line).second) {
            continue;
        }

        istringstream iss(line);
        string type;
        iss >> type; // Read the type (e.g., "Point2D," or "Line3D,")

        if (type == "Point2D,") {
            // Parse Point2D
            int x, y;
            char ignore; // To ignore characters like '[', ']', or ',' in the input
            iss >> ignore >> x >> ignore >> y; // Format: [x, y]
            point2DRecords.emplace_back(x, y);

        } else if (type == "Point3D,") {
            // Parse Point3D
            int x, y, z;
            char ignore;
            iss >> ignore >> x >> ignore >> y >> ignore >> z; // Format: [x, y, z]
            point3DRecords.emplace_back(x, y, z);

        } else if (type == "Line2D,") {
            // Parse Line2D
            int x1, y1, x2, y2;
            char ignore;
            iss >> ignore >> x1 >> ignore >> y1 >> ignore >> ignore // First point: [x1, y1]
                >> ignore >> x2 >> ignore >> y2; // Second point: [x2, y2]
            line2DRecords.emplace_back(Point2D(x1, y1), Point2D(x2, y2));

        } else if (type == "Line3D,") {
            // Parse Line3D
            int x1, y1, z1, x2, y2, z2;
            char ignore;
            iss >> ignore >> x1 >> ignore >> y1 >> ignore >> z1 >> ignore >> ignore // First point: [x1, y1, z1]
                >> ignore >> x2 >> ignore >> y2 >> ignore >> z2; // Second point: [x2, y2, z2]
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

    // Step 3:
    // Store sorting criteria for later
    lastSortedPoint2D = filteredRecords;
    lastFilterCriteria = "Point2D";
    lastSortCriteria = sortCriteria;
    lastSortOrder = sortOrder;

    // Clear previous formatted output
    lastFormattedOutput.str("");
    lastFormattedOutput.clear();

    // Format and store output
    lastFormattedOutput << "[ View data ... ]\n";
    lastFormattedOutput << " filtering criteria : " << lastFilterCriteria << "\n";
    lastFormattedOutput << " sorting criteria : " << lastSortCriteria << "\n";
    lastFormattedOutput << " sorting order : " << lastSortOrder << "\n\n";

    lastFormattedOutput << setw(5) << "X" << setw(6) << "Y";
    lastFormattedOutput << setw(20) << "Dist. Fr Origin\n";
    lastFormattedOutput << "- - - - - - - - - - - - - - - - - - -\n";

    //overloaded << operator for the output
    for (const auto& point : filteredRecords) {
        lastFormattedOutput << point << "\n";
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

    // Step 3:
    // Store sorting criteria for later
    lastSortedPoint3D = filteredRecords;
    lastFilterCriteria = "Point3D";
    lastSortCriteria = sortCriteria;
    lastSortOrder = sortOrder;

    // Clear previous formatted output
    lastFormattedOutput.str("");
    lastFormattedOutput.clear();

    // Format and store output
    lastFormattedOutput << "[ View data ... ]\n";
    lastFormattedOutput << " filtering criteria : " << lastFilterCriteria << "\n";
    lastFormattedOutput << " sorting criteria : " << lastSortCriteria << "\n";
    lastFormattedOutput << " sorting order : " << lastSortOrder << "\n\n";

    //Header formatting
    lastFormattedOutput << setw(5) << "X" << setw(6) << "Y" << setw(6) << "Z";
    lastFormattedOutput << setw(19) << "Dist. Fr Origin";
    lastFormattedOutput << endl;
    lastFormattedOutput << "- - - - - - - - - - - - - - - - - - - - - -" << endl;

    //overloaded << operator for the output
    for (const auto& point : filteredRecords) {
        lastFormattedOutput << point << "\n";
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

    // Step 3:
    // Store sorting criteria for later
    lastSortedLine2D = filteredRecords;
    lastFilterCriteria = "Line2D";
    lastSortCriteria = sortCriteria;
    lastSortOrder = sortOrder;

    // Clear previous formatted output
    lastFormattedOutput.str("");
    lastFormattedOutput.clear();

    // Format and store output
    lastFormattedOutput << "[ View data ... ]\n";
    lastFormattedOutput << " filtering criteria : " << lastFilterCriteria << "\n";
    lastFormattedOutput << " sorting criteria : " << lastSortCriteria << "\n";
    lastFormattedOutput << " sorting order : " << lastSortOrder << "\n\n";

    //Header formatting
    lastFormattedOutput << setw(5) << "P1-X" << setw(6) << "P1-Y";
    lastFormattedOutput << setw(9) << "P2-X" << setw(6) << "P2-Y";
    lastFormattedOutput << setw(10) << "Length";
    lastFormattedOutput << endl;
    lastFormattedOutput << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    //overloaded << operator for the output
    for (const auto& line : filteredRecords) {
        lastFormattedOutput << line << "\n";
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

    // Step 3:
    // Store sorting criteria for later
    lastSortedLine3D = filteredRecords;
    lastFilterCriteria = "Line3D";
    lastSortCriteria = sortCriteria;
    lastSortOrder = sortOrder;

    // Clear previous formatted output
    lastFormattedOutput.str("");
    lastFormattedOutput.clear();

    // Format and store output
    lastFormattedOutput << "[ View data ... ]\n";
    lastFormattedOutput << " filtering criteria : " << lastFilterCriteria << "\n";
    lastFormattedOutput << " sorting criteria : " << lastSortCriteria << "\n";
    lastFormattedOutput << " sorting order : " << lastSortOrder << "\n\n";

    //Header formatting
    lastFormattedOutput << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z";
    lastFormattedOutput << setw(9) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z";
    lastFormattedOutput << setw(10) << "Length";
    lastFormattedOutput << endl;
    lastFormattedOutput << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    //overloaded << operator for the output
    for (const auto& line : filteredRecords) {
        lastFormattedOutput << line << "\n";
    }

    if (filteredRecords.empty()) {
        cout << "No records available." << endl;
    }
}
