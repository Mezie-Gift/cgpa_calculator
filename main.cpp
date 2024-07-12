#include "studentInfo.h"
//Author: Mezie Gift

float gpa;
int sumOfCreditUnit = 0;

int main()
{
	char option;


	std :: cout << "\nWhat do you want to do?" << "\n";
	std :: cout << "a. Calculate your CGPA for a particular year(level) or for your entire college/university course duration? OR" << "\n";
	std :: cout << "b. Calculate your CGPA for a specific semester?" << "\n";
	std :: cout << "Input either a or b: ";
	std :: cin >> option;
	int attempt = 0;

	//Validate user's option
	while(attempt < 3)
	{
		if((std :: isalpha(option)) && (std :: tolower(option) == 'a' || std :: tolower(option) == 'b'))
		{
			break;
		}
		else
		{
			std :: cin.clear();
			std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
			std :: cout << "Invalid input. reinput your option: ";
			std :: cin >> option;
		}
		attempt++;

		if((attempt == 2) && !(std :: tolower(option) == 'a' || std :: tolower(option) == 'b' || std :: isalpha(option)))
		{
			std :: cerr << "Error: You have entered 3 invalid inputs for option!\n";
			std :: cout << "Your option must be either a or b.\n";
			return 1;
		}//End validation for student's option
	}

	//Calculate the CGPA for at least one academic year
	if(option == 'a')
	{
		StudentInfo student1;
		int sumQty_pointArr[student1.course_duration * 2];
		int sumOfCreditUnit_Arr[student1.course_duration * 2];

		//Get user's name
		std :: cout << "\nEnter your name: ";
		std :: cin.ignore();
		std :: getline(std :: cin, student1.name);

		//Validate student1.name input
		int i;
		attempt = 0;
		while(attempt <= 2)
		{
			//Check if student1.name is empty
			if(student1.name.empty())
			{
				std :: cout << "Invalid input. Please reinput your name: ";
				std :: getline(std :: cin, student1.name);
			}
			else
			{

				//Check if student1.name is a string of alphabet
				bool valid = true;

				for(i = 0; student1.name[i] != '\0'; i++)
				{
					if(!(std :: isalpha(student1.name[i])) && !(student1.name[i] == ' '))
					{
						valid = false;
						break;
					}
				}

				if(!valid)
				{
					std :: cout << "Invalid input. reinput your name: ";
					std :: getline(std :: cin, student1.name);
				}
				else
				{
					break;
				}
				attempt++;

				if(attempt == 2 && !(std :: isalpha(student1.name[i]) || student1.name[i] == ' '))
				{
					std :: cerr << "Error: You have entered 3 invalid inputs for your name!\n";
					std :: cout << "Your name must be a string of alphabets e.g John Doe.\n";
					return 1;
				}
			}
		}//End validation for student1.name
		
		//Get user's course duration
		std :: cout << "How many years course are you studying: ";
		std :: cin >> student1.course_duration;

		//Validate student1.course_duration
		attempt = 0;
		while(attempt <= 2)
		{
			if(student1.course_duration <= 0 || student1.course_duration >= 8)
			{
				std :: cin.clear();
				std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
				std :: cout << "Invalid input. reinput your course duration: ";
				std :: cin >> student1.course_duration;
			}
			else
			{
				break;
			}
			attempt++;
			
			if((attempt) == 2 && (student1.course_duration < 1 || student1.course_duration > 7))
			{
				std :: cerr << "Error: You have entered 3 invalid inputs for your course duration!\n";
				std :: cout << "Your course duration must be >= 1 and <= 7.\n";
				return 1;
			}
		}//End validation for student1.course_duration

		std :: string semester[2] = {"1st SEMESTER", "2nd SEMESTER"};

		//This loop runs for the number of times as the course duration e.g 4 years.
		for(int i = 0; i < student1.course_duration; i++)
		{
			//This loop runs for the number of semesters i.e 2.
			for(int j = 0; j < 2; j++)
			{
				std :: cout << "\nFOR YEAR " << i + 1 << ": " << semester[j] << "\n";
				std :: cout << "________________________\n";

				//Get the user's number of registered courses per semester
				std :: cout << "\nEnter the number of courses you offered for YEAR " << i + 1 << ", " << semester[j] << ": ";
				std :: cin >> student1.NumOfCourses;

				//Validate student1.NumOfCourses
				attempt = 0;

				while(attempt <= 2)
				{
					if(student1.NumOfCourses <= 0 || std :: cin.fail())
					{
						std :: cin.clear();
						std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
						std :: cout << "Invalid input. please reinput your number of courses: ";
						std :: cin >> student1.NumOfCourses;
					}
					else
					{
						break;
					}
					attempt++;

					if(attempt == 2 && (student1.NumOfCourses <= 0))
					{
						std :: cerr << "Error: You have entered 3 invalid inputs for your number of courses!\n";
						std :: cout << "Your number of courses must be an integer > 0.\n";
						return 1;
					}
				}//End validation for student1.NumOfCourses

				std :: cout << "For the " << student1.NumOfCourses << " courses you offered, input your Grade and the credit unit for each of the course seperated by a tab:\n";
				std :: cout << "\nCOURSES GRADES CREDIT UNIT\n";
				student1.grades.resize(student1.NumOfCourses);
				student1.CreditUnit.resize(student1.NumOfCourses);

				//Initialize grades and credit unit through user input
				attempt = 0;
				for(int k = 0; k < student1.NumOfCourses; k++)
				{
					std :: cout << "Course " << k + 1 << ":  ";
					std :: cin >> student1.grades[k] >> student1.CreditUnit[k];

					//Validate student1.grades
					attempt = 0;

					while(attempt <= 2)
					{
						if(!(std :: isalpha(student1.grades[k])) || ((student1.grades[k] < 'a' || student1.grades[k] > 'f') && (student1.grades[k] < 'A' || student1.grades[k] > 'F')))
						{
							std :: cin.clear();
							std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
							std :: cout << "Invalid input. Please reinput your Grade for Course " << k + 1 << ": ";
							std :: cin >> student1.grades[k];

						}
						else
						{
							break;
						}
						attempt++;

						if(attempt == 2 && !student1.grades[k])
						{
							std :: cerr << "Error: You have enterd 3 invalid inputs for Grade in Course " << k + 1 << "!\n";
							std :: cout << "Your grade for each course must be >= a and <= f OR >= A and <= F.\n";
							return 1;
						}
					}//End validation for student1.grades
 
					//Validate student1.CreditUnit
					attempt = 0;

					while(attempt <= 2)
					{
						if((student1.CreditUnit[k] <= 0) || (student1.CreditUnit[k] > 3) || (std :: cin.fail()))
						{
							std :: cin.clear();
							std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
							std :: cout << "Invalid input. Please reinput your Credit Unit for Course " << k + 1 << ": ";
							std :: cin >> student1.CreditUnit[k];
						}
						else
						{
							break;
						}
						attempt++;

						if(attempt == 2 && !student1.CreditUnit[k])
						{	std :: cerr << "Error: You have entered 3 invalid inputs for Credit Unit in Course " << k + 1 << "!\n";
							std :: cout << "Your credit Unit for each course must be >= 1 and <= 3.\n";
							return 1; 
						}
					}//End validation for student1.CreditUnit
				}//End initialization of student1.grades and student1.CreditUnit

				int grade_score;
				int sumQty_point = 0;
				int sumOfCreditUnit = 0;
				int scoreArr[student1.NumOfCourses]; //An array to store a student's Grade Score
			 	int Qty_point[student1.NumOfCourses]; //array to store a student's Quality points
			        int terminalWidth = 80;

				//Header To Output Quality Points
				std :: cout << "\nCOURSES  GRD SCORES   C/UNIT  QUALITY POINT" << "\n";
				
				//This loop assigns grade-score to grade-marks e.g 5 = A||a.
				for( int j = 0; j < student1.NumOfCourses; j++)
				{

					if(student1.grades[j] == 'A' || student1.grades[j] == 'a')
					{
						grade_score = 5;
					}
					else if(student1.grades[j] == 'B' || student1.grades[j] == 'b')
					{
						grade_score = 4;
					}
					else if(student1.grades[j] == 'C' || student1.grades[j] == 'c')
					{
						grade_score = 3;
					}
					else if(student1.grades[j] == 'D' || student1.grades[j] == 'd')
					{
						grade_score = 2;
					}
					else if(student1.grades[j] == 'E' || student1.grades[j] == 'e')
					{
						grade_score = 1;
					}
					else
					{
						grade_score = 0;
					}
					scoreArr[j] = grade_score;

					//Calculate Quality points
					Qty_point[j] = scoreArr[j] * student1.CreditUnit[j];
					
					//Output Quality Points
					std :: cout << "course " << j + 1 << ":    " << scoreArr[j] << "      *     " << student1.CreditUnit[j] << "  =   " << Qty_point[j] <<"\n";

					//Sum The Student's Quality Points
					sumQty_point += Qty_point[j];

					// Sum Of Credit unit
					sumOfCreditUnit += student1.CreditUnit[j];

				}//End of assignment of grade score to grade marks

				//Output The Sum Of Quality Point & Credit Unit
				std :: cout << "\nThe sum of your Quality Point is = " <<sumQty_point <<"\n";
				std :: cout << "The sum of your Credit Unit is = " <<sumOfCreditUnit <<"\n";

				//Calculate The Student's GPA
				float gpa;

				//To return GPA with two decimal places without rounding off
				gpa = static_cast<int>((float)sumQty_point / sumOfCreditUnit * 100) / 100.0f; //To return GPA with two decimal places without rounding off
				std :: cout << "\nYour GPA for year " << i + 1 << ", "  << semester[j] << "is " << gpa  << "\n\n";

				//Initialize  the array that stores  the sum of quality point and the sum of credit unit of every semester
				sumQty_pointArr[i * 2 + j] = sumQty_point;
				sumOfCreditUnit_Arr[i * 2  + j] = sumOfCreditUnit;
				
				//Print '*' To separate The Semesters
				for(int l = 0; l < terminalWidth; l++)
				{
					std :: cout << '*';
				}
				std :: cout << "\n";

			}//End semester
		}//End of Course duration 

	    	//Calculate the Student's CGPA
		float cgpa;
		int cum_sumQty_point = 0; //cumulative sum of Quality Points.
		int cum_sumOfCreditUnit = 0;  //Cumulative sum of Credit Units.

		for(int n = 0; n < student1.course_duration * 2; n++)
		{
			cum_sumQty_point += sumQty_pointArr[n];
			cum_sumOfCreditUnit += sumOfCreditUnit_Arr[n];
		
		}

		//Return CGPA with two decimal places without rounding off
		cgpa = static_cast<int>((float)cum_sumQty_point / cum_sumOfCreditUnit * 100) / 100.0f;
		std :: cout <<student1.name << ", Your CGPA is " << cgpa <<"\n";
		
		if(cgpa >= 4.50 && cgpa <= 5.00)
		{
			std :: cout << "You finished in the 1st Class (Distinction) category!\n";
		}
		else if(cgpa >= 3.50 && cgpa <= 4.49)
		{
			std :: cout << "You finished in the 2nd Class Upper category!\n";
		}	
		else if(cgpa >= 2.40 && cgpa <= 3.49)
		{
			std :: cout << "You finished in the 2nd Class Lower category!\n";
		}
		else if(cgpa >= 1.50 && cgpa <= 2.39)
		{
			std :: cout << "You finished in the 3rd Class category!\n";
		}
		else
		{
			std :: cout << "Error: Invalid CGPA!\n";
		}

		std :: cout <<"\n";
	}

	//Calculate the CGPA (GPA) of a semester
	else
	{
		StudentInfo student2;
		int attempt = 0;

		//Get Student's name
		std :: cout << "\nEnter your name: ";
		std :: cin.ignore();
		std :: getline(std :: cin, student2.name);
		
		//Validate student2.name
		int i;
		attempt = 0;
		while(attempt <= 2)
		{
			//Check if student2.name is empty
			if(student2.name.empty())
			{
				std :: cout << "Invalid input. Please reinput your name: ";
				std :: getline(std :: cin, student2.name);
			}
			else
			{

				//Check if student2.name is a string of alphabet
				bool valid = true;

				for(i = 0; student2.name[i] != '\0'; i++)
				{
					if(!(std :: isalpha(student2.name[i])) && !(student2.name[i] == ' '))
					{
						valid = false;
						break;
					}
				}

				if(!valid)
				{
					std :: cout << "Invalid input. reinput your name: ";
					std :: getline(std :: cin, student2.name);
				}
				else
				{
					break;
				}
				attempt++;

				if(attempt == 2 && !(std :: isalpha(student2.name[i]) || student2.name[i] == ' '))
				{
					std :: cerr << "Error: You have entered 3 invalid inputs for your name!\n";
					std :: cout << "Your name must be a string of alphabets e.g John Doe.\n";
					return 1;
				}
			}
		}//End validation for student2.name


		//Get number of Courses
		std :: cout << "How many course did you offer this semester: ";
		std :: cin >> student2.NumOfCourses;

		//Validate student2.NumofCourses
		attempt = 0;

		while(attempt <= 2)
		{
			if(student2.NumOfCourses <= 0 || std :: cin.fail())
			{
				std :: cin.clear();
				std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
				std :: cout << "Invalid input. please reinput your number of courses: ";
				std :: cin >> student2.NumOfCourses;
			}
			else
			{
				break;
			}
			attempt++;

			if(attempt == 2 && student2.NumOfCourses <= 0)
			{
				std :: cerr << "Error: You have entered 3 invalid inputs for your number of courses!\n";
				std :: cout << "Your number of course must be an integer > 0.\n";
				return 1;
			}
		}//End validation for student2.NumOfCourses


		std :: cout << "For the " << student2.NumOfCourses << " courses you offered this semester, input your grade and the credit unit of each course separated by a tab " <<"\n";
		
		student2.grades.resize(student2.NumOfCourses);
		student2.CreditUnit.resize(student2.NumOfCourses);
		int grade_score;
		int scoreArr[student2.NumOfCourses]; //To store the grade score for each course
		int Qty_point[student2.NumOfCourses]; //To store the quality point for each course
		int sum_Qty_point = 0;
		int sumOfCreditUnit = 0;

		//Header for outputting courses, grades and credit unit
		std :: cout << "\nCOURSES GRADES CREDIT UNIT\n";

		//Initialize  grades and credit unit through student's input	
		for(int i = 0; i < student2.NumOfCourses; i++)
		{
			std :: cout << "Course " << i + 1 << ": ";
			std :: cin >> student2.grades[i] >> student2.CreditUnit[i];

			//Validate student2.grades
			attempt = 0;

			while(attempt <= 2)
			{
				if(!(std :: isalpha(student2.grades[i])) || ((student2.grades[i] < 'a' || student2.grades[i] > 'f') && (student2.grades[i] < 'A' || student2.grades[i] > 'F')))
				{
					std :: cin.clear();
					std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
					std :: cout << "Invalid input. Please reinput your Grade for Course " << i + 1 << ": ";
					std :: cin >> student2.grades[i];
				}
				else
				{
					break;
				}
				attempt++;

				if(attempt == 2 && !student2.grades[i])
				{
					std :: cerr << "Error: You have enterd 3 invalid inputs for Grade in Course " << i + 1 << "!\n";
					std :: cout << "Your grade for each course must be >= a and <= f OR >= A and <= F.\n";
					return 1;
				}
			}//End validation for student2.grades

			//Validate student1.CreditUnit
			attempt = 0;

			while(attempt <= 2)
			{
				if((student2.CreditUnit[i] <= 0) || (student2.CreditUnit[i] > 3) || (std :: cin.fail()))
				{
					std :: cin.clear();
					std :: cin.ignore(std :: numeric_limits < std :: streamsize > :: max(), '\n');
					std :: cout << "Invalid input. Please reinput your Credit Unit for Course " << i + 1 << ": ";
					std :: cin >> student2.CreditUnit[i];
				}
				else
				{
					break;
				}
				attempt++;

				if(attempt == 2 && !student2.CreditUnit[i])
				{
					std :: cerr << "Error: You have entered 3 invalid inputs for Credit Unit in Course " << i + 1 << "!\n";
					std :: cout << "Your credit Unit for each course must be >= 1 and <= 3.\n";
					return 1; 
				}
			}//End validation for student1.CreditUnit

		}//End the initialization of grades and credit unit

		//Header To Output Quality Points
		std :: cout << "\nCOURSES  GRD SCORES   C/UNIT  QUALITY POINT" << "\n";

		//This loop assigns grade-score to grade-marks e.g 5 = A||a.
		for(int j = 0; j < student2.NumOfCourses; j++)
		{

			if(student2.grades[j] == 'A' || student2.grades[j] == 'a')
			{
				grade_score = 5;
			}
			else if(student2.grades[j] == 'B' || student2.grades[j] == 'b')
			{
				grade_score = 4;
			}
			else if(student2.grades[j] == 'C' || student2.grades[j] == 'c')
			{
				grade_score = 3;
			}
			else if(student2.grades[j] == 'D' || student2.grades[j] == 'd')
			{
				grade_score = 2;
			}
			else if(student2.grades[j] == 'E' || student2.grades[j] == 'e')
			{
				grade_score = 1;
			}
			else
			{
				grade_score = 0;
			}

			//Assign to scoreArr
			scoreArr[j] = grade_score;

			//Assign to Qty_point
			Qty_point[j] = scoreArr[j] * student2.CreditUnit[j];

			//Output student's info
			std :: cout << "course " << j + 1 << ":    " << scoreArr[j] << "      *     " << student2.CreditUnit[j] << "  =   " << Qty_point[j] <<"\n";

			//Sum of Quality point
			sum_Qty_point += Qty_point[j];

			//Sum of Credit Unit
			sumOfCreditUnit += student2.CreditUnit[j];
		}
		//Output the sum of Quality points & Credit Units
		std :: cout << "\nThe Sum Of Your Qualit Point is = " << sum_Qty_point << "\n";
		std :: cout << "The Sum Of Your Credit Unit is " << sumOfCreditUnit << "\n";

		//Calculate The Student's GPA
		float gpa;
				
		gpa = static_cast<int>((float)sum_Qty_point / sumOfCreditUnit * 100) / 100.0f; //To return GPA with two decimal places without rounding off
		std :: cout << "\n" << student2.name <<", Your GPA for this semester is " << gpa  << "\n\n";

	}

	return 0;
}
