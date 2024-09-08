/*
 * student.c
 *
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	Student_Database_Using_Queue.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *      Author: Mohamed_Ayman
 */

#include "student.h"

/*file*/
FILE *Database_student;

static FIFO_Student_t *Search_Student_by_Roll_Number(FIFO_Buf_t *students_queue, int roll);

FIFO_status_t FIFO_enqueue_item(FIFO_Buf_t *fifo_buf , FIFO_Student_t item)
{
	//check fifo is valid
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;

	//check fifo is full
	if(FIFO_is_full(fifo_buf) == FIFO_full)
		return FIFO_full;

	//add item
	*(fifo_buf->head) = item;

	//circular fifo
	if(fifo_buf->head == (fifo_buf->base + fifo_buf->length * sizeof(FIFO_Student_t)))
		fifo_buf->head = fifo_buf->base;
	else
		fifo_buf->head++;

	fifo_buf->count++;

	return FIFO_no_error;

}

/*************************************************************************************************/

void add_student_manually(FIFO_Buf_t *student_queue)
{
	FIFO_Student_t new_student;
	int i;

	printf("Enter student data\n");
	printf("\tEnter roll number: ");
	scanf("%d", &new_student.roll);
	//check if the roll number is exit
    if(Search_Student_by_Roll_Number(student_queue, new_student.roll))
    {
        printf("\n[ERROR] Roll number %d is already taken\n", new_student.roll);
		printf("\n[ERROR] Adding student manually failed\n");
		return;
    }

	printf("\tEnter the first name: ");
	scanf("%s", new_student.Fname);

	printf("\tEnter the last name: ");
	scanf("%s", new_student.Lname);

	printf("\tEnter the GPA: ");
	scanf("%f", &new_student.GPA);

	printf("\tEnter courses ID of each course\n");
	for(i = 0; i < Courses_Number; i++)
	{
		printf("\tcourse %d id: ", i+1);
		scanf("%d", &new_student.CourseId[i]);
	}

	//Add new student
	if(FIFO_enqueue_item(student_queue , new_student) == FIFO_no_error)
	{
		printf("[INFO] Student Details is added successfully\n");
	}
	else
		printf("[ERROR] Adding student manually failed\n");
}

/***************************************************************************************************/

void add_student_file(FIFO_Buf_t *student_queue)
{
    FIFO_Student_t new_student;
    int i;

    /*open a file --> read */
    Database_student = fopen("Database_student.txt", "r");
    //check if the file is not empty
    if(Database_student == NULL)
    {
        printf("[ERROR] Database_student.txt file is empty\n");
        return;
    }

    /*Reading from file until eof = End of file*/
    while(!feof(Database_student))
    {
        //reading roll number
        fscanf(Database_student, "%d",&new_student.roll);
        /*check if the roll number is exit*/
        if(Search_Student_by_Roll_Number(student_queue, new_student.roll))
    {
        printf("[ERROR] Roll number %d is already taken\n", new_student.roll);

		/* Ignore the rest of the line --> because this roll numberis taken */
        fscanf(Database_student, "%*[^\n]");

        continue;
    }

        /*Reading the data student*/
        fscanf(Database_student, "%s", new_student.Fname);
        fscanf(Database_student, "%s", new_student.Lname);
        fscanf(Database_student, "%f", &new_student.GPA);

        /*Reading courses ID*/
        for(i = 0; i < Courses_Number; i++)
        {
            fscanf(Database_student, "%d", &new_student.CourseId[i]);
        }
        /*Enqueue a new student*/
        if(FIFO_enqueue_item(student_queue, new_student) == FIFO_no_error)
            printf("[INFO] Roll number %d saved successfully\n", new_student.roll);

        else{
            printf("[ERROR] Adding students by file failed\n");
            return;
        }
    }
    printf("[INFO] students details is added successfully\n");

    /*Close the file*/
    fclose(Database_student);
}

/***************************************************************************************************/

