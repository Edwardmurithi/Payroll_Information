#include <stdio.h>
#include <stdlib.h>

//structure declaration to store Employee information
struct Employee {
  char name[50];
  int hoursWorked;
  float hourlyRate;
  float totalPay;
};
//function to validate HoursWorked
void validateHoursWorked(int hoursWorked) {
  if (hoursWorked < 0) {
    printf("Hours worked must be non-negative.\n");
    exit(1);
  }
}

//function to validate HourlyRate
void validateHourlyRate(float hourlyRate) {
  if (hourlyRate < 0) {
    printf("Hourly rate must be non-negative.\n");
    exit(1);
  }
}

//Fuction to calculate the Total pay
void calculateTotalPay(struct Employee *employee) {
  //formula
  employee->totalPay = employee->hoursWorked * employee->hourlyRate;
}

//Main function begins program execution
int main() {
  int numberOfEmployees;
  struct Employee *employees;

  printf("\n");
  printf("\t------PAYROLL INFORMATION PROGRAM-------\n");
  printf("\n");
  printf("\t\t\t--WELCOME---");
  printf("\n\n\n");

  printf("Enter the number of employees: ");//Prompt user
  scanf("%d", &numberOfEmployees);//Read input

  employees = (struct Employee *)malloc(sizeof(struct Employee) * numberOfEmployees);

  for(int i = 0; i < numberOfEmployees; i++) {
    printf("Enter the name of employee %d: ", i + 1);
    scanf("%s", employees[i].name);

    printf("Enter the hours worked by employee %d: ", i + 1);
    scanf("%d", &employees[i].hoursWorked);
    validateHoursWorked(employees[i].hoursWorked);

    printf("Enter the hourly rate of employee %d: ", i + 1);
    scanf("%f", &employees[i].hourlyRate);
    validateHourlyRate(employees[i].hourlyRate);

    calculateTotalPay(&employees[i]);
  }

  printf("\n");
  printf("The payroll information for the employees is: \n");
  for (int i = 0; i < numberOfEmployees; i++) {
    printf("Name: %s\n", employees[i].name);
    printf("Hours Worked: %d\n", employees[i].hoursWorked);
    printf("Hourly Rate: $%.2f\n", employees[i].hourlyRate);
    printf("Total Pay: $%.2f\n", employees[i].totalPay);
    printf("\n\n");
  }

  free(employees);

  return 0;
}
