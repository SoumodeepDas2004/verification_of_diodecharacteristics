#include <stdio.h>
#include <math.h>

int main() {
    FILE *csv_file,*csv_file_experimental;
    csv_file = fopen("Forwardbias.csv", "w");
    csv_file_experimental=fopen("FOrward_Experimental_data.csv","w");
    if (csv_file == NULL) {
        printf("Error opening the SOftware data CSV file.\n");
        return 1;
    }
    if (csv_file_experimental== NULL) {
        printf("Error opening the Practical data CSV file.\n");
        return 1;
    }
    char compT;
    double I0 ;  /// Replace with  I0 value
    double n ;   /// Replace with  ideality factor
    double Vd, Id, Vd_p,Id_p;
    int lim1;
    printf("\n GIVE your diode material among the following  's' for Silicon or 'g' for Germenium:-\n");
    scanf("%c",&compT);

    if(compT==("s"||"S"))
    { I0=.00001;
      n=2.0;
    }
    else
    {
      I0=.025;
      n=1.4;
    }
    // Create CSV header
    fprintf(csv_file, "Voltage (Vd), Diode Current (Id)\n");
    fprintf(csv_file_experimental, "D.VoltagePractical (Vd), D.CurrentPractical(Id)\n");

    printf("\nGIVE THE NUMBER OF DATA ENTRIES in FORWARD bias condition- \n");
    scanf("%d",&lim1);

    for(int i=1;i<=lim1;i++)
    {
      printf("\n Input practical data of observation no %d   diode voltage and diode current respectively:  ",i);
      scanf("%lf  %lf",&Vd_p,&Id_p);

      Vd=Vd_p;
      Id = I0 * (exp(Vd / (n * 0.0260)) - 1)/10000;

      fprintf(csv_file, " %.2lf ,%.4lf\n",Vd , Id);
      fprintf(csv_file_experimental, " %.2lf ,%.4lf\n",Vd_p , Id_p);
    }

    fclose(csv_file_experimental);
    fclose(csv_file);

    printf("\nCSV files 'Forwardbias.csv'&'FOrward_Experimental_data.csv' has been created.\n");
///REVERSE BIAS
     double Vd_R, Id_R, Vd_pR,Id_pR;
    int lim2;
     FILE *csv_file_R,*csv_file_experimental_R;
    csv_file_R= fopen("ReverseBIas_rev.csv","w");
    csv_file_experimental_R=fopen("Reverse_Experimental_data_rev.csv","w");
    if (csv_file_R== NULL) {
        printf("Error opening the SOftware data rev CSV file.\n");
        return 1;
    }
    if (csv_file_experimental_R== NULL) {
        printf("Error opening the Practical data rev CSV file.\n");
        return 1;
    }
    fprintf(csv_file_R, "Voltage (Vd), Diode Current (Id)\n");
    fprintf(csv_file_experimental_R, "D.VoltagePractical (Vd), D.CurrentPractical(Id)\n");
    printf("\nGIVE THE NUMBER OF DATA ENTRIES in revese bias condition- \n");
    scanf("%d",&lim2);
    for(int i=1;i<=lim2;i++)
    {
        printf("\n Input practical data of observation(REVERSE BIAS) no %d  diode voltage and diode current respectively:  ",i);
      scanf("%lf  %lf",&Vd_pR,&Id_pR);

      Vd_R=Vd_pR;
      Id_R =( I0 * (exp(Vd / (n * 0.0257)) - 1))/100000;

      fprintf(csv_file_experimental_R, " %.2lf ,%.4lf\n",-Vd_pR,-Id_pR);
      fprintf(csv_file_R, " %.2lf ,%.4lf\n",-Vd_R , -Id_R);
    }


   fclose(csv_file_experimental_R);
    fclose(csv_file_R);
    printf("\nCSV files 'ReverseBIas_rev.csv'&'Reverse_Experimental_data_rev.csv' has been created.\n");

    return 0;
}


