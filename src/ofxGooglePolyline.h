#pragma once
#include "ofMain.h"

namespace ofxGooglePolyline {
    
    static vector<ofVec2f>* decode(string encoded) {
        int len = encoded.length();
        int index = 0;
        vector<ofVec2f>* points = new vector<ofVec2f>();
        float lat = 0;
        float lng = 0;
        
        while (index < len) {
            char b;
            int shift = 0;
            int result = 0;
            do {
                b = encoded.at(index++) - 63;
                result |= (b & 0x1f) << shift;
                shift += 5;
            } while (b >= 0x20);
            float dlat = ((result & 1) ? ~(result >> 1) : (result >> 1));
            lat += dlat;
            
            shift = 0;
            result = 0;
            do {
                b = encoded.at(index++) - 63;
                result |= (b & 0x1f) << shift;
                shift += 5;
            } while (b >= 0x20);
            float dlng = ((result & 1) ? ~(result >> 1) : (result >> 1));
            lng += dlng;
            
            ofVec2f point;
            point.y = lat * (float)1e-5;
            point.x = lng * (float)1e-5;
            points->push_back(point);
        }
        
        return points;
    }
};