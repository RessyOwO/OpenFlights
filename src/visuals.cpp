#include "visuals.h"
#include <iostream>
#include <cmath>
Visual::Visual(const string& filenameA, const string& filenameR, const string& filenameV) {
    airport = new Airports(filenameA);
    route  = new Routes(*airport, filenameR);
    png = new PNG();
    png->readFromFile(filenameV);
    graph = new Graph(airport->getAirportsMap(), route->getRoute());
}
void Visual::MarkAirports() {
    unordered_map<string,pair<double, double>> map = airport->getAirportsMap();
    for (auto& it : map) {
        double temp_X = airport->getLatitude(it.first); //-90 - 90
        double temp_Y = airport->getLongitude(it.first); //-180 - 180
        temp_X += 90;
        temp_Y += 190;
        temp_X *= 6;
        temp_Y *= 5;
        //cout << temp_X << endl;
       // cout << temp_Y << endl;
        
        for (int i = (int) temp_X; i < (int) temp_X + 6; i++) {
            for (int j = (int) temp_Y; j < (int) temp_Y + 5; j++) {
                cs225::HSLAPixel& temp = png->getPixel((int) j, 1080 - (int) i);
                temp.l = 0.5;
                temp.h = 0.0;
                temp.s = 1.0;
            }
        }
        
    }
}
void Visual::MarkTopX(int x) {
    vector<string> top = graph->top_airports(x);
    for (auto& it : top) {
        double temp_X = airport->getLatitude(it); //-90 - 90
        double temp_Y = airport->getLongitude(it); //-180 - 180
        temp_X += 90;
        temp_Y += 190;
        temp_X *= 6;
        temp_Y *= 5;
        //cout << temp_X << endl;
       // cout << temp_Y << endl;
        
        for (int i = (int) temp_X; i < (int) temp_X + 8; i++) {
            for (int j = (int) temp_Y; j < (int) temp_Y + 7; j++) {
                cs225::HSLAPixel& temp = png->getPixel((int) j, 1080 - (int) i);
                temp.l = 0.5;
                temp.h = 0.0;
                temp.s = 1.0;
            }
        }
    }
}

pair<double,double> Visual::MarkStartAirport(string ap) {
    double temp_X = airport->getLatitude(ap); //-90 - 90
    double temp_Y = airport->getLongitude(ap); //-180 - 180
    temp_X += 90;
    temp_Y += 190;
    temp_X *= 6;
    temp_Y *= 5;
    //cout << temp_X << endl;
    // cout << temp_Y << endl;
    
    for (int i = (int) temp_X; i < (int) temp_X + 8; i++) {
        for (int j = (int) temp_Y; j < (int) temp_Y + 7; j++) {
            cs225::HSLAPixel& temp = png->getPixel((int) j, 1080 - (int) i);
            temp.l = 0.5;
            temp.h = 0.0;
            temp.s = 1.0;
        }
    }
    return make_pair(temp_Y, 1080.0 - temp_X);
}

pair<double,double> Visual::MarkEndAirport(string ap) {
    double temp_X = airport->getLatitude(ap); //-90 - 90
    double temp_Y = airport->getLongitude(ap); //-180 - 180
    temp_X += 90;
    temp_Y += 190;
    temp_X *= 6;
    temp_Y *= 5;
    //cout << temp_X << endl;
    // cout << temp_Y << endl;
    
    for (int i = (int) temp_X; i < (int) temp_X + 8; i++) {
        for (int j = (int) temp_Y; j < (int) temp_Y + 7; j++) {
            cs225::HSLAPixel& temp = png->getPixel((int) j, 1080 - (int) i);
            temp.l = 0.5;
            temp.h = 147.0;
            temp.s = 1.0;
        }
    }
    return make_pair(temp_Y, 1080.0 - temp_X);
}

void Visual::MarkRoute(string start, string end) {
    pair<double, double> start_coord = MarkStartAirport(start);
    pair<double, double> end_coord = MarkEndAirport(end);
    double start_X = start_coord.first;
    double start_Y = start_coord.second;
    double end_X = end_coord.first;
    double end_Y = end_coord.second;

    bool cross_page = false;
    if (abs(start_X - end_X) >= png->width()/2) cross_page = true;

    if (!cross_page) {
        if (start_X > end_X) {
            double j = end_Y;
            double k = (start_Y - end_Y) / (start_X - end_X);
            for (double i = end_X; i < start_X; i += 1.0) {
                cs225::HSLAPixel& temp = png->getPixel((int)i, (int)j);
                j = j + k;
                temp.l = 0.5;
                temp.h = 40.0;
                temp.s = 1.0;
            }
        } else {
            double j = start_Y;
            double k = (end_Y - start_Y) / (end_X - start_X);
            for (double i = start_X; i < end_X; i += 1.0) {
                cs225::HSLAPixel& temp = png->getPixel((int)i, (int)j);
                j = j + k;
                temp.l = 0.5;
                temp.h = 40.0;
                temp.s = 1.0;
            }
        }

    } else {
        if (start_X > end_X) {
            double j = start_Y;
            double k = (end_Y - start_Y) / (end_X + png->width() - start_X);
            for (double i = start_X; i < end_X + png->width(); i += 1.0) {
                cs225::HSLAPixel& temp = png->getPixel((int)i % png->width(), (int)j);
                j = j + k;
                temp.l = 0.5;
                temp.h = 40.0;
                temp.s = 1.0;
            }
        } else {
            double j = end_Y;
            double k = (start_Y - end_Y) / (start_X + png->width() - end_X);
            for (double i = end_X; i < start_X + png->width(); i += 1.0) {
                cs225::HSLAPixel& temp = png->getPixel((int)i % png->width(), (int)j);
                j = j + k;
                temp.l = 0.5;
                temp.h = 40.0;
                temp.s = 1.0;
            }
        }
    }







}

void Visual::Write(const string& filenameA) {
    png->writeToFile(filenameA);
}