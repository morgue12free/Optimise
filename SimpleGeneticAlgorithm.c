#include <stdio.h>
#include <stdlib.h>

#define NUMBER_ORGANISMS 100
#define NUMBER_GENES 20
int CURRENT_ORGANISM;
int CURRENT_GENE;
typedef struct{
		int gene[NUMBER_GENES];
		int fitness;
	}individual;        
int fit_total;
int fit_total2;

int main(){
	
	int P = NUMBER_ORGANISMS;
        int N = NUMBER_GENES;

	individual population[P];
	int parent1, parent2;
	individual offSpring[P];

        for (CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){
		for (CURRENT_GENE = 0; CURRENT_GENE<N; CURRENT_GENE++){
			population[CURRENT_ORGANISM].gene[CURRENT_GENE] = rand() % 2;
		}
		population[CURRENT_ORGANISM].fitness = 0;
	}

	for (CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){
		for (CURRENT_GENE = 0; CURRENT_GENE<N; CURRENT_GENE++){
			if (population[CURRENT_ORGANISM].gene[CURRENT_GENE]) population[CURRENT_ORGANISM].fitness++;
         
	}
     }
        
        for(CURRENT_ORGANISM = 0;CURRENT_ORGANISM<P;CURRENT_ORGANISM++ ){
   printf("Fitness:%d\n",population[CURRENT_ORGANISM].fitness); //print fitness of each individual
   fit_total+=population[CURRENT_ORGANISM].fitness; 
  }
        printf("Total Fitness:%d\n",fit_total);  //print total fitness of new group
       
        for(CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){
		parent1 = rand()%P;
		parent2 = rand()%P;

		if (population[parent1].fitness > population[parent2].fitness){
			offSpring[CURRENT_ORGANISM] = population[parent1];
		}
		else{
			offSpring[CURRENT_ORGANISM] = population[parent2];
		}
        //offSpring[CURRENT_ORGANISM].fitness++;
        printf("New Population Fitness is:%d\n",offSpring[CURRENT_ORGANISM].fitness);
        fit_total2+=offSpring[CURRENT_ORGANISM].fitness;
	};
   printf("Total Fitness:%d\n",fit_total2);  //Print total fitness of new group

};
