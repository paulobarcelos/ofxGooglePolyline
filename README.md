# ofxGooglePolyline #

OpenFrameworks addon that exposes a c++ implementation of a decoder for the [Google Encoded Polyline Algorithm Format](https://developers.google.com/maps/documentation/utilities/polylinealgorithm). Very useful if you are trying to extract coordinates out of calls to [Google Directions API](https://developers.google.com/maps/documentation/directions/).

### Sample Usage ###
```c++
void testApp::setup(){
    
    string encoded = "a~l~Fjk~uOnzh@vlbBtc~@tsE`vnApw{A`dw@~w\\|tNtqf@l{Yd_Fblh@rxo@b}@xxSfytAblk@xxaBeJxlcBb~t@zbh@jc|Bx}C`rv@rw|@rlhA~dVzeo@vrSnc}Axf]fjz@xfFbw~@dz{A~d{A|zOxbrBbdUvpo@`cFp~xBc`Hk@nurDznmFfwMbwz@bbl@lq~@loPpxq@bw_@v|{CbtY~jGqeMb{iF|n\\~mbDzeVh_Wr|Efc\\x`Ij{kE}mAb~uF{cNd}xBjp]fulBiwJpgg@|kHntyArpb@bijCk_Kv~eGyqTj_|@`uV`k|DcsNdwxAott@r}q@_gc@nu`CnvHx`k@dse@j|p@zpiAp|gEicy@`omFvaErfo@igQxnlApqGze~AsyRzrjAb__@ftyB}pIlo_BflmA~yQftNboWzoAlzp@mz`@|}_@fda@jakEitAn{fB_a]lexClshBtmqAdmY_hLxiZd~XtaBndgC";
    
    vector<ofVec2f>* decoded = ofxGooglePolyline::decode(encoded);
    
    for(int i = 0; i < decoded->size(); i++){
        ofVec2f point = (*decoded)[i];
        cout << "LAT:" << point.x << ", LONG:" << point.y << endl;
    }
}
```