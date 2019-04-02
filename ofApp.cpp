#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 144;
	for (int x = span * 0.5; x <= ofGetWidth() - span * 0.5; x += span) {

		for (int y = span * 0.5; y <= ofGetWidth() - span * 0.5; y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			int big_radius = 60;
			int small_radius = 40;
			int deg_gap = ofMap(ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.005), 0, 1, 0, 360);
			for (int deg = 0; deg < 360; deg += 10) {

				auto big_location = glm::vec2(big_radius * cos(deg * DEG_TO_RAD), big_radius * sin(deg * DEG_TO_RAD));
				auto small_location = glm::vec2(small_radius * cos((deg + deg_gap) * DEG_TO_RAD), small_radius * sin((deg + deg_gap) * DEG_TO_RAD));

				ofDrawCircle(big_location, 2);
				ofDrawCircle(small_location, 2);

				ofDrawLine(big_location, small_location);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}