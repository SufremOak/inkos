/*
Coded by:
  ________  ________  ___  __        ___    ___ _____ ______   ________  ________     
 |\   __  \|\   __  \|\  \|\  \     |\  \  /  /|\   _ \  _   \|\   __  \|\   ____\    
 \ \  \|\  \ \  \|\  \ \  \/  /|_   \ \  \/  / | \  \\\__\ \  \ \  \|\  \ \  \___|    
  \ \  \\\  \ \   __  \ \   ___  \   \ \    / / \ \  \\|__| \  \ \   __  \ \  \       
   \ \  \\\  \ \  \ \  \ \  \\ \  \   \/  /  /   \ \  \    \ \  \ \  \ \  \ \  \____  
    \ \_______\ \__\ \__\ \__\\ \__\__/  / /      \ \__\    \ \__\ \__\ \__\ \_______\
     \|_______|\|__|\|__|\|__| \|__|\___/ /        \|__|     \|__|\|__|\|__|\|_______|
                                   \|___|/                                            
                                                                                     
                                                                                     
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 (C) 2025 Miguel's Software  (OakyMac!)
 (C) 2025 OakyMac! <

 This program is part of the InkOS Pen PupListener, so it is a initializer for the NSOL kernel (dummy devices version)
 It will not work on non-WinNT systems.
*/

#include <iostream>
#include <windows.h>
#include <string>

int main() {
    // Set the console title
    SetConsoleTitle("InkOS Pen PupListener - Dummy Device");

    // Print a welcome message
    std::cout << "Welcome to the InkOS Pen PupListener!" << std::endl;
    std::cout << "This is a dummy device for testing purposes." << std::endl;

    // Simulate some initialization process
    std::cout << "Initializing..." << std::endl;
    Sleep(2000); // Simulate a delay for initialization

    // Indicate that the initialization is complete
    std::cout << "Initialization complete!" << std::endl;

    // Keep the console open until the user presses a key
    std::cout << "Press any key to exit..." << std::endl;
    system("pause");

    return 0;
}
// OakyMac! <