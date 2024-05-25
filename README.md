Error Log Monitoring Platform

This repository contains a solution for an Error Log Monitoring platform. The solution processes log entries and performs various operations such as computing statistics based on timestamps and log types. The project is implemented in C++ for the main functionality and includes a Python script for generating test input files. The solution is Dockerized for easy deployment.

Features

1.Submit Log Entry: Store a new log entry with timestamp, log type, and severity.
2.Compute Statistics by Log Type: Compute the min, max, and mean severity for a specified log type.
3.Compute Statistics Before/After Timestamp: Compute the min, max, and mean severity for all log entries 4.4.occurring before or after a specified timestamp.
4.Compute Statistics by Log Type and Timestamp: Compute the min, max, and mean severity for all log entries of a specified log type occurring before or after a specified timestamp.

Assumptions:

1.Timestamps will come in an ascending sorted order.
2.Log types can be any UTF-8 supported string with a maximum length of 100 characters.
3.Severity will be a positive non-zero floating-point number.
4.The solution ensures precision to 10E-6 for severity results.

File Descriptions
1.error_log.cpp: Main script for processing log entries and generating the output in C++.
2.input.txt: Input file containing log entries and commands.
3.output.txt: Output file for storing the results.

Prerequisites:
1.c++20.
2.vsCode.

Running the Solution:
Run the Main Script: error_log.cpp

Example

Sample Input (input.txt):

1 1715744138011;INTERNAL_SERVER_ERROR;23.72 1 1715744138012;INTERNAL_SERVER_ERROR;10.17 2 INTERNAL_SERVER_ERROR 1 1715744138012;BAD_REQUEST;15.22 1 1715744138013;INTERNAL_SERVER_ERROR;23.72 3 BEFORE 1715744138011 3 AFTER 1715744138010 2 BAD_REQUEST 4 BEFORE INTERNAL_SERVER_ERROR 1715744138011 4 AFTER INTERNAL_SERVER_ERROR 1715744138010

Sample Output (output.txt):

No output No output Min: 10.17, Max: 23.72, Mean: 16.945000 No output No output Min: 0.00, Max: 0.00, Mean: 0.000000 Min: 10.17, Max: 23.72, Mean: 18.207500 Min: 15.22, Max: 15.22, Mean: 15.220000 Min: 0.00, Max: 0.00, Mean: 0.000000 Min: 10.17, Max: 23.72, Mean: 19.203333

Author

Ovijit Kirtania
