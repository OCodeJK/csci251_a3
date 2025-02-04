#include <iostream>
#include <vector>
#include <string>
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "menu.h"
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Global variables to store the last sorted data
extern string lastFilterCriteria;
extern ostringstream lastFormattedOutput;

int main() {
    vector<Point2D> point2DRecords;
    vector<Point3D> point3DRecords;
    vector<Line2D> line2DRecords;
    vector<Line3D> line3DRecords;
    string studentID = "9071180";
    string studentName = "Ooi Jun Kang";
    string filterCriteria = "Point2D";
    string sortCriteria = "x-ordinate";
    string sortOrder = "ASC";
    string messyFileName;
    int choice;


    do {
        displayMenu(studentID, studentName, filterCriteria, sortCriteria, sortOrder);
        cin >> choice;

        switch (choice){
            case 1:
                //Process the file to remove duplicates and parse data
                cout << "\nPlease enter filename : ";
                cin >> messyFileName;

                readDataFromFile(messyFileName, point2DRecords, point3DRecords, line2DRecords, line3DRecords);

                break;

            //Select which data to sort Point2D, Point3D or Line2D, Line3D
            case 2:
                specifyFilterCriteria(filterCriteria, sortCriteria);
                if (filterCriteria == "Point2D") {
                    filterAndSortPoint2D(point2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Point3D") {
                    filterAndSortPoint3D(point3DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line2D") {
                    filterAndSortLine2D(line2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line3D") {
                    filterAndSortLine3D(line3DRecords, sortCriteria, sortOrder);
                }
                break;

            //Select what to sort by x-ordinate for point or pt1/2 for line 
            case 3:
                specifySortingCriteria(filterCriteria, sortCriteria);
                if (filterCriteria == "Point2D") {
                    filterAndSortPoint2D(point2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Point3D") {
                    filterAndSortPoint3D(point3DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line2D") {
                    filterAndSortLine2D(line2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line3D") {
                    filterAndSortLine3D(line3DRecords, sortCriteria, sortOrder);
                }
                break;

            //Select whether its ascending or descending
            case 4:
                specifySortingOrder(sortOrder);
                if (filterCriteria == "Point2D") {
                    filterAndSortPoint2D(point2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Point3D") {
                    filterAndSortPoint3D(point3DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line2D") {
                    filterAndSortLine2D(line2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line3D") {
                    filterAndSortLine3D(line3DRecords, sortCriteria, sortOrder);
                }
                break;

            case 5:
                if (lastFormattedOutput.str().empty()){
                    cout << "\nError: No sorted data available. Please sort data first.\n";
                } else {
                    cout << lastFormattedOutput.str(); // Print the stored sorted data
                }
                cout << "\nPress any key to go back to the main menu...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover inputs
                cin.get(); // Wait for user input
                break;

            case 6:{
                string fileName;
                cout << "\nPlease enter filename: "; 
                cin >> fileName;

                //Check if the inital .txt file has been even put
                if (messyFileName == "") {
                    cout << "\nError: Did not insert any data at all. Please insert messy txt file\n";
                    break;
                }

                //Check if lastFormattedOutput is empty (i.e, no sorting has been done yet)
                if (lastFormattedOutput.str().empty()) {

                    //Perform default sort first
                    filterAndSortPoint2D(point2DRecords, "x-ordinate", "ASC");
                }
                storeSortedDataToFile(fileName);
                
                //Line that says how many records stored here
                if (filterCriteria == "Point2D") {
                    cout << "\n" << point2DRecords.size() << " records output successfully!" << endl;

                } else if (filterCriteria == "Point3D") {
                    cout << "\n" << point3DRecords.size() << " records output successfully!" << endl;

                } else if (filterCriteria == "Line2D") {
                    cout << "\n" << line2DRecords.size() << " records output successfully!" << endl;

                } else if (filterCriteria == "Line3D") {
                    cout << "\n" << line3DRecords.size() << " records output successfully!" << endl;

                }

                cout << "\nGoing back to main menu ...\n";

                break;
            }
            case 7:
                //Quit
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);


    return 0;
}
