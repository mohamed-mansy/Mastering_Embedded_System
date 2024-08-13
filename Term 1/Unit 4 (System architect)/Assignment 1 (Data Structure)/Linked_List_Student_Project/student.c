/*
 * student.c
 *
 *  Created on: Aug 8, 2024
 *      Author: Mohamed_Ayman
 */

#include "student.h"

struct Sstudent *gpFirstStudent = NULL;

void AddStudent()
{
	struct Sstudent *PNewStudent;
	struct Sstudent *PLastStudent;
	char temp_text[40];
	//check the list is empty ==Yes
	if(gpFirstStudent == NULL)
	{
		//create new record
		PNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
		//assign the gpFirstStudent to NewStudent
		gpFirstStudent = PNewStudent;
	}
	else //the list contains record
	{
		//Navigate until reach to the last record
		PLastStudent = gpFirstStudent;
		while(PLastStudent->PNext_Student){
			PLastStudent = PLastStudent->PNext_Student;
		}
			//create new record
			PNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
			//assign the PLastStudent to NewStudent
			PLastStudent->PNext_Student = PNewStudent;
	}

	//fill the record data
	printf("\nEnter the ID: ");
	gets(temp_text);
	PNewStudent->Student.ID = atoi(temp_text);

	printf("\nEnter Student Full Name: ");
	gets(PNewStudent->Student.Name);

	printf("\nEnter the Height: ");
	gets(temp_text);
	PNewStudent->Student.height = atof(temp_text);

	//set the NewStudent record to NULL
	PNewStudent->PNext_Student = NULL;
}

int Delete_Student()
{
	//Get selected ID from user
	char temp_text[30];
	unsigned int selected_ID;
	printf("Enter the selected student ID to be deleted: ");
	gets(temp_text);
	selected_ID = atoi(temp_text);

	if(gpFirstStudent){

		struct Sstudent *selectedStudent = gpFirstStudent;
		struct Sstudent *previousStudent = NULL;
		//loop on all records starting of gpFirstStudent
		while(selectedStudent){
			//compare the record ID with selected ID
			if(selectedStudent->Student.ID == selected_ID)
			{
				if(previousStudent)
				{
					previousStudent->PNext_Student = selectedStudent->PNext_Student;
				}else
				{
					gpFirstStudent = selectedStudent->PNext_Student;
				}
				free(selectedStudent);
				return 1;
			}
			previousStudent = selectedStudent;
			selectedStudent=selectedStudent->PNext_Student;

		}
	}
	printf("\ncannot find student ID");
	return 0;

}

void View_Student()
{
	struct Sstudent *currentStudent = gpFirstStudent;
	unsigned int count = 0;
	if(gpFirstStudent == NULL)
		{printf("\nEmpty list");}

		while(currentStudent){
			printf("\nRecord number: %d", count+1);
			printf("\n \tstudent ID: %d", currentStudent->Student.ID);
			printf("\n \tstudent Name: %s", currentStudent->Student.Name);
			printf("\n \tstudent Height: %f", currentStudent->Student.height);
			currentStudent = currentStudent->PNext_Student;
			count++;
		}

}

void DeleteALL()
{
	struct Sstudent *currentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		printf("Empty list");
	}else
	{
		while(currentStudent){
			struct Sstudent *tempStudent = currentStudent;
			currentStudent = currentStudent->PNext_Student;
			free(tempStudent);
		}
		gpFirstStudent = NULL;
	}

}

void Get_Number_Node()
{
	struct Sstudent *currentStudent = gpFirstStudent;
	unsigned int count = 1;
	char temp_index[20];
	printf("Enter the index position\n");
	gets(temp_index);

	if(gpFirstStudent == NULL)
		{
			printf("Empty list");
		}
			while(atoi(temp_index) != count){
			currentStudent = currentStudent->PNext_Student;
            count++;
		}

    printf("Record Student of index %d\n", atoi(temp_index));
    printf("\tID : %d\n", currentStudent->Student.ID);
    printf("\tname : %s\n", currentStudent->Student.Name);
    printf("\tHeight : %f\n", currentStudent->Student.height);
}

//          by iterative solution       //
void count_the_Nodes()
{
    unsigned int count = 1;
    struct Sstudent *currentStudent = gpFirstStudent;

    if(gpFirstStudent == NULL)
        printf("empty list");

    while(currentStudent->PNext_Student){
        currentStudent = currentStudent->PNext_Student;
        count++;
    }

    printf("the number of nodes is : %d", count);
}


//recursive method
int get_length_node()
{
	struct Sstudent * ptr = gpFirstStudent;
    if(ptr == NULL)
        return 0;
    else
    {
    	return 1 + get_length_node(ptr->PNext_Student);
    }

}

void get_nth_node_end()
{
    unsigned int count = 0;
    char temp_text[20];
    struct Sstudent *main_ptr = gpFirstStudent;
    struct Sstudent *ref_ptr = gpFirstStudent;

    if(gpFirstStudent == NULL)
        printf("Empty list");
    else{
        printf("Enter the number of node from the end: ");
        gets(temp_text);
    }

    while(atoi(temp_text) != count)
    {
        ref_ptr = ref_ptr->PNext_Student;
        count++;
    }

    while(ref_ptr)
    {
        main_ptr = main_ptr->PNext_Student;
        ref_ptr = ref_ptr->PNext_Student;
    }

    printf("\tID : %d\n", main_ptr->Student.ID);
    printf("\tname : %s\n", main_ptr->Student.Name);
    printf("\tHeight : %f\n", main_ptr->Student.height);

}

void get_middle_linkedList()
{
    struct Sstudent *slow_ptr = gpFirstStudent;
    struct Sstudent *fast_ptr = gpFirstStudent;
    unsigned int count = 1;

    while(fast_ptr && fast_ptr->PNext_Student)
    {
        fast_ptr = fast_ptr->PNext_Student->PNext_Student;
        slow_ptr = slow_ptr->PNext_Student;
        count++;
    }

        printf("Record Student of index %d\n", count);
        printf("\tID : %d\n", slow_ptr->Student.ID);
        printf("\tname : %s\n", slow_ptr->Student.Name);
        printf("\tHeight : %f\n", slow_ptr->Student.height);
}

void Revers_linkedList()
{
    struct Sstudent *pre_ptr = NULL;
    struct Sstudent *current_ptr = gpFirstStudent;
    struct Sstudent *next_ptr = current_ptr->PNext_Student;

    while(current_ptr != NULL)
    {
        next_ptr = current_ptr->PNext_Student;
        current_ptr->PNext_Student = pre_ptr;
        pre_ptr = current_ptr;
        current_ptr = next_ptr;
    }

    gpFirstStudent = pre_ptr;

    View_Student();

}
