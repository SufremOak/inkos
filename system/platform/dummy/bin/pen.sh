#!/usr/bin/env bash

# Coded by:
#  ________  ________  ___  __        ___    ___ _____ ______   ________  ________     
# |\   __  \|\   __  \|\  \|\  \     |\  \  /  /|\   _ \  _   \|\   __  \|\   ____\    
# \ \  \|\  \ \  \|\  \ \  \/  /|_   \ \  \/  / | \  \\\__\ \  \ \  \|\  \ \  \___|    
#  \ \  \\\  \ \   __  \ \   ___  \   \ \    / / \ \  \\|__| \  \ \   __  \ \  \       
#   \ \  \\\  \ \  \ \  \ \  \\ \  \   \/  /  /   \ \  \    \ \  \ \  \ \  \ \  \____  
#    \ \_______\ \__\ \__\ \__\\ \__\__/  / /      \ \__\    \ \__\ \__\ \__\ \_______\
#     \|_______|\|__|\|__|\|__| \|__|\___/ /        \|__|     \|__|\|__|\|__|\|_______|
#                                   \|___|/                                            
                                                                                     
                                                                                     
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# (C) 2025 Miguel's Software  (OakyMac!)
# (C) 2025 OakyMac! <

# This script is part of the InkOS Pen PupListener, so it is a initializer for the NSOL kernel (dummy devices version)
# This version works only on Unix and Unix-like systems, do not use it on Windows or on POSIX compatibility layers like Cygwin or WSL.

set -e

# Check if the script is running as root
if [ "$(id -u)" -ne 0 ]; then
    echo "This script must be run as root. Please use 'sudo' or switch to the root user."
    exit 1
fi

# Check if the script is running on a Unix-like system
case "$(uname)" in
    Linux|Darwin|*BSD)
        ;;
    *)
        echo "This script is designed to run on Unix-like systems (Linux, macOS, or BSD)."
        exit 1
        ;;
esac


# This section is for the NSOL kernel, do not modify it unless you know what you are doing.
nsol() {
    nsol-init() {
        echo "[*] NSOL is now starting..."
        
    }
}

# create the arguments for the program
case "$1" in
    --help|-h)
        echo "Usage: $0 [--help|-h]"
        echo "This script initializes the NSOL kernel for InkOS Pen PupListener on Unix-like systems."
        exit 0
        ;;
    *)
        # No specific arguments, proceed with initialization
        nsol-init
        ;;
esac