void find_Student_by_id(FIFO_Buf_t *student_queue){
	int id, i;
    FIFO_Student_t *pstudent;

	printf("\tEnter the roll number of the student: ");
	scanf("%d", &id);

	/*scan the queue to find the roll number*/
	pstudent = Search_Student_by_Roll_Number(student_queue, id);

	if(pstudent == NULL)
    {
        printf("\n[ERROR] Roll number %d in not found\n", id);
		return;
    }
    else
    {
        printf("the student details are\n");
        printf("\tthe first name is %s\n", pstudent->Fname);
        printf("\tthe last name is %s\n", pstudent->Lname);
        printf("\tthe GPA is %f\n", pstudent->GPA);

        printf("\tcourses IDs are\n");
        for(i = 0; i < Courses_Number; i++)
        {
            printf("\t\tcourse id: %d\n", pstudent->CourseId[i]);
        }
    }

}

/***************************************************************************************************/

void find_Student_by_name(FIFO_Buf_t *student_queue, FIFO_Student_t *student)
{
    student = student_queue->tail;

    char FirstName[20];
    printf("Enter the first name of the student: ");
    scanf("%s", FirstName);

    int i, j;
    for(i = 0; i < student_queue->count; i++)
    {
        if(strcmp(student->Fname, FirstName) == 0)
        {
             printf("The student details are: \n");
            printf("\tthe first name is %s\n", student->Fname);
            printf("\tthe last name is %s\n", student->Lname);
            printf("\tthe Roll number is %d\n", student->roll);
            printf("\tthe GPA is %f\n", student->GPA);

            printf("\tcourses IDs are\n");
            for(j = 0; j < Courses_Number; j++)
            {
            printf("\t\tcourse id: %d\n", student->CourseId[j]);
            }
            return;
        }

         //Check if we reach the last Node in the queue
		if((student +1) == (student_queue->base + student_queue->length))
		{
			/* Set to the start */
			student = student_queue->base;
		}
		else
		{
			/* go to the next tail */
			student++;
		}
    }

        printf("[ERROR] %s is not found\n", FirstName);
        return;

}

/***************************************************************************************************/

void find_Student_by_courseId(FIFO_Buf_t *student_queue)
{
    FIFO_Student_t *student = student_queue->tail;

    int CourseID, i, j, flag = 0;
    printf("Enter the course ID: ");
    scanf("%d", &CourseID);

    for(i = 0; i < student_queue->count; i++)
    {
        for(j = 0; j < Courses_Number; j++)
        {
            if(student->CourseId[j] == CourseID)
            {
                printf("The student details are: \n");
                printf("\tthe first name is %s\n", student->Fname);
                printf("\tthe last name is %s\n", student->Lname);
                printf("\tthe Roll number is %d\n", student->roll);
                printf("\tthe GPA is %f\n", student->GPA);
                flag = 1;
            }
        }
        if((student +1) == (student_queue->base + student_queue->length))
		{
			/* Set to the start */
			student = student_queue->base;
		}
		else
		{
			/* go to the next tail */
			student++;
		}

    }
    if(flag == 0){
        printf("[ERROR] course ID %d is not found\n", CourseID);
        return;
    }

}

/***************************************************************************************************/

void Show_info(FIFO_Buf_t *student_queue)
{
    FIFO_Student_t *student = student_queue->tail;
    int i, j;

    /*check the queue is empty*/
    if(student_queue->count == 0)
    {
        printf("\n[ERROR] student queue is empty\n");
		return;
    }

    for(i = 0; i < student_queue->count; i++)
    {
        printf("The student details are: \n");
        printf("\tthe first name is %s\n", student->Fname);
        printf("\tthe last name is %s\n", student->Lname);
        printf("\tthe Roll number is %d\n", student->roll);
        printf("\tthe GPA is %f\n", student->GPA);

        printf("\tcourses IDs are\n");
        for(j = 0; j < Courses_Number; j++)
        {
            printf("\t\tcourse id: %d\n", student->CourseId[j]);
        }
        student++;
    }
}

/***************************************************************************************************/

void Count_The_Student(FIFO_Buf_t *student_queue)
{
    FIFO_Student_t *student = student_queue->tail;
    int i, count = 0;

    for(i = 0; i < student_queue->count; i++)
    {
        count++;
        student++;
    }
    printf("[INFO] The total number of student is %d", count);

}

