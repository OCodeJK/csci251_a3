#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

using namespace std;


//Menu functions
void displayMenu(const string& studentID, const string& studentName, const string& filterCriteria, const string& sortCriteria, const string& sortOrder);
void specifyFilterCriteria(string& filterCriteria, string& sortCriteria);
void specifySortingCriteria(const string& filterCriteria, string& sortCriteria);
void specifySortingOrder(string& sortOrder);
void readDataFromFile(const string& filename, vector<Point2D>& point2DRecords, vector<Point3D>& point3DRecords, vector<Line2D>& line2DRecords, vector<Line3D>& line3DRecords);

//Filtering and Sorting
void filterAndSortPoint2D(vector<Point2D>& point2DRecords, const string& sortCriteria, const string& sortOrder);
void filterAndSortPoint3D(vector<Point3D>& point3DRecords, const string& sortCriteria, const string& sortOrder);
void filterAndSortLine2D(vector<Line2D>& line2DRecords, const string& sortCriteria, const string& sortOrder);
void filterAndSortLine3D(vector<Line3D>& line3DRecords, const string& sortCriteria, const string& sortOrder);

//Storing data in .txt file
void storeSortedDataToFile(const string& fileName);

#endif
