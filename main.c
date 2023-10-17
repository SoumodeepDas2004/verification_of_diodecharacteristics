#include <stdio.h>
#include <math.h>

int main() {
    FILE *csv_file;
    csv_file = fopen("diode_current_program.csv", "w");

    if (csv_file == NULL) {
        printf("Error opening the SOftware data CSV file.\n");
        return 1;
    }

    double I0 ;  /// Replace with  I0 value
    double n ;   /// Replace with  ideality factor
    double Vd=0, Id;
    int lim1=2.5;

     I0=.00000001;
      n=1;///CHECK


    fprintf(csv_file, "Voltage (Vd), Diode Current (Id)\n");


    for(;Vd<=lim1;Vd+=.05)
    {
      Id = I0 * (exp(Vd / (n * 0.0257)) - 1);

      fprintf(csv_file, " %.2lf ,%.4lf\n",Vd , Id);

    }

    fclose(csv_file);
    printf("\nCSV files 'diode_current_program.csv' has been created.\n");

  return 0;
}
