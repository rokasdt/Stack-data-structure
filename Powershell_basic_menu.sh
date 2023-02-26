#!/bin/bash

# Function to display menu
show_menu() {
    echo "Menu:"
    echo "1. Print first name and last name"
    echo "2. Print age and city"
    echo "3. Print everything"
    echo "4. Exit"
}

# Function to execute selected option
execute_option() {
    case $1 in
        1)
            echo "Printing first name and last name..."
            awk '{print $1, $2}' info.txt
            ;;
        2)
            echo "Printing age and city..."
            awk '{print $3, $4}' info.txt
            ;;
        3)
            echo "Printing everything..."
            cat info.txt
            ;;
        4)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid option"
            ;;
    esac
}

# Main loop
while true; do
    show_menu
    read -p "Enter option: " option
    execute_option $option
done
