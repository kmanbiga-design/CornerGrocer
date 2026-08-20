/*
 * Name: Kristian Amick
 * Course: CS-210
 * Project Three: Corner Grocer
 * Date: July 2026
 * Description:
 * This file contains the functions used by the GroceryTracker
 * class to read grocery items, count their frequencies,
 * display the results, and create the backup file.
 */

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// Reads the items from the input file and counts each item.
void GroceryTracker::loadData(const std::string& fileName)
{
    std::ifstream inputFile(fileName);
    std::string item;

    if (!inputFile)
    {
        std::cout << "Unable to open the input file." << std::endl;
        return;
    }

    while (inputFile >> item)
    {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// Finds an item in the map and returns its frequency.
int GroceryTracker::getItemFrequency(const std::string& item)
{
    if (itemFrequency.find(item) != itemFrequency.end())
    {
        return itemFrequency[item];
    }

    return 0;
}

// Displays every item and its frequency.
void GroceryTracker::printAllItems()
{
    for (const auto& item : itemFrequency)
    {
        std::cout << std::left << std::setw(15)
            << item.first << item.second << std::endl;
    }
}

// Displays every item with asterisks showing its frequency.
void GroceryTracker::printHistogram()
{
    for (const auto& item : itemFrequency)
    {
        std::cout << std::left << std::setw(15)
            << item.first;

        for (int i = 0; i < item.second; i++)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
}

// Creates the frequency.dat backup file.
void GroceryTracker::createBackupFile(const std::string& fileName)
{
    std::ofstream outputFile(fileName);

    if (!outputFile)
    {
        std::cout << "Unable to create the backup file." << std::endl;
        return;
    }

    for (const auto& item : itemFrequency)
    {
        outputFile << item.first << " " << item.second << std::endl;
    }

    outputFile.close();
}