/*****Project: Optimisation in AI***/
/*****Using Various EA Techniques optimise a set of equations for the desire output***/
/*****Code Created By: Etinosa Murphy Obanor***/
/*****Date:30th Sept 2015*****/
/**************************************/

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_ORGANISMS 100
#define NUMBER_GENES 10


//Global definitions of variables and functions
int CURRENT_ORGANISM;
int CURRENT_GENE;
	typedef struct{
			int gene[NUMBER_GENES];
			int fitness;
		   }    individual;        
int fit_total;
int fit_total2;
int final_fitness;
int compFunc(); //Comparison for sort function
int funcEval(); //
int func2Eval();

int main(){
	
	//Assign organisms and genes to more concise variable names
	int P = NUMBER_ORGANISMS;
    int N = NUMBER_GENES;

	individual population[P];
	int parent1, parent2;
	individual offSpring[P];

   
   	    /*******Initialisation of the Population********/
        for (CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){ //Loop through the population
		  for (CURRENT_GENE = 0; CURRENT_GENE<N; CURRENT_GENE++){ 
			population[CURRENT_ORGANISM].gene[CURRENT_GENE] = rand() % N; //Assign random numbers / Genes to gene
		} 
		population[CURRENT_ORGANISM].fitness = 0;  //initialise the population fitness
	}

	for (CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){
		for (CURRENT_GENE = 0; CURRENT_GENE<N; CURRENT_GENE++){
			if (population[CURRENT_ORGANISM].gene[CURRENT_GENE]) population[CURRENT_ORGANISM].fitness++;
         
	}
     }
            	
         /*******Tournament********/
        for(CURRENT_ORGANISM = 0;CURRENT_ORGANISM<P;CURRENT_ORGANISM++ ){

   printf("Fitness:%d\n",population[CURRENT_ORGANISM].fitness); //print fitness of each individual
   fit_total+=population[CURRENT_ORGANISM].fitness; 
  }
       // printf("Total Fitness:%d\n",fit_total);  //print total fitness of new group
       
       //Run through entire population
        for(CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){
		parent1 = rand()%P; //generate random parents within the population  
		parent2 = rand()%P; 

        //Pick the best parent of the 2 and assign to a new offspring
		if (population[parent1].fitness > population[parent2].fitness){ 
			offSpring[CURRENT_ORGANISM] = population[parent1]; 
		}
		else{
			offSpring[CURRENT_ORGANISM] = population[parent2];
		}
        offSpring[CURRENT_ORGANISM].fitness++;
        printf("New Population Fitness is:%d\n",offSpring[CURRENT_ORGANISM].fitness);
	};
 
                   /*******CrossOver Operation********/
    for(CURRENT_ORGANISM = 0; CURRENT_ORGANISM<P; CURRENT_ORGANISM++){

    	
	    	//Shift the 1 in the 000001 config to the left by 3, then - 1, to create a 000111 config
	    	int mask = 1;
	    	mask = mask<<3; 
	    	mask = mask - 1;
	       

	    	//Mask the the last 3 bits of the genes of the 1st 2 offsprings and assign to 2 new variables
		    int gene_end = population[CURRENT_ORGANISM].gene[N] &  mask; 
		    int gene2_end = population[CURRENT_ORGANISM+1].gene[N] & mask;

	        //Mask the first 3 digits of the genes, like above but reverse (no new variables)
	        int mask2 = 56;
	   
	       population[CURRENT_ORGANISM].gene[N] = population[CURRENT_ORGANISM].gene[N] & mask2;
	       population[CURRENT_ORGANISM+1].gene[N] = population[CURRENT_ORGANISM+1].gene[N] & mask2;

	        //Crossover the last 4 bit gene of the first offspring with that of the second and vice versa
	       offSpring[CURRENT_ORGANISM].gene[N] = population[CURRENT_ORGANISM].gene[N] | gene2_end;
	       offSpring[CURRENT_ORGANISM+1].gene[N] = population[CURRENT_ORGANISM+1].gene[N] | gene_end;
	      // printf("Test:%d\n", offSpring[CURRENT_ORGANISM].fitness);

	         for(int oSprings = 0; oSprings < CURRENT_ORGANISM; oSprings++){
	       	   for(int oSGenes = 0; oSGenes < N; oSGenes++){
			       offSpring[CURRENT_ORGANISM].fitness++;
			     }
			   }
			      
	       
	             /***********Mutation**********/
	       //define 6 integer masks to perform the bit flip
	       int array_mask[] = {21,22,16,28,4,52};

	        if(rand()%N < 5){
	        	int t = rand()%N;  //t gets assigned the value of rand/N, if the result is < 5
	       offSpring[CURRENT_ORGANISM].gene[N] = offSpring[CURRENT_ORGANISM].gene[ N & array_mask[t]]; //A single bit gets fliped  at random
	       }else{
	       	offSpring[CURRENT_ORGANISM].gene[N] = offSpring[CURRENT_ORGANISM].gene[N]; 
	       }

	       for(int oSprings = 0; oSprings < CURRENT_ORGANISM; oSprings++){
	       	   for(int oSGenes = 0; oSGenes < N; oSGenes++){
			       offSpring[CURRENT_ORGANISM].fitness++;
			        
			     }
			     
			   }
            
            int x = offSpring[CURRENT_ORGANISM].fitness;
            int y = offSpring[CURRENT_ORGANISM+1].fitness;

             if ((y<=15)&&(y>=-15)){
			 	printf("Function Result2:%d\n",func2Eval(x,y));
               }else{
               	
               }
			 
			 if((x<=255 )&&(x>=0)){
			 	
			 	printf("Function Result:%d\n",funcEval(x));
			 }else{

			 }



       

     }

};

//Sort Comparison Function
int compFunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

//Function F(x) = X^2 
int funcEval(x){
return x^2;	
}

//Function F(x) = 0.26.(x^2 + y^2) - 0.48.(x x y)
int func2Eval(x,y){
return 0.26*(x^2 + y^2) - (0.48)*(x * y);
}
