
/*
LABPLAY.C
	author aRaafat
	last edit 13/10/2017

odd magic box implementation
based on a certain algorithm
1 put 1 in the first row and the middle column
if num accepts division by square order decrement row and column
other wise increment the row
check the circular conditions on both cases
goto the write position on the screen and write the right number
*/

//icluding different libraries
#include<conio.h>
#include<stdio.h>

void main(void)
{
	int cl,row,N,i,dx,dy,flag; //variables declerations

	clrscr();//clear output screan


	//get the square order from the user

	do
	{
	flag=0;//if user enter right input flag will still 0 otherwise 1
	printf("please enter valid odd square order");
	scanf("%d",&N);

	//check if input invalid change the flag
	if((N%2==0) || (N<3) )
		flag=1;

	}while(flag);//repeat the process if the flag equals 1



	row=0;//the algorithms starts with 1st row
	cl=(N-1)/2;//calculate column number medium col in the square
	dx=80/N-1;//specifying x axis weight for better show
	dy=25/N-1;//specifying y axis weight for better show

	clrscr();//clear screen again before showing the suare

	//put one on its specified position
	gotoxy((cl+1)*dx,(row+1)*dy);
	printf("%d",1);

	//make loop to write the n*n squrare based on magical box algorithm
	for (i=1;i<N*N;i++)//loop n*n of the cube order
	{
		if(i%N!=0)//case doesn't accept division by oreder
		{
			row--; //decrease row
			cl--;  //decrease col

		//check for circular
			if(row<0)
				row=N-1;
			if(cl<0)
				cl=N-1;
		}
		else
		{
			row++;//increase row

			//check circuilar
			if(row>N-1)
			row=0;
		}

		//print the number in the right square
		gotoxy((cl+1)*dx,(row+1)*dy);
		printf("%d",i+1);

	}//for end

	getch();//to see from the screen

}//main end