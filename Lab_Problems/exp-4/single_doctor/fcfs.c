#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100

float patients_array[MAX];

void initial_appointments(int *num_patients)
{
int i,n=0;
puts("Enter the number of patients:");
scanf("%d",&n);

puts("Enter estimated consultation time for each patient: ");
for(i=0;i<n;i++)
scanf("%f",&patients_array[i]);

*num_patients=n;
}

void send_in(int *num_patients)
{
static int send=0;

if(send>*num_patients)
{
puts("No more patients!");
return;
}

printf("Patient number %d has been sent for consultation.\n",send);
sleep(patients_array[send]);
printf("Patient number %d has finished.\n\n",send++);

}

void new_appointment(int *num_patients)
{
puts("Enter the estimated consultation time:");
scanf("%f",&patients_array[++(*num_patients)]);
}

void show_queue(int num_appointments)
{
int i;
for(i=0;i<=num_appointments;i++)
printf("Patient %d:\nConsultation time: %f\n\n",i,patients_array[i]);
}

int main(int argc,char **argv)
{
int num_patients=0,choice=0;

initial_appointments(&num_patients);

for(;num_patients+1;) //until num_patients>=0
{
puts("1. Send in");
puts("2. New appointent");
puts("3. Show queue\n");

scanf("%d",&choice);
puts("");
switch(choice)
{
	case 1:
	send_in(&num_patients);
	break;

	case 2:
	new_appointment(&num_patients);
	break;

	case 3:
	show_queue(num_patients);
	break;
}
}

return 0;
}
