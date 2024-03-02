#pragma once
#include <json/value.h>

void createNoteArray();

void createDefaultArray(double baseFreq);

void readSettings();

void printJsonArray(Json::Value noteList);

void printOneNote(Json::Value noteList, int i);

int writeJsonArray(Json::Value noteArray);

int setMode();

void wrongInput();

double getFrequency();

void readJsonArray();

void clearNoteList(Json::Value noteList);

std::string generateNoteName(int octave, int modulo);

double calculateFrequency(double noteNum, double baseFrequency);