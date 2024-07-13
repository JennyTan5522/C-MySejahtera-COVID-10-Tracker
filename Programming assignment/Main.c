#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//function protocol
int mainFixed();
void display();
void end();
void main() {
	mainFixed();
}

int mainFixed() {
	int c;
	printf("++------------------------------------------------------------------------------------------------------------------++\n");
	printf("||  Every evening the local authority collects details of covid-10 cases from all its districts                     ||\n");
	printf("||  Daily details include the number of new cases,number of deaths and number recovered.                            ||\n");
	printf("||  Based on these details and previous data, your system will be able to produce a summary report showing the total||\n");
	printf("||  number of cases, total deaths, total recovered, total under treatment and the respective percentages.           ||\n");
	printf("++------------------------------------------------------------------------------------------------------------------++\n");


	printf("++------------------------------------++\n");
	printf("||  Select 1 > CONTINUE THE PROCESS  ||\n");
	printf("||  Select 0 > EXIT                  ||\n");
	printf("\tPlease enter your option:");
	scanf("%d", &c);
	while (c != 1 && c != 0) {  //Validation check
		printf("Re-enter the option\n");
		scanf("%d", &c);
	}
	switch (c) {
	case 1:display();//Choose continue then turn into the display menus
		break;
	default:end();//Choose 0 to end the process
	}


}

