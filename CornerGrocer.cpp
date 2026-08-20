/*
 * Name: Kristian Amick
 * Course: CS-210
 * Project Three: Corner Grocer
 * Date: July 2026
 * Description:
 * This program tracks grocery items purchased at Corner Grocer.
 * It reads items from an input file, counts their frequency,
 * displays the frequencies, creates a histogram, and creates
 * a backup file containing the item frequencies.
 */

#include <iostream>
#include "GroceryTracker.h"

int main()
{
    GroceryTracker tracker;

    // Load the grocery data and create the backup file.
    tracker.loadData("CS210_Project_Three_Input_File.txt");
    tracker.createBackupFile("frequency.dat");

    int choice = 0;
    std::string item;

    while (true)
    {
        std::cout << "\nCorner Grocer Menu" << std::endl;
        std::cout << "1. Search for an item" << std::endl;
        std::cout << "2. Display all item frequencies" << std::endl;
        std::cout << "3. Display item frequency histogram" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Enter the item you want to search for: ";
            std::cin >> item;

            std::cout << item << " was purchased "
                << tracker.getItemFrequency(item)
                << " time(s)." << std::endl;
        }
        else if (choice == 2)
        {
            tracker.printAllItems();
        }
        else if (choice == 3)
        {
            tracker.printHistogram();
        }
        else if (choice == 4)
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please select 1-4." << std::endl;
        }
    }

    return 0;
}