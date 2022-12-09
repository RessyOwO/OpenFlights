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
                temp.h = 11.0;
            }
        }
        
    }
}
void Visual::MarkTop100() {
    vector<string> top = graph->top_airports(100);
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
                temp.h = 11.0;
            }
        }
    }
}
void Visual::MarkRoute(string start, string end) {
    cout << graph -> getAirportNode().size() << endl;
    vector<string> bfs_path = graph -> BFS(start, end);
    cout << bfs_path.size() << endl;
    for (int i = 0; i < (int)bfs_path.size(); i++) {
        for (int j = i + 1; j < (int)bfs_path.size(); j++) {
            double x1 = airport -> getLatitude(bfs_path[i]);
            double y1 = airport -> getLongitude(bfs_path[i]);
            double x2 = airport -> getLatitude(bfs_path[j]);
            double y2 = airport -> getLongitude(bfs_path[j]);
            // cout << "x1 is " << x1 << " x2 is " << x2 << endl;
            // cout << "y1 is " << y1 << " y2 is " << y2 << endl;
            x1 += 90;
            y1 += 165;
            x2 += 90;
            y2 += 165;
            x1 *= 6;
            y1 *= 5;
            x2 *= 6;
            y2 *= 5;
            for (int ii = (int) x1; ii < (int) x1 + 6; ii++) {
                for (int jj = (int) y1; jj < (int) y1 + 5; jj++) {
                    cs225::HSLAPixel& temp = png->getPixel((int) jj, 1080 - (int) ii);
                    temp.l = 0.5;
                    temp.h = 216.0;
                }
            }
            x2 = 700.0;
            y2 = 1000.0;
            cout << "x1 is " << x1 << " x2 is " << x2 << endl;
            cout << "y1 is " << y1 << " y2 is " << y2 << endl;
            for (int iii = (int) x2; iii < (int) x2 + 6; iii++) {
                for (int jjj = (int) y2; jjj < (int) y2 + 5; jjj++) {
                    cs225::HSLAPixel& temp = png->getPixel((int) jjj, 1080 - (int) iii);
                    temp.l = 0.5;
                    temp.h = 100.0;
                }
            }
            double diff_y = y2 - y1; //x 
            cout << "the differ is " << diff_y << endl;
            double diff_x = x2 - x1; //y
            cout << "the differ of x is " << diff_x << endl;
            double ratio = (diff_x) / (diff_y);
            cout << "the ratio is " << (diff_x) / (diff_y) << endl;
            if ((diff_x / diff_y) > 0) {
                if (y2 - y1 >= 0) {
                    //cout << "here1" << endl;
                    for (int ii = (int) x1, jj = (int) y1; ii < (int) x2 && jj < (int) y2; ii+=1*(diff_x/diff_y), jj++) {
                            cs225::HSLAPixel& temp = png->getPixel((int) jj, 1080 - (int) ii);
                            temp.l = 0.5;
                            temp.h = 11.0;
                    }
                } else if (y2 - y1 < 0) {
                    //cout << "here2" << endl;
                    for (int ii = (int) x1, jj = (int) y1; ii >= (int) x2 && jj >= (int) y2; ii-=1*(diff_x/diff_y), jj--) {
                            cs225::HSLAPixel& temp = png->getPixel((int) jj, 1080 - (int) ii);
                            temp.l = 0.5;
                            temp.h = 11.0;
                    }
                }
            } else if ((diff_x / diff_y) < 0) {
                if (y2 - y1 >= 0.0) {
                    cout << "here3" << endl;
                    for (int ii = (int) x1, jj = (int) y1; ii < (int) x2 && jj < (int) y2; ii=ii-1*(diff_x/diff_y), jj++) {
                            cs225::HSLAPixel& temp = png->getPixel((int) jj, 1080 - (int) ii);
                            temp.l = 0.5;
                            temp.h = 11.0;
                    }

                } else if (y2 - y1 < 0.0) {
                    cout << "here4" << endl;
                    for (int ii = (int) x1, jj = (int) y1; ii >= (int) x2 && jj >= (int) y2; ii = ii + 1 * (diff_x / diff_y), jj = jj - 1) {
                            cs225::HSLAPixel& temp = png->getPixel((int) jj, 1080 - (int) ii);
                            temp.l = 0.5;
                            temp.h = 11.0;
                    }
                }
            }
        }
    }
}
void Visual::Write(const string& filenameA) {
    png->writeToFile(filenameA);
}