/***************************************************************************************************/

FIFO_status_t FIFO_dequeue_item(FIFO_Buf_t *fifo_buf, FIFO_Student_t *item)
{
	//check fifo is valid
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;

	//check fifo is empty
	if(fifo_buf->count == 0)
		return FIFO_empty;

	//pop item
	*item = *fifo_buf->tail;
	fifo_buf->count--;
	if(fifo_buf->tail == (fifo_buf->tail + fifo_buf->length * sizeof(FIFO_Student_t)))
		fifo_buf->tail = fifo_buf->base;
	else
		fifo_buf->tail++;

	return FIFO_no_error;
}

void Delete_Student(FIFO_Buf_t *student_queue)
{
    FIFO_Student_t *student = student_queue->tail;

    /*check the queue is empty*/
    if(student_queue->count == 0)
    {
        printf("\n[ERROR] student queue is empty\n");
		return;
    }

    int roll, i;
    printf("Enter the Roll number which you want to deleted: ");
    scanf("%d", &roll);

    for(i = 0; i < student_queue->count; i++)
    {
        if(student->roll == roll)
        {
            if(FIFO_dequeue_item(student_queue, student) == FIFO_no_error)
                printf("[INFO] The Roll number is removed successfully");
        }
        student++;
    }
}

/***************************************************************************************************/

void Update_Student(FIFO_Buf_t *student_queue)
{
    FIFO_Student_t *student = student_queue->tail;
    int Roll, i , j, choice;
    printf("Enter the roll number to update the entry: ");
    scanf("%d", &Roll);
    printf("1. first name \n");
    printf("2. last name \n");
    printf("3. roll number \n");
    printf("4. GPA \n");
    printf("5. courses \n");
    scanf("%d", &choice);

    for(i = 0; i < student_queue->count; i++)
    {
        if(student->roll == Roll)
        {
            switch(choice)
            {
            case 1:
                printf("Enter the new first name: ");
                scanf("%s", student->Fname);
                printf("[INFO] update successfully");
                break;

            case 2:
                printf("Enter the new last name: ");
                scanf("%s", student->Lname);
                printf("[INFO] update successfully");
                break;

            case 3:
                printf("Enter the new roll number: ");
                scanf("%d", &student->roll);
                printf("[INFO] update successfully");
                break;

            case 4:
                printf("Enter the new GPA: ");
                scanf("%f", &student->GPA);
                printf("[INFO] update successfully");
                break;

            case 5:
                printf("Enter the new courses IDs are: \n");
                for(j = 0; j < Courses_Number; j++)
                {
                    scanf("%d", &student->CourseId[j]);
                }
                break;
            }
        }

        student++;
    }


}

/***************************************************************************************************/

FIFO_status_t FIFO_init(FIFO_Buf_t *fifo_buf , FIFO_Student_t* buf, unsigned int length)
{
	if(buf == NULL)
		return FIFO_null;

	fifo_buf->base = buf;
	fifo_buf->tail = buf;
	fifo_buf->head = buf;
	fifo_buf->length = length;
	fifo_buf->count = 0;

	return FIFO_no_error;
}

/***************************************************************************************************/

FIFO_status_t FIFO_is_full(FIFO_Buf_t *fifo_buf )
{
	//check fifo is valid
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;

	if(fifo_buf->length == fifo_buf->count)
		return FIFO_full;

	return FIFO_empty;
}

/***************************************************************************************************/

static FIFO_Student_t *Search_Student_by_Roll_Number(FIFO_Buf_t *students_queue, int roll)
{
	int i ;
	FIFO_Student_t *student = students_queue->tail;

	/* Loop inside the queue */
	for (i = 0; i < students_queue->count; ++i)
	{
		if (student->roll == roll)
		{
			break;
		}

		if((student + 1) == (students_queue->base + students_queue->length))
		{
			student = students_queue->base;
		}
		else
		{
			student++;
		}
	}

	if(i == students_queue->count)
	{
		student = NULL;
	}

	return student;
}

/***************************************************************************************************/

void Exit()
{
	printf("Thank You");
    exit(1);
}