void display() {
	//constant variables of day 9
	const int NCASE = 9;
	const int TCASE = 100;
	const int TDEATH = 2;
	const int TRECOVER = 10;
	const int TREAT = 88;


	int day, local, imported, death, recover, totalNew, totalCase, totalDeath, totalRecover, underTreatment;
	int   diffNew,   diffNegative,  diffTotalCase, negtvDiffTotalCase, choice;//difference of cases
	int  max = 0, min = 0, maxDay = 0, minDay = 0,  maxDayR = 9, minDayR = 9, maxDayD = 9, minDayD = 9, mostD= 2, leastD = 2, highestR = 10, lowestR = 10;//calculate highest and lowest cases 
	int yTotalNew, yDeath, yRecover, yTreat, yTotalCase;
	int nextDay, highest;//nextday for user to continue ,highest for show highest & lowest report
	double d, r, t; //d,r,t refer to calculation of percentage total deaths,recovered,undertreatment
	double deathRate, newDeathRate, diffDeathRate, negDiffDeathRate, recoverRate, newRecoverRate, diffRecoverRate, negRecoverRate;
	double dayDeath, dayRecover, dayTreat;


	//Day 9 data of covid-19 cases(constant)
	day = 9;
	do {
		if (day == 9) {
			//If day 9 the yesterday variables change to constant
			yTotalCase = TCASE;
			yTotalNew = NCASE;
			yDeath = TDEATH;
			yRecover = TRECOVER;
			yTreat = TREAT;
		}
		else {//Let today case change to yesterday case
			yTotalCase = totalCase;
			yTotalNew = totalNew;
			yDeath = totalDeath;
			yRecover = totalRecover;
			yTreat = dayTreat;

		}

		dayDeath = (double)yDeath / yTotalCase * 100.0;
		dayRecover = (double)yRecover / yTotalCase * 100.0;
		dayTreat = (double)(yTotalCase - yDeath - yRecover) / yTotalCase * 100.0;

		printf("+----------------------Yesterday day's data(DAY%2d) in Malaysia --------------------------------+\n", day);
		printf("|---------|-------------|---------------++-----------------|-----------------|-----------------|\n");
		printf("|         |  New Cases  |  Total Cases  ||   Total Deaths  | Total Recovered | Under Treatment |\n");
		printf("| DAY %2d  |     %3d     |     %3d       ||       %3d       |      %3d        |      %3d        |\n", day, yTotalNew, yTotalCase, yDeath, yRecover, yTreat);
		printf("|---------|-------------|---------------++-----------------|-----------------|-----------------|\n");
		printf("+-------- |-------------|---------------||------%3.2lf%%------|------%3.2lf%%-----|-----%3.2lf%%----- +\n", dayDeath, dayRecover, dayTreat);

		//User input
		printf("DAY %d\n", day + 1);
		printf("=======\n");
		printf("Enter the number of new cases from local  >");
		scanf("%d", &local);
		printf("Enter the number of new cases from imported  >");
		scanf("%d", &imported);

		totalNew = local + imported;//Find the total new cases
		//difference of today and yesterday total new  cases
		diffNew = totalNew - yTotalNew;
		diffNegative = yTotalNew - totalNew;

		//3 possible outcomes

		if (diffNew > 0) {
			printf("Total new cases  >%d", totalNew);
			printf("\t-[Increased by %d from yesterday]-\n", diffNew);
		}

		else if (diffNew < 0) {
			printf("Total new cases  > % d", totalNew);
			printf("-[Decreased by %d from yesterday]-\n", diffNegative);
		}
		else {
			printf("Total new cases  > % d", totalNew);
			printf("-[Today's number of cases is same as yesterday]-\n");
		}


		printf("Enter the number of death  >");
		scanf("%d", &death);
		printf("Enter the number of recoverd/dischaged  >");
		scanf("%d", &recover);


		totalCase = totalNew + yTotalCase;//total cases of today and yesterday
		totalDeath = yDeath + death; // total death of today and yesterday
		totalRecover = yRecover + recover;
		underTreatment = totalCase - totalDeath - totalRecover;

		d = (double)totalDeath / totalCase * 100;
		r = (double)totalRecover / totalCase * 100;
		t = (double)underTreatment / totalCase * 100;

		//choose a report
		printf("-----------------------------------------------\n");
		printf("Please choose a report that you want \n");
		printf("(1)Daily Summary Report \n");
		printf("(2)Daily Comparative Report \n");
		printf("Enter your answer >");
		scanf("%d", &choice);
		//Validation check whether user enter correct choice or not 
		while (choice != 1 && choice != 2) {
			printf("++----Invalid choice----++\n");
			printf("[  PLEASE ENTER AGAIN!   ]\n");
			scanf("%d", &choice);
		}
		day++;//Let the day change according the day
		if (choice == 1) {
			printf("--------------------------------Daily Summary Report-----------------------------------\n", day);
			printf("||--------------||------------------------------||-----------------||-----------------||\n");
			printf("|| New Cases    || Total cases ||  Total deaths || Total Recovered || Under treatment ||\n");
			printf("|| Local:%4d   ||-------------||---------------||-----------------||-----------------||\n", local);
			printf("||Imported:%4d ||     %4d    ||      %4d     ||      %4d       ||      %4d       ||\n", imported, totalCase, totalDeath, totalRecover, underTreatment);
			printf("||--------------||-------------||---------------||-----------------||-----------------||\n");
			printf("||--------------||-------------||    %4.1f%%      ||       %4.1f%%     ||      %4.1f%%      ||\n", d, r, t);
			printf("---------------------------------END OF DAY  %d -----------------------------------------\n", day);
		}
		//Second choice display comparative report
		else {
			printf("||---------------------Daily Comparative Report-------------------------||\n");
			printf("||-------------||----------------||------------------||-----------------||\n");
			printf("||             ||    YESTERDAY   ||       TODAY      ||    DIFFERENCE   ||\n");
			printf("||-------------||----------------||------------------||-----------------||\n");
			printf("||             ||     DAY %3d    ||      DAY %3d     ||                 ||\n", day - 1, day);
			printf("||-------------||----------------||------------------||-----------------||\n");
			//3 possible outcomes
			if (diffNew > 0) {
				printf("||   New cases ||    %4d        ||       %4d       ||      +%4d      ||\n", yTotalNew, totalNew, diffNew);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else if (diffNew < 0) {
				printf("||   New cases ||    %4d        ||       %4d       ||      -%4d      ||\n", yTotalNew, totalNew, diffNegative);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else {
				printf("||  New cases  ||    %4d        ||      %4d        ||      same      ||\n", yTotalNew, totalNew);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}


			//difference of today and yesterday total cases
			diffTotalCase = (yTotalCase + totalNew) - yTotalCase;
			negtvDiffTotalCase = yTotalCase - (yTotalCase + totalNew);
			//3 possible outcomes
			if (diffTotalCase > 0) {
				printf("|| Total cases ||     %4d       ||       %4d       ||      +%4d      ||\n", yTotalCase, totalCase, diffTotalCase);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else if (diffTotalCase < 0) {
				printf("|| Total cases ||     %4d       ||       %4d       ||      -%4d      ||\n", yTotalCase, totalCase, negtvDiffTotalCase);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else {
				printf("|| Total cases ||     %4d       ||       %4d       ||      same      ||\n", yTotalCase, totalCase);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}

			//calculations of death percentage
			deathRate = (double)yDeath / yTotalCase * 100.0;
			newDeathRate = (double)totalDeath / totalCase * 100.0;
			diffDeathRate = newDeathRate - deathRate;
			negDiffDeathRate = deathRate - newDeathRate;
			//3 possible outcomes
			if (diffDeathRate > 0) {
				printf("||  Death Rate ||      %4.1f%%     ||       %4.1f%%      ||      +%4.1f%%     ||\n", deathRate, newDeathRate, diffDeathRate);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else if (diffDeathRate < 0) {
				printf("||  Death Rate ||      %4.1f%%     ||       %4.1f%%      ||      -%4.1f%%     ||\n", deathRate, newDeathRate, negDiffDeathRate);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else {
				printf("||  Death Rate ||      %4.1lf%%     ||        %4.1lf%%     ||       same      ||\n", deathRate, newDeathRate);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			//calculations of recover percentage
			recoverRate = (double)yRecover / yTotalCase * 100.0;
			newRecoverRate = (double)totalRecover / totalCase * 100.0;
			diffRecoverRate = newRecoverRate - recoverRate;
			negRecoverRate = recoverRate - newRecoverRate;

			//3 possible outcomes
			if (diffRecoverRate > 0) {
				printf("||Recovery Rate||      %3.1lf%%     ||        %3.1lf%%     ||      +%3.1lf%%     ||\n", recoverRate, newRecoverRate, diffRecoverRate);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else if (diffRecoverRate < 0) {
				printf("||Recovery Rate||      %3.1lf%%     ||        %3.1lf%%      ||      -%3.1lf%%      ||\n", recoverRate, newRecoverRate, negRecoverRate);
				printf("||-------------||----------------||------------------||-----------------||\n");
			}
			else {
				printf("||Recovery Rate||      %3.1lf%%     ||       %3.1lf%%     ||      same       ||\n", recoverRate, newRecoverRate);
				printf("--------------------------------------------------------------------------\n");
			}
			printf("||---------------------------END OF DAY %d------------------------------||\n", day);

		}

		//To find the highest cases
		if (yTotalNew > totalNew) {
			max = yTotalNew;//Store the highest case to max
			maxDay = day;//Store the highest case of day
		}
		if (yTotalNew < totalNew) {
			min = yTotalNew;
			minDay = day;
		}

		/*calculate highest recoveries rate and lowest death case*/
		if (death > mostD) {
			mostD = death;
			maxDayD = day;
		}
		if (death < leastD) {
			leastD = death;
			minDayD = day;

		}
		/*calculate highest recoveries rate and lowest recoveries case*/
		if (recover > highestR) {
			highestR = recover;
			maxDayR = day;
		}

		if (recover < lowestR) {
			lowestR = recover;
			minDayR = day;
		}


		printf("Please enter 1 to continue or 2 to stop the process >> \n");
		printf("(1)Continue\n");
		printf("(2)Stop\n");
		scanf("%d", &nextDay);

		//Validation check whether user enter correct choice or not
		while (nextDay != 1 && nextDay != 2) {
			printf("++----Invalid choice----++\n");
			printf("|| PLEASE ENTER AGAIN!  ||\n");
			scanf("%d", &nextDay);
		}
		if (nextDay == 2) {
			printf("|| Total days recorded     >> %2d (DAY 10 to DAY %2d) ||\n", day - 9, day);
			printf("|| Highest number of cases >> %2d, on DAY %2d         ||\n", max, maxDay - 1);
			printf("|| Lowest number of cases  >> %2d, on DAY %2d         ||\n", min, minDay - 1);
			printf("-[ Do you want to show the  HIGHEST & LOWEST report? ]-\n");
			printf("(1) - YES  \n");
			printf("(2) - NO   \n");
			scanf("%d", &highest);
			if (highest == 1) {
				printf("||--------- HIGHEST & LOWEST Report------------||\n");
				printf("|| HIGHEST CASES         > %3d   -[ DAY %2d ]-  ||\n", max, maxDay - 1);
				printf("|| LOWEST  CASES         > %3d   -[ DAY %2d ]-  ||\n", min, minDay - 1);
				printf("|| HIGHEST RECOVER CASES > %3d   -[ DAY %2d ]-  ||\n", highestR, maxDayR);
				printf("|| LOWEST  RECOVER CASES > %3d   -[ DAY %2d ]-  ||\n", lowestR, minDayR);
				printf("|| HIGHEST DEATH  CASES  > %3d   -[ DAY %2d ]-  ||\n", mostD, maxDayD );
				printf("|| LOWEST  DEATH  CASES  > %3d   -[ DAY %2d ]-  ||\n", leastD, minDayD );
			}
			printf("------------------THANK YOU!----------------------------\n");
		}

	} while (nextDay == 1);
}
void end() {
	printf("----------------------THANK YOU!-------------------------\n");
}