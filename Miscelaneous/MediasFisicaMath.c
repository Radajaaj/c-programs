#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int grades[2][5];
    int s;
    int j;
    float average;


    grades[0][0] = 80;
	grades[0][1] = 70;
	grades[0][2] = 65;
	grades[0][3] = 89;
	grades[0][4] = 90;

	grades[1][0] = 85;
	grades[1][1] = 80;
	grades[1][2] = 80;
	grades[1][3] = 82;
	grades[1][4] = 87;

	for(s = 0; s < 5; s++){
        average = 0;
        average = (grades[0][s] + grades[1][s]);
        average = (average / 2);
        printf("Student %i's average grade is %f \n", s, average);
	}

    printf("\n");

		for(s = 0; s < 2; s++){

        average = 0;

            for(j = 0; j < 5; j++){
                average = average + grades[s][j];
            }

        average = (average / 5);
        printf("Subject %i's average grade is %f \n", s, average);
	}


return 0;
}
