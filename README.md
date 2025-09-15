Toll Management System
Description

The Toll Management System is a simple C++ console application that simulates the operations of a toll booth. It uses Object-Oriented Programming (OOP) concepts such as inheritance, polymorphism, encapsulation, and abstraction to manage different types of vehicles passing through a toll plaza.

This system allows the user to:

Add multiple vehicles (Car, Truck, Bus, Bike) to the toll booth.

Specify whether the toll has been paid or not.

Automatically calculate tolls based on vehicle type:

Car: ₹50

Truck: ₹100

Bus: ₹75

Bike: ₹30

Keep track of the total vehicles, total money collected, and count of each vehicle type.

Display a detailed summary of all vehicles and toll collection.

Features

Object-Oriented Design: Uses classes and inheritance to model vehicles and the toll booth.

Polymorphism: Virtual functions are used to identify the type of vehicle dynamically.

Encapsulation: Vehicle and TollBooth data members are private or protected.

Interactive Console Application: Users can input vehicle details and payment status in real-time.

Summary Report: Displays total collection, number of vehicles of each type, and tolls paid per vehicle.

How to Use

Clone or download the repository.

Compile the project.cpp file using a C++ compiler:

g++ project.cpp -o TollManagement


Run the executable:

./TollManagement   # Linux/macOS
TollManagement.exe # Windows


Follow the prompts:

Enter the type of vehicle (1 for Car, 2 for Truck, 3 for Bus, 4 for Bike, 0 to exit).

Enter the vehicle number.

Specify if the toll has been paid (y/n).

Once done, the program will display a summary of the toll booth, including:

Total vehicles passed

Total money collected

Count and toll collection per vehicle type

Vehicle-wise details

Example Output
Enter vehicle type (1.Car 2.Truck 3.Bus 4.Bike) or 0 to exit: 1
Enter vehicle number: KA01AB1234
Has toll been paid? (y/n): y

Enter vehicle type (1.Car 2.Truck 3.Bus 4.Bike) or 0 to exit: 2
Enter vehicle number: KA02CD5678
Has toll been paid? (y/n): n

===== Toll Booth Summary =====
Total vehicles: 2
Total money collected: ₹50
Cars: 1, Trucks: 1, Buses: 0, Bikes: 0

Vehicle Details:
Number     Type       Toll Paid
KA01AB1234 Car        ₹50
KA02CD5678 Truck      ₹0

Technologies Used

C++ Programming Language

Object-Oriented Programming (OOP)

Console-based input/output

Author

Bhavesh Dhanvij

GitHub: https://github.com/bhaveshdhanvij

You can save this content in a file called README.md and place it in your project folder. When you push to GitHub, it will automatically display on your repository page.
