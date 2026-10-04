/* ============================================================
 * suppliers.c - Supplier Management Module
 * PAP521S - Programming in Practice - Project A
 * ============================================================ */
 
#include <stdio.h>
#include "reports.h"
 
static double employeeSalary(const Employee *e)
{
    /* Align field names with the team's Employee structure. */
    return e->basicSalary + e->housingAllowance
         + e->transportAllowance + e->otherAllowance;
}
 
void employeeReport(const Employee employees[], int count)
{
    if (count <= 0) {
        printf("\nNo employee records available.\n");
        return;
    }
 
    double total = 0.0;
    double highest = employeeSalary(&employees[0]);
    double lowest  = highest;
 
    for (int i = 0; i < count; ++i) {
        double salary = employeeSalary(&employees[i]);
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest)  lowest = salary;
    }
 
    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Total Employees : %d\n", count);
    printf("Average Salary  : N$%.2f\n", total / count);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
}
 
void budgetReport(const Budget budgets[], int count)
{
    if (count <= 0) {
        printf("\nNo budget records available.\n");
        return;
    }
 
    double allocated = 0.0;
    double expenditure = 0.0;
 
    for (int i = 0; i < count; ++i) {
        allocated += budgets[i].allocatedBudget;
        expenditure += budgets[i].expenditure;
    }
 
    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Allocated Budget : N$%.2f\n", allocated);
    printf("Total Expenditure      : N$%.2f\n", expenditure);
    printf("Remaining Budget       : N$%.2f\n", allocated - expenditure);
    printf("Departments Over Budget:\n");
 
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            printf("- %s (Over by N$%.2f)\n",
                   budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocatedBudget);
            found = 1;
        }
    }
    if (!found) printf("None\n");
}
 
void supplierReport(const Supplier suppliers[], int count)
{
    if (count <= 0) {
        printf("\nNo supplier records available.\n");
        return;
    }
 
    printf("\n================ SUPPLIER REPORT ================\n");
    for (int i = 0; i < count; ++i) {
        printf("ID: %s | Name: %s | Email: %s | Tel: %s | Town: %s\n",
               suppliers[i].supplierID,
               suppliers[i].supplierName,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].town);
    }
}
 
void assetReport(const Asset assets[], int count)
{
    if (count <= 0) {
        printf("\nNo asset records available.\n");
        return;
    }
 
    printf("\n================ ASSET REPORT ================\n");
    for (int i = 0; i < count; ++i) {
        printf("ID: %s | Name: %s | Type: %s | Value: N$%.2f | Dept: %s | Condition: %s\n",
               assets[i].assetID,
               assets[i].assetName,
               assets[i].assetType,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }
}
 
void displayReports(const Employee employees[], int employeeCount,
                    const Budget budgets[], int budgetCount,
                    const Supplier suppliers[], int supplierCount,
                    const Asset assets[], int assetCount)
{
    int choice;
    do {
        printf("\n========== REPORTS MENU ==========\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: employeeReport(employees, employeeCount); break;
            case 2: budgetReport(budgets, budgetCount); break;
            case 3: supplierReport(suppliers, supplierCount); break;
            case 4: assetReport(assets, assetCount); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid report option. Please try again.\n");
        }
    } while (choice != 5);
}

