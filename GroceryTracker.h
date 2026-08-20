/*
 * Name: Kristian Amick
 * Course: CS-210
 * Project Three: Corner Grocer
 * Date: July 2026
 * Description:
 * This header file defines the GroceryTracker class used to
 * store grocery items and their frequencies.
 */

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker
{
private:
    // Stores each grocery item and the number of times it appears.
    std::map<std::string, int> itemFrequency;

public:
    // Reads the grocery items from the input file.
    void loadData(const std::string& fileName);

    // Returns the number of times an item was purchased.
    int getItemFrequency(const std::string& item);

    // Displays all items and their frequencies.
    void printAllItems();

    // Displays the frequencies as a histogram.
    void printHistogram();

    // Creates the backup frequency.dat file.
    void createBackupFile(const std::string& fileName);
};

#endif