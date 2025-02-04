#include <iostream>
#include <vector>
#include <string>
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "menu.h"
#include <limits>

using namespace std;



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
    string fileName;
    int choice;


    do {
        displayMenu(studentID, studentName, filterCriteria, sortCriteria, sortOrder);
        cin >> choice;

        switch (choice){
            case 1:
                //Process the file to remove duplicates and parse data
                cout << "\nPlease enter filename : ";
                cin >> fileName;

                readDataFromFile(fileName, point2DRecords, point3DRecords, line2DRecords, line3DRecords);

                break;

            case 2:
                specifyFilterCriteria(filterCriteria, sortCriteria);
                break;

            case 3:
                specifySortingCriteria(filterCriteria, sortCriteria);
                break;

            case 4:
                specifySortingOrder(sortOrder);
                break;

            case 5:
                if (filterCriteria == "Point2D") {
                    filterAndSortPoint2D(point2DRecords, sortCriteria, sortOrder);
                    cout << "\nPress any key to go back to main menu...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover inputs
                    cin.get(); // Wait for user input

                } else if (filterCriteria == "Point3D") {
                    filterAndSortPoint3D(point3DRecords, sortCriteria, sortOrder);
<<<<<<< HEAD
                    cout << "\nPress any key to go back to main menu...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover inputs
                    cin.get(); // Wait for user input

                } else if (filterCriteria == "Line2D") {
                    filterAndSortLine2D(line2DRecords, sortCriteria, sortOrder);
                    cout << "\nPress any key to go back to main menu...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover inputs
                    cin.get(); // Wait for user input

                } else if (filterCriteria == "Line3D") {
                    filterAndSortLine3D(line3DRecords, sortCriteria, sortOrder);
                    cout << "\nPress any key to go back to main menu...";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover inputs
                    cin.get(); // Wait for user input
                    
=======
                } else if (filterCriteria == "Line2D") {
                    filterAndSortLine2D(line2DRecords, sortCriteria, sortOrder);
                } else if (filterCriteria == "Line3D") {
                    filterAndSortLine3D(line3DRecords, sortCriteria, sortOrder);
>>>>>>> 44492dbf5b5d659969d00c818c60d8aae6076c30
                } else {
                    cout << "Filtering for data type not implementing" << endl;
                }
                break;

            case 6:
                // Placeholder for storing data function
                cout << "Storing data... (to be implemented)" << endl;
                break;
            
            case 7:
                //Quit
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);


    return 0;
}
