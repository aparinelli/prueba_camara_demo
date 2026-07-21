#include "ofApp.h"

namespace {
const int APP_W = 1024;
const int APP_H = 768;

void dibujarTextoCentrado(ofTrueTypeFont& font, const std::string& text, float x, float y) {
    ofRectangle bounds = font.getStringBoundingBox(text, 0, 0);
    font.drawString(text, x - bounds.width * 0.5f - bounds.x, y - bounds.height * 0.5f - bounds.y);
}
}

void ofApp::setup() {
    ofSetWindowTitle("Prueba Camara");
    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableSmoothing();
    ofEnableAntiAliasing();

    configurarPantallaInicio();
}

void ofApp::configurarPantallaInicio() {
    startTitleFont.load(ofToDataPath("fonts/CaslonCPswash.otf", true), 88, true, true);
    startPromptFont.load(ofToDataPath("fonts/Arial.ttf", true), 25, true, true);
}

void ofApp::update() {}

void ofApp::draw() {
    ofBackground(255);

    float scale = std::min(ofGetWidth() / float(APP_W), ofGetHeight() / float(APP_H));
    float offsetX = (ofGetWidth() - APP_W * scale) * 0.5f;
    float offsetY = (ofGetHeight() - APP_H * scale) * 0.5f;

    ofPushMatrix();
    ofTranslate(offsetX, offsetY);
    ofScale(scale);
    dibujarPantallaInicio();
    ofPopMatrix();
}

void ofApp::dibujarPantallaInicio() {
    ofPushStyle();
    ofSetColor(0);

    const std::string title = "Prueba Cámara";
    if (startTitleFont.isLoaded()) {
        dibujarTextoCentrado(startTitleFont, title, APP_W * 0.5f, APP_H * 0.42f);
    } else {
        ofDrawBitmapStringHighlight(title, APP_W * 0.5f - 65.0f, APP_H * 0.42f);
    }

    const float pulse = 0.5f + 0.5f * sin(ofGetElapsedTimef() * 2.4f);
    const float promptAlpha = ofLerp(80.0f, 255.0f, pulse);
    const std::string promptLeft = "Apretá";
    const std::string promptRight = "para empezar";
    const float promptY = APP_H * 0.61f;
    const float keyW = 88.0f;
    const float keyH = 40.0f;
    const float gap = 18.0f;

    ofRectangle leftBounds = startPromptFont.isLoaded()
        ? startPromptFont.getStringBoundingBox(promptLeft, 0, 0)
        : ofRectangle(0, 0, promptLeft.size() * 8.0f, 12.0f);
    ofRectangle rightBounds = startPromptFont.isLoaded()
        ? startPromptFont.getStringBoundingBox(promptRight, 0, 0)
        : ofRectangle(0, 0, promptRight.size() * 8.0f, 12.0f);
    float totalW = leftBounds.width + gap + keyW + gap + rightBounds.width;
    float x = APP_W * 0.5f - totalW * 0.5f;

    ofSetColor(0, promptAlpha);
    if (startPromptFont.isLoaded()) {
        startPromptFont.drawString(promptLeft, x, promptY);
    } else {
        ofDrawBitmapString(promptLeft, x, promptY);
    }
    x += leftBounds.width + gap;

    ofNoFill();
    ofSetLineWidth(2.0f);
    ofSetColor(0, promptAlpha);
    ofDrawRectRounded(x, promptY - keyH + 7.0f, keyW, keyH, 7.0f);
    ofFill();
    if (startPromptFont.isLoaded()) {
        dibujarTextoCentrado(startPromptFont, "Enter", x + keyW * 0.5f, promptY - keyH * 0.5f + 7.0f);
    } else {
        ofDrawBitmapString("Enter", x + 25.0f, promptY - 15.0f);
    }
    x += keyW + gap;

    if (startPromptFont.isLoaded()) {
        startPromptFont.drawString(promptRight, x, promptY);
    } else {
        ofDrawBitmapString(promptRight, x, promptY);
    }

    if (!startScreenActive) {
        ofSetColor(0, promptAlpha * 0.65f);
        ofDrawCircle(APP_W * 0.5f, APP_H * 0.72f, 4.0f);
    }

    ofPopStyle();
}

void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RETURN || key == '\r' || key == '\n') {
        startScreenActive = false;
    }
}

void ofApp::keyReleased(int key) {}
void ofApp::mouseMoved(int x, int y) {}
void ofApp::mouseDragged(int x, int y, int button) {}
void ofApp::mousePressed(int x, int y, int button) {}
void ofApp::mouseReleased(int x, int y, int button) {}
